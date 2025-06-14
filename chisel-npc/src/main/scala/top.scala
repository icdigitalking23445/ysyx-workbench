// src/main/scala/npc/Top.scala
package npc

import chisel3._
import chisel3.util._

class top extends Module {
  val io = IO(new Bundle{})
  
  // ——— 1. PC 寄存器 ———
  val pc      = RegInit("h80000000".U(32.W))
  val pcPlus4 = pc + 4.U
  val valid = RegInit(false.B) 
  valid := true.B 
  // ——— 2. IFU ———
  val ifu = Module(new IFU)
  ifu.io.pc := pc      // 把 PC 给 IFU
  val inst = ifu.io.inst
  ifu.io.valid := valid // IFU 的 valid 信号
  // ——— 3. Decode & Execute ———
  val idu         = Module(new IDU())
  val regFile     = Module(new RegFile())
  val exu         = Module(new EXU())
  val dpiHandlers = Module(new DPIHandlers())

  idu.io.instruction := inst
  regFile.io.rs1     := idu.io.rs1
  regFile.io.rs2     := idu.io.rs2

  exu.io.funct3   := idu.io.funct3
  exu.io.funct7   := idu.io.funct7
  exu.io.TYpe     := idu.io.TYpe
  exu.io.reg_rs1  := regFile.io.regData1
  exu.io.reg_rs2  := regFile.io.regData2
  exu.io.imm      := idu.io.imm.asSInt
  exu.io.pc       := pc
  exu.io.isAuipc  := idu.io.isAuipc
  dpiHandlers.io.IsIllegal   := idu.io.IsIllegal
  dpiHandlers.io.IsInterrupt := idu.io.IsInterrupt

  // ——— 4. Data Memory (Load/Store) ———
  val pmemD = Module(new Pmem)
 pmemD.io.clock := clock // 时钟信号
  val isLoad  = idu.io.TYpe === "b0001".U
  val isStore = idu.io.TYpe === "b0010".U
  pmemD.io.wdata := regFile.io.regData2
  pmemD.io.valid := isLoad || isStore
  pmemD.io.wen   := isStore
  pmemD.io.wmask := MuxLookup(idu.io.funct3, 0.U(4.W), Seq(
    "b000".U -> "b0001".U(4.W), // SB
    "b001".U -> "b0011".U(4.W), // SH
    "b010".U -> "b1111".U(4.W)  // SW
  ))

pmemD.io.raddr := exu.io.result_out
pmemD.io.waddr := exu.io.result_out
 // —— 4.5 Load Data Extract ——  
 // 先拿到对齐的 32 位整字
 val memWord    = pmemD.io.rdata
 // 低两位偏移决定我们要哪一路字节或半字
val byteOffset = pmemD.io.raddr(1,0)
val byteOff    = (memWord >> (byteOffset * 8.U))
val halfOff    = (memWord >> (byteOffset * 8.U))(15,0) 
val lbValue    = Cat(Fill(24, byteOff(7)),     byteOff(7,0))
val lbuValue   = Cat(0.U(24.W),                byteOff(7,0))
val lhValue    = Cat(Fill(16, halfOff(15)),    halfOff)
val lhuValue   = Cat(0.U(16.W),                halfOff)
val lwValue    = memWord   

val loadData = MuxLookup(idu.io.funct3, 0.U, Seq(
  "b000".U -> lbValue,
  "b100".U -> lbuValue,
  "b001".U -> lhValue,
  "b101".U -> lhuValue,
  "b010".U -> lwValue
))
  // ——— 5. Write-back ———
  val isBranch = idu.io.TYpe === "b0011".U
  val isJal    = idu.io.TYpe === "b0110".U
  val isJalr   = idu.io.TYpe === "b0111".U

  val wen = Wire(Bool())
  wen := !isBranch && !isStore && !idu.io.IsIllegal && !idu.io.IsInterrupt
val writeData = Wire(UInt(32.W))
writeData := MuxCase(exu.io.result_out, Seq(
    isLoad  -> loadData,     
    isJal   -> pcPlus4,
    isJalr  -> pcPlus4
  ))

  regFile.io.writeEnable := wen
  regFile.io.writeData   := writeData
  regFile.io.rd          := idu.io.rd

  // ——— 6. Next PC ———
  val branchTarget = Mux(exu.io.branch_taken, exu.io.branch_target, pcPlus4)
  val nextPC = MuxLookup(idu.io.TYpe, pcPlus4, Seq(
    "b0011".U -> branchTarget,        // Branch
    "b0110".U -> exu.io.jump_target,  // JAL
    "b0111".U -> exu.io.jump_target   // JALR
  ))
  pc := nextPC
}
