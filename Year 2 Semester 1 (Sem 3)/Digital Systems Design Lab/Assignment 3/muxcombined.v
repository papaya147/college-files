module mux2to1(x, s, f);
    input [0:1]x;
    input s;
    output f;
    wire nots, prod1, prod2;
    not(nots, s);
    and(prod1, x[0], nots);
    and(prod2, x[1], s);
    or(f, prod1, prod2);
endmodule

module mux4to1(x, s, f);
    input [0:3]x;
    input [0:1]s;
    output f;
    wire [0:1]farr;
    mux2to1 tto1(x[0:1], s[1], farr[0]);
    mux2to1 tto2(x[2:3], s[1], farr[1]);
    mux2to1 tto3(farr, s[0], f);
endmodule

module mux8to1(x, s, f);
    input [0:7]x;
    input [0:2]s;
    output f;
    wire [0:1]farr;
    mux4to1 fto1(x[0:3], s[1:2], farr[0]);
    mux4to1 fto2(x[4:7], s[1:2], farr[1]);
    mux2to1 tto1(farr, s[0], f);
endmodule

module mux16to1(x, s, f);
    input [0:15]x;
    input [0:3]s;
    output f;
    wire [0:1]farr;
    mux8to1 eto1(x[0:7], s[1:3], farr[0]);
    mux8to1 eto2(x[8:15], s[1:3], farr[1]);
    mux2to1 tto1(farr, s[0], f);
endmodule