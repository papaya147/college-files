// Gate Level Model
module regno(a, b, c, d, f);
    input a, b, c, d;
    output f;
    
    not(nota, a);
    not(notb, b);
    not(notc, c);
    not(notd, d);
    
    and(prod1, nota, notb);

    and(prod2_1, nota, notc);
    and(prod2, prod2_1, notd);

    and(prod3_1, notb, c);
    and(prod3, prod3_1, d);
    
    and(prod4_1, a, b);
    and(prod4_2, notc, d);
    and(prod4, prod4_1, prod4_2);

    or(sum1, prod1, prod2);
    or(sum2, prod3, prod4);
    or(f, sum1, sum2);
endmodule
