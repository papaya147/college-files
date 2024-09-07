module halfsubtractor_dataflow(x, y, b, d);
input x, y;
output b, d;
assign d = x ^ y;
assign notx = ~x;
assign b = notx & y;
endmodule