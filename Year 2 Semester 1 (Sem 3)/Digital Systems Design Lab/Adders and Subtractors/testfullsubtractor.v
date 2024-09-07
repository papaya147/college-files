module testfullsubtractor;
reg a, b, c;
wire borrow, diff;
fullsubtractor_structural fss(a, b, c, borrow, diff);
initial
begin
a = 0; b = 0; c = 0;
#100
a = 0; b = 0; c = 1;
#100
a = 0; b = 1; c = 0;
#100
a = 0; b = 1; c = 1;
#100
a = 1; b = 0; c = 0;
#100
a = 1; b = 0; c = 1;
#100
a = 1; b = 1; c = 0;
#100
a = 1; b = 1; c = 1;
end
endmodule