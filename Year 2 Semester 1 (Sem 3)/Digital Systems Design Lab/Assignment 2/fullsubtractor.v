module halfsubtractor(x, y, b, d);
    input x, y;
    output b, d;
    xor(d, x, y);
    not(notx, x);
    and(b, notx, y);
endmodule

module fullsubtractor(x, y, z, b, d);
    input x, y, z;
    output b, d;

    wire b1, d1, b2;

    halfsubtractor hs1(x, y, b1, d1);
    halfsubtractor hs2(d1, z, b2, d);
    or(b, b1, b2);
endmodule