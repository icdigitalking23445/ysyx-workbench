package npc
import chisel3._
import chisel3.util._
import java.awt.Window.Type

class IDU extends Module {
  val io = IO(new Bundle {
    val instruction = Input(UInt(32.W))
    val rs1 = Output(UInt(5.W))
    val rs2 = Output(UInt(5.W))
    val rd = Output(UInt(5.W))
    val funct3 = Output(UInt(3.W))
    val funct7 = Output(UInt(7.W))
    val imm = Output(SInt(12.W))
    val TYpe = Output(UInt(4.W)) // Type of instruction (R, I, S, B, U, J)
    //val pc_sel = Output(UInt(2.W)) // PC selection signal
    val IsIllegal = Output(Bool()) // Illegal instruction flag
    val IsInterrupt = Output(Bool()) // Interrupt instruction flag
  })
  // Set pc_sel based on instruction type
  //io.pc_sel := MuxLookup(io.instruction(6, 0), 0.U(2.W), Seq(
    //"b1101111".U -> "b01".U, // JAL
    //"b1100011".U -> "b10".U, // Branch
    //"b0110111".U -> "b00".U, // LUI
    //"b0010111".U -> "b00".U  // AUIPC
  //))
  // Decode the instruction
  io.IsIllegal := Mux(io.TYpe === "b1000".U,true.B, false.B) // Default to not illegal

  io.IsInterrupt := Mux(io.TYpe === "b1001".U,true.B,false.B) // Default to not interrupt



  io.TYpe := MuxLookup(io.instruction(6, 0), "b1000".U, Seq(
    "b0110011".U -> "b0000".U, // R-type
    "b0000011".U -> "b0001".U, // I-type (Load)
    "b0100011".U -> "b0010".U, // S-type 
    "b1100011".U -> "b0011".U, // B-type (Branch)
    "b0010011".U -> "b0100".U, // I-type (Immediate)
    "b0110111".U -> "b0101".U, // U-type (LUI)
    "b1101111".U -> "b0110".U, // J-type (JAL)
    "b0010111".U -> "b0101".U,  // U-type (AUIPC, treated as LUI for simplicity)
    "b1100111".U -> "b0111".U,  // I-type (JALR, treated as Immediate)
    //ebreak: set highest bit 1
    "b1110011".U -> "b1001".U 
  ))//default: illegal instruction
    io.rs1 := MuxLookup(io.TYpe, 0.U(5.W), Seq(
        "b0000".U -> io.instruction(19, 15), // R-type
        "b0001".U -> io.instruction(19, 15), // I-type (Load)
        "b0010".U -> io.instruction(24, 20), // S-type (Store)
        "b0011".U -> io.instruction(19, 15), // B-type (Branch)
        "b0100".U -> io.instruction(19, 15), // I-type (Immediate)
        "b0101".U -> 0.U, // U-type (LUI) - no rs1
        "b0110".U -> 0.U,  // J-type (JAL) - no rs1
        "b0111".U -> io.instruction(19, 15) // I-type (JALR, treated as Immediate)
    ))
    io.rs2 := MuxLookup(io.TYpe, 0.U(5.W), Seq(
        "b0000".U -> io.instruction(24, 20), // R-type
        "b0001".U -> 0.U, // I-type (Load) - no rs2
        "b0010".U -> io.instruction(19, 15), // S-type (Store)
        "b0011".U -> 0.U, // B-type (Branch) - no rs2
        "b0100".U -> io.instruction(24, 20), // I-type (Immediate)
        "b0101".U -> 0.U, // U-type (LUI) - no rs2
        "b0110".U -> 0.U,  // J-type (JAL) - no rs2
        "b0111".U -> 0.U // I-type (JALR, treated as Immediate - no rs2
    ))
    io.rd := MuxLookup(io.TYpe, 0.U(5.W), Seq(
        "b0000".U -> io.instruction(11, 7), // R-type
        "b0001".U -> io.instruction(11, 7), // I-type (Load)
        "b0010".U -> 0.U, // S-type (Store) - no rd
        "b0011".U -> 0.U, // B-type (Branch) - no rd
        "b0100".U -> io.instruction(11, 7), // I-type (Immediate)
        "b0101".U -> io.instruction(11, 7), // U-type (LUI)
        "b0110".U -> io.instruction(11, 7),  // J-type (JAL)
        "b0111".U -> io.instruction(11, 7) // I-type (JALR, treated as Immediate)
    ))

    io.imm := MuxLookup(io.TYpe, 0.S(12.W), Seq(
        "b0000".U -> 0.S, // R-type - no immediate
        "b0001".U -> io.instruction(31, 20).asSInt, // I-type (Load)
        "b0010".U -> Cat(io.instruction(31, 25), io.instruction(11, 7)).asSInt, // S-type (Store)
        "b0011".U -> Cat(io.instruction(31, 25), io.instruction(11, 8), io.instruction(7)).asSInt, // B-type (Branch)
        "b0100".U -> Cat(io.instruction(31, 20)).asSInt, // I-type (Immediate)
        "b0101".U -> Cat(io.instruction(31, 12), 0.U(12.W)).asSInt, // U-type (LUI)
        "b0110".U -> Cat(io.instruction(31, 12), 0.U(12.W)).asSInt, // J-type (JAL)
        "b0111".U -> Cat(io.instruction(31, 20)).asSInt // I-type (JALR, treated as Immediate)
    ))
    io.funct3 := io.instruction(14, 12) // Extract funct3 field
    io.funct7 := io.instruction(31, 25) // Extract funct7 field
    
}