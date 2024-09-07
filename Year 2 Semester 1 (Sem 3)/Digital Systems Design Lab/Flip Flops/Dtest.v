module Dtest;
  reg d, clk, rst;
  wire q, qbar;
  Dflipflop dff1(d, clk, rst, q, qbar);
  always
    #5
    clk = ~clk;
  initial begin
    d = 0; clk = 0; rst = 1;
    #10
    rst = 0;
    #10
    d = 1;
    #50
    $stop;
  end
endmodule