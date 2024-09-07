module halfsubtractor_behavioural(x, y, b, d);
input x, y;
output reg b, d;
always @(*)
begin
d = x ^ y;
b = ~x & y;
end
endmodule