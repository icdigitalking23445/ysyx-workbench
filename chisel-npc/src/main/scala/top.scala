package npc
import chisel3._
import chisel3.util._

class top extends Module{
val io = IO (new  Bundle {
    val instruction = Input(UInt(32.W)) // Input instruction
    val pc = Output(UInt(32.W)) // Program counter
  })
  val pc = RegInit(0x80000000.U(32.W)) // Initialize program counter to 0x80000000
  val pc_snpc = Wire(pc + 4.U) // static next program counter
  val pc_dnpc = RegInit(0x80000000.U(32.W)) // Wire for dynamic next program counter
  //      "000"=R-type, "001"=I-Load, "010"=S-Store,
  //      "011"=B-Branch, "100"=I-calculate(ADDI…), "101"=U-type(LUI/AUIPC),
  //      "110"=JAL, "111"=JALR
  
  val wen       = WireDefault(false.B)
  val writeData = WireDefault(0.U(32.W))



  // Instantiate IDU, RegFile, and EXU modules
  val idu = Module(new IDU())
  val regFile = Module(new RegFile())
  val exu = Module(new EXU())

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
  //RegFile write data and enable
  val isBranch = (idu.io.TYpe === "b011".U)
  val isStore  = (idu.io.TYpe === "b010".U)
  val isJal    = (idu.io.TYpe === "b110".U)
  val isJalr   = (idu.io.TYpe === "b111".U)
 when (isStore || isBranch) {
    // Store/Branch 不写寄存器
    wen := false.B
  } .elsewhen (isJal || isJalr) {
    // JAL / JALR: 写 rd = exu.io.jump_target
    wen        := true.B
    writeData  := exu.io.jump_target
  } .otherwise {
    // 其余类型（R / I-Load / I-arith / U-type）写回 exu.io.result_out
    wen        := true.B
    writeData  := exu.io.result_out
  }
//PC update logic
val pc_next = Wire(UInt(32.W))
  when (isBranch) {
    // Branch: 若 exu.io.branch_taken = 1，跳到 exu.io.branch_target；否则顺序 +4
    pc_next := Mux(exu.io.branch_taken, exu.io.branch_target, pc_snpc)
  } .elsewhen (isJalr) {
    // JALR: 跳转到 exu.io.jump_target
    pc_next := exu.io.jump_target
  } .elsewhen (isJal) {
    // JAL: 跳转到 exu.io.jump_target
    pc_next := exu.io.jump_target
  } .otherwise {
    // 其余：顺序 +4
    pc_next := pc_snpc
  }

  // 写回 PC
  pc := pc_next


}