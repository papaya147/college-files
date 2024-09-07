module testhalfadder;
reg x, y;
wire s, c;
halfadder_behavioural had(x, y, s, c);
// halfadder_dataflow had(x, y, s, c);
initial begin
x = 0; y = 0;
#100
x = 0; y = 1;
#100
x = 1; y = 0;
#100
x = 1; y = 1;
end
endmodule