package npc
import chisel3._
import chisel3.util._

class top extends Module{
val io = IO (new  Bundle {
    val instruction = Input(UInt(32.W)) // Input instruction
    val pc = Output(UInt(32.W)) // Program counter
  })

  val pc = RegInit("h80000000".U(32.W)) // Initialize program counter to 0x80000000
  val pc_snpc = pc + 4.U // static next program counter
  val pc_dnpc = RegInit("h80000000".U(32.W)) // Wire for dynamic next program counter
  //      "000"=R-type, "001"=I-Load, "010"=S-Store,
  //      "011"=B-Branch, "100"=I-calculate(ADDI…), "101"=U-type(LUI/AUIPC),
  //      "110"=JAL, "111"=JALR
  io.pc := pc // Output the current program counter
  val wen       = WireDefault(false.B)
  val writeData = WireDefault(0.U(32.W))



  // Instantiate IDU, RegFile, and EXU modules
  val idu = Module(new IDU())
  val regFile = Module(new RegFile())
  val exu = Module(new EXU())
  val dpiHandlers = Module(new DPIHandlers())
  // Connect IDU outputs to DPIHandlers inputs
  dpiHandlers.io.IsIllegal   := idu.io.IsIllegal
  dpiHandlers.io.IsInterrupt := idu.io.IsInterrupt
  //Connect IDU outputs to EXU inputs
  idu.io.instruction := io.instruction
  exu.io.funct3 := idu.io.funct3
  exu.io.funct7 := idu.io.funct7
  exu.io.imm := idu.io.imm.asSInt
  exu.io.TYpe := idu.io.TYpe
  exu.io.reg_rs1 := regFile.io.regData1
  exu.io.reg_rs2 := regFile.io.regData2
  exu.io.pc := pc
  
  // Connect IDU outputs to RegFile inputs
  regFile.io.rs1 := idu.io.rs1
  regFile.io.rs2 := idu.io.rs2
  regFile.io.rd := idu.io.rd
  regFile.io.writeEnable := wen
  regFile.io.writeData   := writeData

  //RegFile write data and enable
  val isBranch = (idu.io.TYpe === "b0011".U)
  val isStore  = (idu.io.TYpe === "b0010".U)
  val isJal    = (idu.io.TYpe === "b0110".U)
  val isJalr   = (idu.io.TYpe === "b0111".U)
  

//   Branch/Store/ebreak/unknown instruction → false；其它 → true
 wen:= (!isBranch && !isStore && !idu.io.IsIllegal && !idu.io.IsInterrupt)
//   如果是 JAL/JALR → exu.io.jump_target
//   否则           → exu.io.result_out
writeData:= Mux(
  isJal || isJalr,
  exu.io.jump_target,
  exu.io.result_out
)
//PC update logic
// 先计算一个“Branch 分支里要用的 Mux”：
//   如果分支条件成立 → exu.io.branch_target， 否则 → pc_snpc
val branchPath: UInt =
  Mux(exu.io.branch_taken, exu.io.branch_target, pc_snpc)

// 再用嵌套 Mux 依次判断 isBranch / isJalr / isJal / 其余
val pc_next: UInt = MuxLookup(idu.io.TYpe, pc_snpc, Seq(
  // “b011” = Branch
  "b0011".U -> branchPath,

  // “b111” = JALR
  "b0111".U -> exu.io.jump_target,

  // “b110” = JAL
  "b0110".U -> exu.io.jump_target

  // 其它情况全部走 “pc_snpc” —— default 已经给定
))

pc := pc_next


}