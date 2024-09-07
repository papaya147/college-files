module test_reg;

reg [3:0]i;
reg [1:0]s;
wire [3:0]f;
reg clk, clear, msb, lsb;

shift_reg sr1(i, f, s, msb, lsb, clk, clear);

always
    #5
    clk = ~clk;

initial begin
    i = 4'b0110;
    msb = 1; lsb = 1;
    s = 2'b00; #10
    s = 2'b01; #10
    s = 2'b10; #10
    s = 2'b11; #10
    s = 2'b11;
end

initial begin
    $dumpfile("dump.vcd");
    $dumpvars(1);
end

endmodule