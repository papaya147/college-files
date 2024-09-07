module SRflipflop(s, r, clk, rst, q, qbar);
  input s, r, clk, rst;
  output q, qbar;
  reg q;
  wire qbar;

  assign qbar = ~q;
  always @(posedge clk or posedge rst)
    begin
      if(rst)
        q <= 1'b0;
      else
        begin
          case({r,s})
            2'b00: q <= q;
            2'b01: q <= 1'b1;
            2'b10: q <= 1'b0;
            2'b11: q <= 1'bz;
          endcase
        end
    end
endmodule