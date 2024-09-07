module testbench;
reg a, b, c, d;
wire f;
regno r(a, b, c, d, f);
initial begin
a = 0; b = 0; c = 0; d = 0;
#5
a = 0; b = 0; c = 0; d = 1;
#5
a = 0; b = 0; c = 1; d = 0;
#5
a = 0; b = 0; c = 1; d = 1;
#5

a = 0; b = 1; c = 0; d = 0;
#5
a = 0; b = 1; c = 0; d = 1;
#5
a = 0; b = 1; c = 1; d = 0;
#5
a = 0; b = 1; c = 1; d = 1;
#5

a = 1; b = 0; c = 0; d = 0;
#5
a = 1; b = 0; c = 0; d = 1;
#5
a = 1; b = 0; c = 1; d = 0;
#5
a = 1; b = 0; c = 1; d = 1;
#5

a = 1; b = 1; c = 0; d = 0;
#5
a = 1; b = 1; c = 0; d = 1;
#5
a = 1; b = 1; c = 1; d = 0;
#5
a = 1; b = 1; c = 1; d = 1;
end
endmodule
