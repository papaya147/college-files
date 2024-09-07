module shift_reg (
    input [3:0]i,
    output reg [3:0]o,
    input [1:0]s,
    input MSB, LSB, clk, clear
);

always @(posedge clk or negedge clear)
    if (clear == 0)
        o <= 4'b0000;
    else
        case (s)
            2'b00: o <= o;
            2'b01: o <= {MSB, o[3:1]};
            2'b10: o <= {o[2:0], LSB};
            2'b11: o <= i;
        endcase

endmodule