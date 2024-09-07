// Dataflow
module fulladder(a, b, c, sum, carry);
    input a, b, c;
    output sum, carry;

    assign xor1 = a ^ b;
    assign prod1 = a & b;
    assign prod2 = xor1 & c;
    assign carry = prod1 & prod2;

    assign sum = xor1 ^ c;
endmodule