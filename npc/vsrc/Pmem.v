// vsrc/pmem.v
// A simple memory model driven by DPI-C:
//   pmem_read  : read a 32-bit word from DRAM
//   pmem_write : write one byte (wmask) into DRAM

module Pmem (
  input        valid,    // 有效的访存周期
  input        wen,      // 写使能
  input  [3:0] wmask,    // 每一位对应一个字节写掩码
  input  [31:0] raddr,   // 读地址
  input  [31:0] waddr,   // 写地址
  input  [31:0] wdata,   // 写数据
  output reg [31:0] rdata // 读数据
);
  import "DPI-C" function int pmem_read(input int raddr);
  import "DPI-C" function void pmem_write(
    input int waddr,
    input int wdata,
    input byte wmask
  );

  always @(*) begin
    if (valid) begin
      // 先读
      rdata = pmem_read(raddr);
      // 再写
      if (wen) begin
        pmem_write(waddr+0, wdata>> 0,  wmask[0] ? 8'h01 : 8'h00);
        pmem_write(waddr+1, wdata>> 8,  wmask[1] ? 8'h02 : 8'h00);
        pmem_write(waddr+2, wdata>> 16, wmask[2] ? 8'h04 : 8'h00);
        pmem_write(waddr+3, wdata>> 24, wmask[3] ? 8'h08 : 8'h00);
      end
    end else begin
      rdata = 0;
    end
  end
endmodule
