module test;
    reg a, b;
    wire sum, carry;
    halfadder ha1(a, b, sum, carry);
    initial
    begin
        a = 0; b = 0;
        #100
        a = 0; b = 1;
        #100
        a = 1; b = 0;
        #100
        a = 1; b = 1;
    end
endmodule