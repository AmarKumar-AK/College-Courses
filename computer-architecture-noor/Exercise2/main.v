//fp multiplier
`include "doub.v"
`include "multi16.v"
module fpm(a,b,res);
input [15:0]a,b;
output [15:0]res;

wire [9:0]mantissaA,mantissaB;
wire [4:0]exponentA,exponentB;
wire signA,signB;
assign mantissaA = a[9:0];
assign mantissaB = b[9:0];
assign exponentA = a[14:10];
assign exponentB = b[14:10];
assign signA = a[15];
assign signB = b[15];
//evaluating sign
assign res[15] = signA ^ signB;

//evaluating exponent
wire [15:0]makeAexp16bit,makeBexp16bit;
assign makeAexp16bit = {11'b0,exponentA};
assign makeBexp16bit = {11'b0,exponentB};
wire [15:0]tempA,tempB;
wire tempA1,tempB1;//not for use
doub d1(makeAexp16bit,16'b10001,1'b0,tempA,tempA1);
doub d2(makeBexp16bit,16'b10001,1'b0,tempB,tempB1);

wire [15:0]tempAB;
wire tempAB1;
doub d3(tempA,tempB,1'b0,tempAB,tempAB1);
wire [15:0]res_exp;
wire res_exp1;
doub d4(tempAB,16'b01111,1'b0,res_exp,res_exp1);
assign res[14:10] = res_exp[4:0];

//evaluating mantissa
wire [15:0]makeAman16bit,makeBman16bit;
assign makeAman16bit = {5'b0,1'b1,mantissaA};
assign makeBman16bit = {5'b0,1'b1,mantissaB};
wire [31:0]manAB;
multi16 m1(makeAman16bit,makeBman16bit,manAB);
// always @(*)
// begin
//     $monitor(" %b  %b %b  ",makeAman16bit,makeBman16bit,manAB);
// end
assign res[9:0] = manAB[19:10];
// assign res[9:0] = 10'b0;
endmodule