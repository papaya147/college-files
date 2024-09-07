module mux16to1(x, s, f);
    input [0:15]x;
    input [0:3]s;
    output f;
    wire [0:1]farr;
    mux8to1 eto1(x[0:7], s[1:3], farr[0]);
    mux8to1 eto2(x[8:15], s[1:3], farr[1]);
    mux2to1 tto1(farr, s[0], f);
endmodule