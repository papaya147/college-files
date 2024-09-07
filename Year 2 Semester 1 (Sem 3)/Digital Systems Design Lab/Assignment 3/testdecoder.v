module testdecoder;
    reg e;
    reg [0:2]x;
    wire [0:7]f;
    decoder3to8 d1(e, x, f);
    initial begin
        e = 0;
        x = 3'b000;
        #100
        x = 3'b001;
        #100
        x = 3'b010;
        #100
        x = 3'b011;
        #100
        x = 3'b100;
        #100
        x = 3'b101;
        #100
        x = 3'b110;
        #100
        x = 3'b111;
        #100
        x = 2'b00;
    end
endmodule