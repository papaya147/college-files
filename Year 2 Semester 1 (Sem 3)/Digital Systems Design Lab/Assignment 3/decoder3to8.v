module decoder3to8(e, x, f);
    input e;
    input [0:2]x;
    output [0:7]f;
    assign f[0] = ~(~e & ~x[0] & ~x[1] & ~x[2]);
    assign f[1] = ~(~e & ~x[0] & ~x[1] & x[2]);
    assign f[2] = ~(~e & ~x[0] & x[1] & ~x[2]);
    assign f[3] = ~(~e & ~x[0] & x[1] & x[2]);
    assign f[4] = ~(~e & x[0] & ~x[1] & ~x[2]);
    assign f[5] = ~(~e & x[0] & ~x[1] & x[2]);
    assign f[6] = ~(~e & x[0] & x[1] & ~x[2]);
    assign f[7] = ~(~e & x[0] & x[1] & x[2]);
endmodule