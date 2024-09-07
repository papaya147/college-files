module decoder2to4(e, x, f);
    input e;
    input [0:1]x;
    output [0:3]f;
    assign f[0] = ~(~e & ~x[0] & ~x[1]);
    assign f[1] = ~(~e & ~x[0] & x[1]);
    assign f[2] = ~(~e & x[0] & ~x[1]);
    assign f[3] = ~(~e & x[0] & x[1]);
endmodule