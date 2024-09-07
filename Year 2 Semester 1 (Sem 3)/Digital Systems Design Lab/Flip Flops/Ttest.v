module Ttest;
  reg t, clk, rst;
  wire q, qbar;
  Tflipflop tff1(t, clk, rst, q, qbar);
  always
    #5
    clk = ~clk;
  initial begin
    t = 0; clk = 0; rst = 1;
    #10
    rst = 0;
    #10
    t = 1;
    #50
    $stop;
  end
endmodule