module Dflipflop(d, clk, rst, q, qbar);
  input d, clk, rst;
  output q, qbar;
  reg q;
  wire qbar;
  assign qbar = ~q;
  always @(posedge clk or posedge rst)
    begin
      if(rst)
        q <= 1'b0;
      else
        q <= d;
    end
endmodule