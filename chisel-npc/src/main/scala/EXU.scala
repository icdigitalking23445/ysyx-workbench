package npc

import chisel3._
import chisel3.util._

/** 32 adder */
class Adder32 extends Module {
  val io = IO(new Bundle {
    val a   = Input(UInt(32.W))
    val b   = Input(UInt(32.W))
    val sum = Output(UInt(32.W))
  })
  io.sum := io.a + io.b
}

/** 32 sub*/
class Sub32 extends Module {
  val io = IO(new Bundle {
    val a    = Input(UInt(32.W))
    val b    = Input(UInt(32.W))
    val diff = Output(UInt(32.W))
  })
  io.diff := io.a - io.b
}

/** 32 shifter for  SLL/SRL/SRA */
class Shifter extends Module {
  val io = IO(new Bundle {
    val in     = Input(UInt(32.W))
    val shamt  = Input(UInt(5.W))    // shift amount, 0-31
    val funct3 = Input(UInt(3.W))    // 001->SLL, 101->SRL/SRA
    val funct7 = Input(UInt(7.W))    // 用于区分 SRL/SRA
    val out    = Output(UInt(32.W))
  })
  // left
  val sll = io.in << io.shamt
  // right
  val srl = io.in >> io.shamt
  // arithmetic right shift
  val sra = (io.in.asSInt >> io.shamt).asUInt

  io.out := MuxLookup(io.funct3, 0.U, Seq(
    "b001".U -> sll,                                // SLLI
    "b101".U -> Mux(io.funct7(5), sra, srl)         // SRAI (funct7(5)=1) / SRLI (funct7(5)=0)
  ))
}

/**logic unit for XOR/OR/AND */
class LogicUnit extends Module {
  val io = IO(new Bundle {
    val in1    = Input(UInt(32.W))
    val in2    = Input(UInt(32.W))
    val funct3 = Input(UInt(3.W))  // 100->XOR, 110->OR, 111->AND
    val out    = Output(UInt(32.W))
  })
  io.out := MuxLookup(io.funct3, 0.U, Seq(
    "b100".U -> (io.in1 ^ io.in2),  // XOR
    "b110".U -> (io.in1 | io.in2),  // OR
    "b111".U -> (io.in1 & io.in2)   // AND
  ))
}

/** cmp，for Branch 判断（EQ/BNE/LT/BGE/BLTU/BGEU） */
class Comparator extends Module {
  val io = IO(new Bundle {
    val in1    = Input(UInt(32.W))
    val in2    = Input(UInt(32.W))
    val funct3 = Input(UInt(3.W))  // 000=BEQ,001=BNE,100=BLT,101=BGE,110=BLTU,111=BGEU
    val cmp    = Output(Bool())
  })
  val in1s = io.in1.asSInt
  val in2s = io.in2.asSInt
  io.cmp := MuxLookup(io.funct3, false.B, Seq(
    "b000".U -> (io.in1 === io.in2),      // BEQ
    "b001".U -> (io.in1 =/= io.in2),      // BNE
    "b100".U -> (in1s < in2s),            // BLT
    "b101".U -> (in1s >= in2s),           // BGE
    "b110".U -> (io.in1 < io.in2),        // BLTU
    "b111".U -> (io.in1 >= io.in2)        // BGEU
  ))
}

/** U-type :LUI/AUIPC */
class UTypeUnit extends Module {
  val io = IO(new Bundle {
    val imm     = Input(UInt(32.W)) // imm 已经有高 20 位
    val pc      = Input(UInt(32.W))
    val isAuipc = Input(Bool())
    val out     = Output(UInt(32.W))
  })
  // LUI: imm<<12
  val luiVal   = io.imm << 12
  // AUIPC: pc + (imm<<12)
  val auipcVal = io.pc + (io.imm << 12)
  io.out := Mux(io.isAuipc, auipcVal, luiVal)
}

/** 分支单元：taken(布尔) 和 branch_target(pc+imm) */
class BranchUnit extends Module {
  val io = IO(new Bundle {
    val in1           = Input(UInt(32.W))
    val in2           = Input(UInt(32.W))
    val funct3        = Input(UInt(3.W))
    val pc            = Input(UInt(32.W))
    val imm           = Input(UInt(32.W))
    val taken         = Output(Bool())
    val branch_target = Output(UInt(32.W))
  })
  // 1. 比较
  val cmp = Module(new Comparator)
  cmp.io.in1    := io.in1
  cmp.io.in2    := io.in2
  cmp.io.funct3 := io.funct3

