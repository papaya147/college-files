module shift_reg_struct (
    input [3:0]i,
    output reg [3:0]o,
    input [1:0]s,
    input MSB, LSB, clk, clear
);

stage s0(o[0], o[1], LSB, i[0], s, clk, clear);
stage s1(o[1], o[2], o[0], i[1], s, clk, clear);
stage s2(o[2], o[3], o[1], i[2], s, clk, clear);
stage s3(o[3], MSB, o[2], i[3], s, clk, clear);
    
endmodule

module stage (
    input [0:3]i,
    input [0:1]s,
    output q,
    input clk, clear
);

wire mux_out;
mux4to1 m(i, s, mux_out);
dflipflop d(mux_out, q, clk, clear);

endmodule

module mux4to1 (
    input [0:3]i,
    input [0:1]s,
    output reg o,
    input clk,
);

always @(s)
    case(s)
        2'b00: o = i[0];
        2'b01: o = i[1];
        2'b10: o = i[2];
        2'b11: o = i[3];
    endcase
    
endmodule

module dflipflop (
    input d,
    output reg q,
    input clk, clear
);

always @(posedge clk or negedge clear)
    if(clear == 0)
        q <= 1'b0;
    else
        q <= d;

endmodule