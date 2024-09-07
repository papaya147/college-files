module testhalfsubtractor;
reg a, b;
wire borrow, diff;
halfsubtractor_behavioural hsd(a, b, borrow, diff);
// halfsubtractor_dataflow hsd(a, b, borrow, diff);
initial
begin
a = 0; b = 0;
#100
a = 0; b = 1;
#100
a = 1; b = 0;
#100
a = 1; b = 1;
end
endmodule