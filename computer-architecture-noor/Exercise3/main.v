//logical unit
module lu_new(a,b,out,select);
input [15:0]a,b;
output reg [15:0]out;
input [2:0]select;

always @* begin
  case(select)
    3'b000: out = a & b; //and
    3'b001: out = a | b; //or
    3'b010: out = ~(a & b); //nand
    3'b011: out = ~(a | b); //nor
    3'b100: out = ~a; //not
    3'b101: out = a ^ b; //xor
    3'b110: out = ~(a ^ b); //xnor
    3'b111: out = ~a + 1'b1; //2's complement
  endcase
end
endmodule