module mux4to1(x, s, f);
    input [0:3]x;
    input [0:1]s;
    output f;
    wire [0:1]farr;
    mux2to1 tto1(x[0:1], s[1], farr[0]);
    mux2to1 tto2(x[2:3], s[1], farr[1]);
    mux2to1 tto3(farr, s[0], f);
endmodule