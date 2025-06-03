error id: file://<WORKSPACE>/src/main/scala/top.scala:local0
file://<WORKSPACE>/src/main/scala/top.scala
empty definition using pc, found symbol in pc: local0
empty definition using semanticdb
empty definition using fallback
non-local guesses:
	 -chisel3/idu/io/TYpe.
	 -chisel3/idu/io/TYpe#
	 -chisel3/idu/io/TYpe().
	 -chisel3/util/idu/io/TYpe.
	 -chisel3/util/idu/io/TYpe#
	 -chisel3/util/idu/io/TYpe().
	 -idu/io/TYpe.
	 -idu/io/TYpe#
	 -idu/io/TYpe().
	 -scala/Predef.idu.io.TYpe.
	 -scala/Predef.idu.io.TYpe#
	 -scala/Predef.idu.io.TYpe().
offset: 478
uri: file://<WORKSPACE>/src/main/scala/top.scala
text:
```scala
package npc
import chisel3._
import chisel3.util._

class top extends Module{
val io = IO (new  Bundle {
    val instruction = Input(UInt(32.W)) // Input instruction
    val pc = Output(UInt(32.W)) // Program counter
  })
  val pc = RegInit(0x80000000.U(32.W)) // Initialize program counter to 0x80000000
  val pc_snpc = pc + 4.U // static next program counter
  val pc_dnpc = RegInit(0x80000000.U(32.W)) // Wire for dynamic next program counter
  pc_dnpc := MuxLookup(idu.io.TY@@pe, pc_snpc, Seq(  
    "b011".U -> exu.io.result_out, // B-type (Branch)
    "b100".U -> exu.io.result_out(~1.U(32.W)), // I-type (JALR)
    "b110".U -> exu.io.result_out // J-type (Jal)
  ))
  // Instantiate IDU, RegFile, and EXU modules
  val idu = Module(new IDU())
  val regFile = Module(new RegFile())
  val exu = Module(new EXU())
  // Connect IDU inputs
  idu.io.instruction := io.instruction
  // Connect IDU outputs to RegFile and EXU
  regFile.io.rs1 := idu.io.rs1
  regFile.io.rs2 := idu.io.rs2
  regFile.io.rd := idu.io.rd
  regFile.io.writeData := exu.io.result_out
  regFile.io.writeEnable := true.B // Enable writing to the register file
  // Connect RegFile outputs to EXU
  exu.io.reg_rs1 := regFile.io.regData1
  exu.io.reg_rs2 := regFile.io.regData2
  // Connect IDU outputs to EXU
  exu.io.funct3 := idu.io.funct3
  exu.io.funct7 := idu.io.funct7
  exu.io.imm := idu.io.imm
  exu.io.TYpe := idu.io.TYpe // Type of instruction
  // Connect EXU output to RegFile
  regFile.io.writeEnable := true.B // Enable writing to the register file
  regFile.io.writeData := exu.io.result_out // Write the result from EXU to the register file



}
```


#### Short summary: 

empty definition using pc, found symbol in pc: local0