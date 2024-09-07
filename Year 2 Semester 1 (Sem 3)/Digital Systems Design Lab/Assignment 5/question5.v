module ripple_counter (
    output [0:3]o,
    input count, reset
);

comp_dflipflop d1(o[0], count, reset);
comp_dflipflop d2(o[1], o[0], reset);
comp_dflipflop d2(o[2], o[1], reset);
comp_dflipflop d2(o[3], o[2], reset);
    
endmodule

module comp_dflipflop (
    input d,
    output reg q,
    input clk, reset
);

always @(negedge clk or posedge reset)
    if(clear == 0)
        q <= 1'b0;
    else
        q <= #2 ~q;

endmodule