package npc

import chisel3._
import chisel3.util._


class RegFile extends Module {
  val io = IO(new Bundle {
    val rs1 = Input(UInt(5.W)) // Source register 1
    val rs2 = Input(UInt(5.W)) // Source register 2
    val rd = Input(UInt(5.W)) // Destination register
    val writeData = Input(UInt(32.W)) // Data to write to the register file
    val writeEnable = Input(Bool()) // Write enable signal
    val regData1 = Output(UInt(32.W)) // Data from register rs1
    val regData2 = Output(UInt(32.W)) // Data from register rs2
  })

  // Register file with 32 registers, each 32 bits wide
  val regFile = RegInit(VecInit(Seq.fill(32)(0.U(32.W))))
    // Initialize register 0 to zero
    regFile(0) := 0.U     
  // Read data from registers
  io.regData1 := regFile(io.rs1)
  io.regData2 := regFile(io.rs2)

  // Write data to the register file if writeEnable is high and rd is not zero
  when(io.writeEnable && io.rd =/= 0.U) {
    regFile(io.rd) := io.writeData
  }
}