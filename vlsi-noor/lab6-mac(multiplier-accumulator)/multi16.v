// `include "HalfAdder.v"
// `include "fullAdder.v"
`include "fullAdder4.v"
`include "fullAdder8.v"
`include "fullAdder16.v"
`include "fullAdder24.v"
`include "wallace.v"
module multi16(a,b,c);
input [15:0]a;
input [15:0]b;
output [31:0]c;

wire [15:0]q0,q1,q2,q3,q4,temp1;	
wire [31:0]c;
wire [23:0]temp2,temp3,temp4,q5,q6;
// using 4 8x8 wallace multipliers to build 16x16 multiplier
wallace z1(a[7:0],b[7:0],q0[15:0]);
wallace z2(a[15:8],b[7:0],q1[15:0]);
wallace z3(a[7:0],b[15:8],q2[15:0]);
wallace z4(a[15:8],b[15:8],q3[15:0]);
wire ca1,ca2,ca3;
// stage 1 adders 
assign temp1 ={8'b0,q0[15:8]};
fullAdder16 z5(q1[15:0],temp1,1'b0,q4,ca1);
assign temp2 ={8'b0,q2[15:0]};
assign temp3 ={q3[15:0],8'b0};
fullAdder24 z6(temp2,temp3,1'b0,q5,ca2);
assign temp4={8'b0,q4[15:0]};

//stage 2 adder
fullAdder24 z7(temp4,q5,1'b0,q6,ca3);
// fnal output assignment 
assign c[7:0]=q0[7:0];
assign c[31:8]=q6[23:0];


endmodule