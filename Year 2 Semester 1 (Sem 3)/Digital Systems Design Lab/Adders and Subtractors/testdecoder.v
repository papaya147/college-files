module testdecoder;
reg a, b, e;
wire [0:3] out;
decoder d(a, b, e, out);
initial begin
a = 0; b = 0; e = 0;
#100
a = 0; b = 1; e = 0;
#100
a = 1; b = 0; e = 0;
#100
a = 1; b = 1; e = 0;
end
endmodule