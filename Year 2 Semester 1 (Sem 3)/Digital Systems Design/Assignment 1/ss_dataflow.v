module ss_dataflow(a, b, c, d, out);
input a, b, c, d;
output [0:6]out;

assign out[0] = a | c | ~(b ^ d);
assign out[1] = ~b | ~(c ^ d);
assign out[2] = b | ~c | d;
assign out[3] = a | (~b & c) | (b & ~c & d) | (~d & (~b | c));
assign out[4] = ~d & (~b | c);
assign out[5] = (b & ~c) | (b & ~d) | (~c & ~d) | a;
assign out[6] = a | (b & ~c) | (~b & c) | (c & ~d);
endmodule