// Dataflow
module fulladder(a, b, c, sum, carry);
    input a, b, c;
    output reg sum, carry;
    always @(*);

    begin
    xor1 = a ^ b;
    prod1 = a & b;
    prod2 = xor1 & c;
    carry = prod1 & prod2;

    sum = xor1 ^ c;
    end
endmodule