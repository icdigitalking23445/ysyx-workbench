package npc
import chisel3._
import chisel3.util._

class IDU extends Module {
  val io = IO(new Bundle {
    val instruction = Input(UInt(32.W))
    val rs1 = Output(UInt(5.W))
    val rs2 = Output(UInt(5.W))
    val rd = Output(UInt(5.W))
    val funct3 = Output(UInt(3.W))
    val funct7 = Output(UInt(7.W))
    val imm = Output(SInt(12.W))
    val TYpe = Output(UInt(3.W)) // Type of instruction (R, I, S, B, U, J)
    val pc_sel = Output(UInt(2.W)) // PC selection signal
  })
  // Set pc_sel based on instruction type
  io.pc_sel := MuxLookup(io.instruction(6, 0), 0.U(2.W), Seq(
    "b1101111".U -> "b01".U, // JAL
    "b1100011".U -> "b10".U, // Branch
    "b0110111".U -> "b00".U, // LUI
    "b0010111".U -> "b00".U  // AUIPC
  ))
  // Decode the instruction
  io.TYpe := MuxLookup(io.instruction(6, 0), 0.U(3.W), Seq(
    "b0110011".U -> "b000".U, // R-type
    "b0000011".U -> "b001".U, // I-type (Load)
    "b0100011".U -> "b010".U, // S-type 
    "b1100011".U -> "b011".U, // B-type (Branch)
    "b0010011".U -> "b100".U, // I-type (Immediate)
    "b0110111".U -> "b101".U, // U-type (LUI)
    "b1101111".U -> "b110".U, // J-type (JAL)
    "b0010111".U -> "b101".U,  // U-type (AUIPC, treated as LUI for simplicity)
    "b1100111".U -> "b111".U  // I-type (JALR, treated as Immediate)
  ))
    io.rs1 := MuxLookup(io.TYpe, 0.U(5.W), Seq(
        "b000".U -> io.instruction(19, 15), // R-type
        "b001".U -> io.instruction(19, 15), // I-type (Load)
        "b010".U -> io.instruction(24, 20), // S-type (Store)
        "b011".U -> io.instruction(19, 15), // B-type (Branch)
        "b100".U -> io.instruction(19, 15), // I-type (Immediate)
        "b101".U -> 0.U, // U-type (LUI) - no rs1
        "b110".U -> 0.U,  // J-type (JAL) - no rs1
        "b111".U -> io.instruction(19, 15) // I-type (JALR, treated as Immediate)
    ))
    io.rs2 := MuxLookup(io.TYpe, 0.U(5.W), Seq(
        "b000".U -> io.instruction(24, 20), // R-type
        "b001".U -> 0.U, // I-type (Load) - no rs2
        "b010".U -> io.instruction(19, 15), // S-type (Store)
        "b011".U -> 0.U, // B-type (Branch) - no rs2
        "b100".U -> io.instruction(24, 20), // I-type (Immediate)
        "b101".U -> 0.U, // U-type (LUI) - no rs2
        "b110".U -> 0.U,  // J-type (JAL) - no rs2
        "b111".U -> 0.U // I-type (JALR, treated as Immediate - no rs2
    ))
    io.rd := MuxLookup(io.TYpe, 0.U(5.W), Seq(
        "b000".U -> io.instruction(11, 7), // R-type
        "b001".U -> io.instruction(11, 7), // I-type (Load)
        "b010".U -> 0.U, // S-type (Store) - no rd
        "b011".U -> 0.U, // B-type (Branch) - no rd
        "b100".U -> io.instruction(11, 7), // I-type (Immediate)
        "b101".U -> io.instruction(11, 7), // U-type (LUI)
        "b110".U -> io.instruction(11, 7),  // J-type (JAL)
        "b111".U -> io.instruction(11, 7) // I-type (JALR, treated as Immediate)
    ))

    io.imm := MuxLookup(io.TYpe, 0.S(12.W), Seq(
        "b000".U -> 0.S, // R-type - no immediate
        "b001".U -> io.instruction(31, 20).asSInt, // I-type (Load)
        "b010".U -> Cat(io.instruction(31, 25), io.instruction(11, 7)).asSInt, // S-type (Store)
        "b011".U -> Cat(io.instruction(31, 25), io.instruction(11, 8), io.instruction(7)).asSInt, // B-type (Branch)
        "b100".U -> Cat(io.instruction(31, 20)).asSInt, // I-type (Immediate)
        "b101".U -> Cat(io.instruction(31, 12), 0.U(12.W)).asSInt, // U-type (LUI)
        "b110".U -> Cat(io.instruction(31, 12), 0.U(12.W)).asSInt, // J-type (JAL)
        "b111".U -> Cat(io.instruction(31, 20)).asSInt // I-type (JALR, treated as Immediate)
    ))
    io.funct3 := io.instruction(14, 12) // Extract funct3 field
    io.funct7 := io.instruction(31, 25) // Extract funct7 field
    
}