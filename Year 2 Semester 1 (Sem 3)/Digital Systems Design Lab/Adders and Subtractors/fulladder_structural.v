module fulladder_structural(a, b, c, sum, carry);
input a, b, c;
output sum, carry;
wire s1, c1, c2;

halfadder_behavioural hab1(a, b, s1, c1);
halfadder_behavioural hab2(s1, c, sum, c2);
or(carry, c1, c2);
endmodule