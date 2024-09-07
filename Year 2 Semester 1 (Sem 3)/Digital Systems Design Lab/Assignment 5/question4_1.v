module counter(
    input [3:0]i,
    output reg [3:0]o,
    input load, up, down,
    input clk, reset
);

always @(posedge clk)
    if (reset == 1)
        o <= 4'0000;
    if (load == 1)
        o <= i;
    if (up == 1)
        o <= o + 1'b1;
    if (down == 1)
        o <= o - 1'b1;

endmodule