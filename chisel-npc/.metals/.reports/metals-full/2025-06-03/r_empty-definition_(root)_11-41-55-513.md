error id: file://<WORKSPACE>/src/main/scala/top.scala:
file://<WORKSPACE>/src/main/scala/top.scala
empty definition using pc, found symbol in pc: 
empty definition using semanticdb
empty definition using fallback
non-local guesses:

offset: 666
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
  val pc = 
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
  regFile.io.writeEnable := true.B // Enable @@writing to the register file
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

empty definition using pc, found symbol in pc: 