// Data Flow Model
module design(a, b, c, d, f);
    input a, b, c, d;
    output f;

    assign nota = ~a;
    assign notb = ~b;
    assign notc = ~c;
    assign notd = ~d;

    assign prod1 = nota & notb;

    assign prod2_1 = nota & notc;
    assign prod2 = prod2_1 & notd;

    assign prod3_1 = notb & c;
    assign prod3 = prod3_1 & d;

    assign prod4_1 = a & b;
    assign prod4_2 = notc & d;
    assign prod4 = prod4_1 & prod4_2;

    assign sum1 = prod1 | prod2;
    assign sum2 = prod3 | prod4;
    assign f = sum1 | sum2;
endmodule