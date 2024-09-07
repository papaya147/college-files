module ss_gate(a, b, c, d, out);
input a, b, c, d;
output [0:6]out;

not(abar, a);
not(bbar, b);
not(cbar, c);
not(dbar, d);

xnor(x1, b, d);
or(out[0], a, c, x1);

xnor(x2, c, d);
or(out[1], bbar, x2);

or(out[2], b, cbar, d);

and(p1, bbar, c);
and(p2, b, cbar, d);
and(p3, dbar, bbar);
and(p4, dbar, c);
or(out[3], a, p1, p2, p3, p4);

or(out[4], p3, p4);

and(p5, b, cbar);
and(p6, b, dbar);
and(p7, cbar, dbar);
or(out[5], a, p5, p6, p7);

or(out[6], a, p5, p1, p4);
endmodule