module fullsubtractor_structural(x, y, z, b, d);
input x, y, z;
output b, d;
wire b1, d1, b2;
halfsubtractor_behavioural hsb1(x, y, b1, d1);
halfsubtractor_behavioural hsb2(d1, z, b2, d);
or(b, b1, b2);
endmodule