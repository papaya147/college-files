module alu(a, b, sel, carry, out);
  input [0:7]a, b;
  input [0:3]sel;
  output carry;
  output [0:7]out;
  reg [0:8]res;
  
  assign out = res[1:8];
  assign carry = res[0];
  always @(*)
    begin
      case(sel)
        4'b0000: //addition
          res = a + b;
        4'b0001: //subtraction
          res = a - b;
        4'b0010: //multiplication
          res = a * b;
        4'b0011: //division
          res = a / b;
        4'b0100: //increment
          res = a + 4'b0001;
        4'b0101: //decrement
          res = a - 4'b0001;
        4'b0110: //logical AND
          res = a & b;
        4'b0111: //logical OR
          res = a | b;
        4'b1000: //logical NOT
          res = ~a;
        4'b1001: //logical NAND
          res = ~(a & b);
        4'b1010: //logical NOR
          res = ~(a | b);
        4'b1011: //logical XOR
          res = a ^ b;
        4'b1100: //logical XNOR
          res = ~(a ^ b);
        4'b1101: //greater comparision
          res = (a > b) ? 8'd1 : 8'd0;
        4'b1110: //lesser comparision
          res = (a < b) ? 8'd1 : 8'd0;
        4'b1111: //equal comparision
          res = (a == b) ? 8'd1 : 8'd0;
      endcase
    end
endmodule