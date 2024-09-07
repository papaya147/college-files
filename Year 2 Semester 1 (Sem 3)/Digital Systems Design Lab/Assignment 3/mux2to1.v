module mux2to1(x, s, f);
    input [0:1]x;
    input s;
    output f;
    wire nots, prod1, prod2;
    not(nots, s);
    and(prod1, x[0], nots);
    and(prod2, x[1], s);
    or(f, prod1, prod2);
endmodule

// module mux2to1(x, s, f);
//     input [0:1]x;
//     input s;
//     output f;
//     wire nots, prod1, prod2;
//     always @(*);
//     begin
//         nots = ~s;
//         prod1 = x[0] & nots;
//         prod2 = x[1] & s;
//         f = prod1 | prod2;
//     end
// endmodule

// module mux2to1(x, s, f);
//     input [0:1]x;
//     input s;
//     output f;
//     wire nots, prod1, prod2;
//     assign nots = ~s;
//     assign prod1 = x[0] & nots;
//     assign prod2 = x[1] & s;
//     assign f = prod1 | prod2;
// endmodule

// module mux2to1(x, s, f);
//     input [0:1]x;
//     input s;
//     output f;
//     assign f = s ? x[0] : x[1];
// endmodule