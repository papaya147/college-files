module test;
  reg [0:7]a, b;
  reg [0:3]sel;
  wire carry;
  wire [0:7]out;
  
  alu a1(a, b, sel, carry, out);
  initial begin
    a = 8'h2A;
    b = 8'hA2;
    sel = 4'h0; #100
    sel = 4'h1; #100
    sel = 4'h2; #100
    sel = 4'h3; #100
    sel = 4'h4; #100
    sel = 4'h5; #100
    sel = 4'h6; #100
    sel = 4'h7; #100
    sel = 4'h8; #100
    sel = 4'h9; #100
    sel = 4'hA; #100
    sel = 4'hB; #100
    sel = 4'hC; #100
    sel = 4'hD; #100
    sel = 4'hE; #100
    sel = 4'hF;
  end
 
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(1);
  end
endmodule