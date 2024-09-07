module counter_mux(
    input [3:0]i,
    output reg [3:0]o,
    input [0:1]s,
    input clk, reset
);

always @(posedge clk)
    if (reset == 1)
        o <= 4'0000;
    case (s)
        2'b00: o <= i;
        2'b01: o <= o + 1'b1;
        2'b10: o <= o - 1'b1;
        2'b11: o <= o;

endmodule