// vsrc/pmem.v
// A simple memory model driven by DPI-C:
//   pmem_read  : read a 32-bit word from DRAM
//   pmem_write : write one byte (wmask) into DRAM

module Pmem (
  input        clock,
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
    input int wmask
  );

  always @(*) begin
  // 默认读出 0
  rdata = 32'h0;
  
  // Load 操作：valid 为真且 wen 为假
  if (valid && !wen) begin
    rdata = pmem_read(raddr);
  end
  
  // Store 操作：valid 为真且 wen 为真

  if (valid && wen) begin
    // 写第 0 字节
    if (wmask[0]) pmem_write(waddr + 0, wdata >>  0, 32'h01);
    // 写第 1 字节
    if (wmask[1]) pmem_write(waddr + 1, wdata >>  8, 32'h02);
    // 写第 2 字节
    if (wmask[2]) pmem_write(waddr + 2, wdata >> 16, 32'h04);
    // 写第 3 字节
    if (wmask[3]) pmem_write(waddr + 3, wdata >> 24, 32'h08);
end
end
endmodule
