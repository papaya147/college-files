module test_updowncounter;

reg [3:0]in;
wire [3:0]out;
reg load, up, down, clk, reset;

counter rc(in, out, load, up, down, clk, reset);

always
    #5 
    count = ~count;

initial begin
    reset = 1; clk = 0; up = 1;
    #20
    down = 1;
    #20
    in = 4'b1000; load = 1;
    #10
    up = 1;
end

endmodule
