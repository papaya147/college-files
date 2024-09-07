// Gate Level
module fulladder(a, b, c, sum, carry);
    input a, b, c;
    output sum, carry;

    xor(xor1, a, b);
    and(prod1, a, b);
    and(prod2, xor1, c);
    or(carry, prod1, prod2);

    xor(sum, xor1, c);
endmodule