  io.taken := cmp.io.cmp

  // 2. 目标地址 = pc + imm
  val ad = Module(new Adder32)
  ad.io.a := io.pc
  ad.io.b := io.imm
  io.branch_target := ad.io.sum
}

/** 跳转单元：JAL/JALR */
class JumpUnit extends Module {
  val io = IO(new Bundle {
    val pc       = Input(UInt(32.W))
    val rs1      = Input(UInt(32.W))
    val imm      = Input(UInt(32.W))
    val isJal    = Input(Bool())
    val isJalr   = Input(Bool())
    val jump_pc  = Output(UInt(32.W))
  })
  // 1. JAL: pc + imm
  val adJal = Module(new Adder32)
  adJal.io.a := io.pc
  adJal.io.b := io.imm

  // 2. JALR: rs1 + imm
  val adJalr = Module(new Adder32)
  adJalr.io.a := io.rs1
  adJalr.io.b := io.imm
  val jalrRaw = adJalr.io.sum
  val jalrAligned = jalrRaw & (~1.U(32.W))  // 清最低位

  io.jump_pc := Mux(io.isJal, adJal.io.sum, jalrAligned)
}

/** ALU 模块，负责 R-type、I-arith、Load/Store 地址和 U-type */
class ALU extends Module {
  val io = IO(new Bundle {
    val funct3   = Input(UInt(3.W))
    val funct7   = Input(UInt(7.W))
    val TYpe     = Input(UInt(4.W))   
    val reg_rs1  = Input(UInt(32.W))
    val reg_rs2  = Input(UInt(32.W))
    val imm      = Input(UInt(32.W))
    val pc       = Input(UInt(32.W))
    val result   = Output(UInt(32.W))
  })

  // —— R-type 运算（ADD/SUB/SHL/SHR/SLT/SLTU/XOR/OR/AND）
  val addR   = Module(new Adder32)
  addR.io.a  := io.reg_rs1
  addR.io.b  := io.reg_rs2

  val subR   = Module(new Sub32)
  subR.io.a  := io.reg_rs1
  subR.io.b  := io.reg_rs2

  val shftr  = Module(new Shifter)
  shftr.io.in     := io.reg_rs1
  shftr.io.shamt  := io.reg_rs2(4, 0)
  shftr.io.funct3 := io.funct3
  shftr.io.funct7 := io.funct7

  val logicU = Module(new LogicUnit)
  logicU.io.in1    := io.reg_rs1
  logicU.io.in2    := io.reg_rs2
  logicU.io.funct3 := io.funct3

  val rtypeRes = Wire(UInt(32.W))
  rtypeRes := MuxLookup(io.funct3, 0.U, Seq(
    "b000".U -> Mux(io.funct7(5), subR.io.diff, addR.io.sum),    // SUB/ADD
    "b001".U -> shftr.io.out,                                    // SLL
    "b010".U -> (io.reg_rs1.asSInt < io.reg_rs2.asSInt).asUInt, // SLT
    "b011".U -> (io.reg_rs1 < io.reg_rs2).asUInt,               // SLTU
    "b100".U -> logicU.io.out,                                   // XOR
    "b101".U -> Mux(io.funct7(5),                               // SRL/SRA
      (io.reg_rs1.asSInt >> io.reg_rs2(4, 0)).asUInt,            // SRA
      (io.reg_rs1 >> io.reg_rs2(4, 0))                           // SRL
    ),
    "b110".U -> logicU.io.out,                                   // OR
    "b111".U -> logicU.io.out                                    // AND
  ))

  // —— I-arith (ADDI/SLTI/SLTIU/XORI/ORI/ANDI)：reg_rs1 + imm
  val addI   = Module(new Adder32)
  addI.io.a  := io.reg_rs1
  addI.io.b  := io.imm

  val itypeRes = Wire(UInt(32.W))
  itypeRes := MuxLookup(io.funct3, 0.U, Seq(
    "b000".U -> addI.io.sum,                          // ADDI
    "b010".U -> (io.reg_rs1.asSInt < io.imm.asSInt).asUInt, // SLTI
    "b011".U -> (io.reg_rs1 < io.imm).asUInt,          // SLTIU
    "b100".U -> (io.reg_rs1 ^ io.imm),                 // XORI
    "b110".U -> (io.reg_rs1 | io.imm),                 // ORI
    "b111".U -> (io.reg_rs1 & io.imm)                  // ANDI
    // SLLI/SRLI/SRAI 在外层 Shifter 里处理
  ))

