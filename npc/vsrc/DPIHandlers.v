
module DPIHandlers(
  input wire IsIllegal,
  input wire IsInterrupt
);
  // 从 C++ 侧导入 DPI-C 函数
  import "DPI-C" function void illegal_halt();
  import "DPI-C" function void interrupt_halt();

  // 当 IsIllegal 从 0 跳到 1 时，调用 illegal_halt()
  always @(posedge IsIllegal) begin
    if (IsIllegal) begin
      illegal_halt();
    end
  end

  // 当 IsInterrupt 从 0 跳到 1 时，调用 interrupt_halt()
  always @(posedge IsInterrupt) begin
    if (IsInterrupt) begin
      interrupt_halt();
    end
  end
endmodule
