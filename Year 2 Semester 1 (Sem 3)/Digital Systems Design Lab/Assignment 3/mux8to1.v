module mux8to1(x, s, f);
    input [0:7]x;
    input [0:2]s;
    output f;
    wire [0:1]farr;
    mux4to1 fto1(x[0:3], s[1:2], farr[0]);
    mux4to1 fto2(x[4:7], s[1:2], farr[1]);
    mux2to1 tto1(farr, s[0], f);
endmodule