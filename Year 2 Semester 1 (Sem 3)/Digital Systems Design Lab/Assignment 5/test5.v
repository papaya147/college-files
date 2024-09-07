module test_ripple_counter;

reg count;
reg reset;
wire [0:3]out;
ripple_counter rc(out, count, reset);
always
    #5 
    count = ~count;
initial begin
    count = 1'b0;
    reset = 1'b1;
    #4 
    reset = 1'b0;
end

endmodule