  // —— Load/Store 地址计算：reg_rs1 + imm
  val addrAdd = Module(new Adder32)
  addrAdd.io.a := io.reg_rs1
  addrAdd.io.b := io.imm

  // —— U-type (LUI/AUIPC)
  val uunit = Module(new UTypeUnit)
  uunit.io.imm     := io.imm.asUInt
  uunit.io.pc      := io.pc
  // isAuipc 由外层决定，ALU 里只用 uunit.out
  uunit.io.isAuipc := (io.TYpe === "b0101".U)  // U-type 的 AUIPC
  // 最终输出 result 先给一个默认
  val defaultRes = Wire(UInt(32.W))
  defaultRes := 0.U

  // 根据 TYpe 选择不同子模块的输出
  // TYpe: 000=R-type, 001=I-load, 010=S-store, 011=B-branch, 
  //       100=I-arith/JALR, 101=U-type, 110=JAL, 111=JALR
  io.result := MuxLookup(io.TYpe, 0.U, Seq(
    "b0000".U -> rtypeRes,        // R-type 运算结果
    "b0001".U -> addrAdd.io.sum,  // Load 地址
    "b0010".U -> addrAdd.io.sum,  // Store 地址
    "b0011".U -> 0.U,             // Branch 条件放在 BranchUnit
    "b0100".U -> itypeRes,        // I-arith（ADDI…），JALR 交给 JumpUnit
    "b0101".U -> uunit.io.out,    // U-type
    "b0110".U -> 0.U,             // JAL 交给 JumpUnit
    "b0111".U -> 0.U              // JALR 交给 JumpUnit
  ))
}


class EXU extends Module {
  val io = IO(new Bundle {
    val funct3        = Input(UInt(3.W))
    val funct7        = Input(UInt(7.W))
    val imm           = Input(SInt(32.W))
    val TYpe          = Input(UInt(4.W))      // 4-bit
    val reg_rs1       = Input(UInt(32.W))
    val reg_rs2       = Input(UInt(32.W))
    val pc            = Input(UInt(32.W))

    // 输出：
    val result_out    = Output(UInt(32.W))  // R/I-arith/Load/Store/U-type 的结果
    val branch_taken  = Output(Bool())      // Branch 条件
    val branch_target = Output(UInt(32.W))  // Branch 目标地址
    val jump_target   = Output(UInt(32.W))  // JAL/JALR 目标地址
  })

  // —— 1. ALU 实例化，做 R/I-arith/Load/Store/U
  val alu = Module(new ALU)
  alu.io.funct3  := io.funct3
  alu.io.funct7  := io.funct7
  alu.io.TYpe    := io.TYpe
  alu.io.reg_rs1 := io.reg_rs1
  alu.io.reg_rs2 := io.reg_rs2
  alu.io.imm     := io.imm.asUInt
  alu.io.pc      := io.pc

  // —— 2. BranchUnit 实例化
  val branchUnit = Module(new BranchUnit)
  branchUnit.io.in1    := io.reg_rs1
  branchUnit.io.in2    := io.reg_rs2
  branchUnit.io.funct3 := io.funct3
  branchUnit.io.pc     := io.pc
  branchUnit.io.imm    := io.imm.asUInt

  // —— 3. JumpUnit 实例化
  val jumpUnit = Module(new JumpUnit)
  jumpUnit.io.pc    := io.pc
  jumpUnit.io.rs1   := io.reg_rs1
  jumpUnit.io.imm   := io.imm.asUInt
  jumpUnit.io.isJal := (io.TYpe === "b0110".U)
  jumpUnit.io.isJalr:= (io.TYpe === "b0111".U)

  // —— 4. 输出赋值
  io.result_out    := alu.io.result
  io.branch_taken  := false.B
  io.branch_target := 0.U
  io.jump_target   := 0.U

  switch(io.TYpe) {
    is("b0011".U) { // B-type
      io.branch_taken  := branchUnit.io.taken
      io.branch_target := branchUnit.io.branch_target
      io.result_out    := branchUnit.io.taken.asUInt // 如果需要也可将 0/1 放 result_out
    }
    is("b0110".U) { // JAL
      io.jump_target := jumpUnit.io.jump_pc
      io.result_out  := jumpUnit.io.jump_pc        // result_out 也可以放跳转目标
    }
    is("b0111".U) { // JALR
      io.jump_target := jumpUnit.io.jump_pc
      io.result_out  := jumpUnit.io.jump_pc
    }
  }
}
