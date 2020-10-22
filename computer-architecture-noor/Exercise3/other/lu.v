///////////////////////////16bit and
module and16(a,b,res);
input [15:0]a,b;
output [15:0]res;
assign res = a&b;
endmodule
//////////////////////////// 16bit or
module or16(a,b,res);
input [15:0]a,b;
output [15:0]res;
assign res = a|b;
endmodule
/////////////////////////// 16bit nand
module nand16(a,b,res);
input [15:0]a,b;
output [15:0]res;
assign res = ~(a&b);
endmodule
/////////////////////////// 16bit nor
module nor16(a,b,res);
input [15:0]a,b;
output [15:0]res;
assign res = ~(a|b);
endmodule
////////////////////////// 16bit not
module not16(a,res);
input [15:0]a;
output [15:0]res;
assign res = ~a;
endmodule
///////////////////////// 16bit xor
module xor16(a,b,res);
input [15:0]a,b;
output [15:0]res;
assign res = a^b;
endmodule
///////////////////////// 16bit xnor
module xnor16(a,b,res);
input [15:0]a,b;
output [15:0]res;
assign res = ~(a^b);
endmodule
///////////////////////// 2's complement
module twoscomplement(a,res);
input [15:0]a;
output [15:0]res;
assign res = ~a + 1'b1;
endmodule
/////////////////////////
// wire [7:0]select_res;
// assign select_res[0] = (~a[2]) & (~a[1]) &(~a[0]);
// assign select_res[1] = (~a[2]) & (~a[1]) &(a[0]);
// assign select_res[2] = (~a[2]) & (a[1]) &(~a[0]);
// assign select_res[3] = (~a[2]) & (a[1]) &(a[0]);
// assign select_res[4] = (a[2]) & (~a[1]) &(~a[0]);
// assign select_res[5] = (a[2]) & (~a[1]) &(a[0]);
// assign select_res[6] = (a[2]) & (a[1]) &(~a[0]);
// assign select_res[7] = (a[2]) & (a[1]) &(a[0]);
// always @ (*)
// begin
// if (select_res[0])
//    and16 a1(a,b,out);
// else if(select_res[1])
//     or16 a2(a,b,out);
// else if(select_res[2])
//     nand16 a3(a,b,out);
// else if(select_res[3])
//     nor16 a4(a,b,out);
// else if(select_res[4])
//     not16 a5(a,out);
// else if(select_res[5])
//     xor16 a6(a,b,out);
// else if(select_res[6])
//     xnor16 a7(a,b,out);
// else if(select_res[3])
//     twoscomplement a8(a,out);
// end
//////////////////////////////////
// always @* begin
//   case(select)
//     3'b000: and16 a1(a,b,out);
//     3'b001: or16 a2(a,b,out);
//     3'b010: nand16 a3(a,b,out);
//     3'b011: nor16 a4(a,b,out);
//     3'b100: not16 a5(a,out);
//     3'b101: xor16 a6(a,b,out);
//     3'b110: xnor16 a7(a,b,out);
//     3'b111: twoscomplement a8(a,out);
//   endcase
// end