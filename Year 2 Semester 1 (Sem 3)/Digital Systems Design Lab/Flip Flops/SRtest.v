module SRtest;
  reg s, r, clk, rst;
  wire q, qbar;
  SRflipflop srff1(r, s, clk, rst, q, qbar);
  always
    #5
    clk = ~clk;
  initial begin
    r = 0; s = 0; clk = 0; rst = 1;
    #10
    rst = 0;
    #10
    r = 0; s = 1;
    #10
    r = 1; s = 0;
    #10
    r = 1; s = 1;
    #50
    $stop;
  end
endmodule
