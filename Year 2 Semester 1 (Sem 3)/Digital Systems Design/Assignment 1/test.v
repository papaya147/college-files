module test;
reg a, b, c, d;
wire [0:7]out;
ss_gate ss1(a, b, c, d, out);
initial begin
{a, b, c, d} = 4'b0000; #50
{a, b, c, d} = 4'b0001; #50
{a, b, c, d} = 4'b0010; #50
{a, b, c, d} = 4'b0011; #50
{a, b, c, d} = 4'b0100; #50
{a, b, c, d} = 4'b0101; #50
{a, b, c, d} = 4'b0110; #50
{a, b, c, d} = 4'b0111; #50
{a, b, c, d} = 4'b1000; #50
{a, b, c, d} = 4'b1001; #50
{a, b, c, d} = 4'b1010; #50
{a, b, c, d} = 4'b1011; #50
{a, b, c, d} = 4'b1100; #50
{a, b, c, d} = 4'b1101; #50
{a, b, c, d} = 4'b1110; #50
{a, b, c, d} = 4'b1111;
end
endmodule