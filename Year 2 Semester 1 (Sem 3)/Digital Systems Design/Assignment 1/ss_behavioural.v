module ss_behavioural(a, b, c, d, out);
input a, b, c, d;
output [0:6]out;
reg [0:6]res;
assign out = res;
always@(*)
begin
case({a, b, c, d})
4'b0000: res = 7'b1111110;
4'b0001: res = 7'b0110000;
4'b0010: res = 7'b1101101;
4'b0011: res = 7'b1111001;
4'b0100: res = 7'b0110011;
4'b0101: res = 7'b1011011;
4'b0110: res = 7'b1011111;
4'b0111: res = 7'b1110000;
4'b1000: res = 7'b1111111;
4'b1001: res= 7'b1111011;
endcase
end
endmodule