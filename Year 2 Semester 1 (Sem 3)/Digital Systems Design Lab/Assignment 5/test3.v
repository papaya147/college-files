module test_ring;

wire [3:0]counter;
reg clk, clear;

ring_counter rc(counter, clk, clear)

always
    #5
    clk = ~clk;

initial begin
    clear = 1; clk = 0;
    #10
    clear = 0;
    counter = 4'b0000;
end

endmodule