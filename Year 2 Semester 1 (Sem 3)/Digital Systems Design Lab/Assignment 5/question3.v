module ring_counter (
    output reg [3:0]o,
    input clk, clear
);

always @(posedge clk or posedge clear)
    if(clear == 1)
        o <= 4'b0000;
    else
        o <= {~o[0], o[3:1]};

endmodule