// active low decoder
module decoder(a, b, e, out);
input a, b, e;
output [0:3] out;
wire nota, notb, note;
not(nota, a);
not(notb, b);
not(note, e);
nand(out[0], nota, notb, note);
nand(out[1], nota, b, note);
nand(out[2], a, notb, note);
nand(out[3], a, b, note);
endmodule