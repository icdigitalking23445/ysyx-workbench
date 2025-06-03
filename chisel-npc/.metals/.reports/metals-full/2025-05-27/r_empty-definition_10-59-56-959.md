error id: file://<WORKSPACE>/src/main/scala/IDU.scala:`<none>`.
file://<WORKSPACE>/src/main/scala/IDU.scala
empty definition using pc, found symbol in pc: `<none>`.
empty definition using semanticdb
empty definition using fallback
non-local guesses:
	 -chisel3/imm.
	 -chisel3/imm#
	 -chisel3/imm().
	 -chisel3/util/imm.
	 -chisel3/util/imm#
	 -chisel3/util/imm().
	 -imm.
	 -imm#
	 -imm().
	 -scala/Predef.imm.
	 -scala/Predef.imm#
	 -scala/Predef.imm().
offset: 321
uri: file://<WORKSPACE>/src/main/scala/IDU.scala
text:
```scala
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
    val im@@m = Output(SInt(12.W))
    val TYpe = Output(UInt(3.W)) // Type of instruction (R, I, S, B, U, J)
  })

  // Decode the instruction
  io.TYpe := MuxLookup(io.instruction(6, 0), 0.U(3.W), Seq(
    "b0110011".U -> "b000".U, // R-type
    "b0000011".U -> "b001".U, // I-type (Load)
    "b0100011".U -> "b010".U, // S-type (Store)
    "b1100011".U -> "b011".U, // B-type (Branch)
    "b0010011".U -> "b100".U, // I-type (Immediate)
    "b0110111".U -> "b101".U, // U-type (LUI)
    "b1101111".U -> "b110".U  // J-type (JAL)
  ))
    io.rs1 := MuxLookup(io.TYpe, 0.U(5.W), Seq(
        "b000".U -> io.instruction(19, 15), // R-type
        "b001".U -> io.instruction(19, 15), // I-type (Load)
        "b010".U -> io.instruction(24, 20), // S-type (Store)
        "b011".U -> io.instruction(19, 15), // B-type (Branch)
        "b100".U -> io.instruction(19, 15), // I-type (Immediate)
        "b101".U -> 0.U, // U-type (LUI) - no rs1
        "b110".U -> 0.U  // J-type (JAL) - no rs1
    ))
    io.rs2 := MuxLookup(io.TYpe, 0.U(5.W), Seq(
        "b000".U -> io.instruction(24, 20), // R-type
        "b001".U -> 0.U, // I-type (Load) - no rs2
        "b010".U -> io.instruction(19, 15), // S-type (Store)
        "b011".U -> 0.U, // B-type (Branch) - no rs2
        "b100".U -> io.instruction(24, 20), // I-type (Immediate)
        "b101".U -> 0.U, // U-type (LUI) - no rs2
        "b110".U -> 0.U  // J-type (JAL) - no rs2
    ))
    io.rd := MuxLookup(io.TYpe, 0.U(5.W), Seq(
        "b000".U -> io.instruction(11, 7), // R-type
        "b001".U -> io.instruction(11, 7), // I-type (Load)
        "b010".U -> 0.U, // S-type (Store) - no rd
        "b011".U -> 0.U, // B-type (Branch) - no rd
        "b100".U -> io.instruction(11, 7), // I-type (Immediate)
        "b101".U -> io.instruction(11, 7), // U-type (LUI)
        "b110".U -> io.instruction(11, 7)  // J-type (JAL)
    ))

    io.imm := MuxLookup(io.TYpe, 0.S(12.W), Seq(
        "b000".U -> 0.S, // R-type - no immediate
        "b001".U -> io.instruction(31, 20).asSInt, // I-type (Load)
        "b010".U -> Cat(io.instruction(31, 25), io.instruction(11, 7)).asSInt, // S-type (Store)
        "b011".U -> Cat(io.instruction(31, 25), io.instruction(11, 8), io.instruction(7)).asSInt, // B-type (Branch)
        "b100".U -> Cat(io.instruction(31, 20)).asSInt, // I-type (Immediate)
        "b101".U -> Cat(io.instruction(31, 12), 0.U(12.W)).asSInt, // U-type (LUI)
        "b110".U -> Cat(io.instruction(31, 12), 0.U(12.W)).asSInt // J-type (JAL)
    ))
  
}
```


#### Short summary: 

empty definition using pc, found symbol in pc: `<none>`.