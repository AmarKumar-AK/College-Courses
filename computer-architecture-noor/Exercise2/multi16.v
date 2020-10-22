///////////////////////////////////////////////////////
module HalfAdder (a,b,sum, ca);
input a, b;
output sum, ca;
	assign sum = a ^ b;
	assign ca  = a&b;
endmodule
///////////////////////////////////////////////////////
module fullAdder (a,b,cin,sum, ca);
input a, b, cin;
output sum, ca;
	assign sum = a ^ b ^ cin;
	assign ca  = (a & b) | (cin & a) | (cin & b);
endmodule
///////////////////////////////////////////////////////
module fullAdder4 (
    input [3:0]a,
    input [3:0]b,
    input cin,
    output [3:0]sum,
    output ca
);
    wire w0,w1,w2;

    fullAdder FA_0(a[0],b[0],cin,sum[0],w0);
    fullAdder FA_1(a[1],b[1],w0,sum[1],w1);
    fullAdder FA_2(a[2],b[2],w1,sum[2],w2);
    fullAdder FA_3(a[3],b[3],w2,sum[3],ca);

endmodule
///////////////////////////////////////////////////////
module fullAdder8 (
    input [7:0]a,
    input [7:0]b,
    input cin,
    output [7:0]sum,
    output ca
);
    wire w0;

    fullAdder4 FA_0(a[3:0],b[3:0],cin,sum[3:0],w0);
    fullAdder4 FA_1(a[7:4],b[7:4],w0,sum[7:4],ca);
endmodule
///////////////////////////////////////////////////////
module fullAdder16 (
    input [15:0]a,
    input [15:0]b,
    input cin,
    output [15:0]sum,
    output ca
);
    wire w0;

    fullAdder8 FA_0(a[7:0],b[7:0],cin,sum[7:0],w0);
    fullAdder8 FA_1(a[15:8],b[15:8],w0,sum[15:8],ca);

endmodule
///////////////////////////////////////////////////////
module fullAdder24 (
    input [23:0]a,
    input [23:0]b,
    input cin,
    output [23:0]sum,
    output ca
);
    wire w0;
    wire w1;

    fullAdder8 FA_0(a[7:0],b[7:0],cin,sum[7:0],w0);
    fullAdder8 FA_1(a[15:8],b[15:8],w0,sum[15:8],w1);
    fullAdder8 FA_2(a[23:16],b[23:16],w1,sum[23:16],ca);

endmodule
///////////////////////////////////////////////////////
module wallace(a,b,result);
input [7:0]a;
input [7:0]b;
output [15:0]result;

wire [7:0]r0,r1,r2,r3,r4,r5,r6,r7;
// a & b[0]
assign r0[0] = a[0] & b[0];
assign r0[1] = a[1] & b[0];
assign r0[2] = a[2] & b[0];
assign r0[3] = a[3] & b[0];
assign r0[4] = a[4] & b[0];
assign r0[5] = a[5] & b[0];
assign r0[6] = a[6] & b[0];
assign r0[7] = a[7] & b[0];
// a & b[1]
assign r1[0] = a[0] & b[1];
assign r1[1] = a[1] & b[1];
assign r1[2] = a[2] & b[1];
assign r1[3] = a[3] & b[1];
assign r1[4] = a[4] & b[1];
assign r1[5] = a[5] & b[1];
assign r1[6] = a[6] & b[1];
assign r1[7] = a[7] & b[1];
// a & b[2]
assign r2[0] = a[0] & b[2];
assign r2[1] = a[1] & b[2];
assign r2[2] = a[2] & b[2];
assign r2[3] = a[3] & b[2];
assign r2[4] = a[4] & b[2];
assign r2[5] = a[5] & b[2];
assign r2[6] = a[6] & b[2];
assign r2[7] = a[7] & b[2];
// a & b[3]
assign r3[0] = a[0] & b[3];
assign r3[1] = a[1] & b[3];
assign r3[2] = a[2] & b[3];
assign r3[3] = a[3] & b[3];
assign r3[4] = a[4] & b[3];
assign r3[5] = a[5] & b[3];
assign r3[6] = a[6] & b[3];
assign r3[7] = a[7] & b[3];
// a & b[4]
assign r4[0] = a[0] & b[4];
assign r4[1] = a[1] & b[4];
assign r4[2] = a[2] & b[4];
assign r4[3] = a[3] & b[4];
assign r4[4] = a[4] & b[4];
assign r4[5] = a[5] & b[4];
assign r4[6] = a[6] & b[4];
assign r4[7] = a[7] & b[4];
// a & b[5]
assign r5[0] = a[0] & b[5];
assign r5[1] = a[1] & b[5];
assign r5[2] = a[2] & b[5];
assign r5[3] = a[3] & b[5];
assign r5[4] = a[4] & b[5];
assign r5[5] = a[5] & b[5];
assign r5[6] = a[6] & b[5];
assign r5[7] = a[7] & b[5];
// a & b[6]
assign r6[0] = a[0] & b[6];
assign r6[1] = a[1] & b[6];
assign r6[2] = a[2] & b[6];
assign r6[3] = a[3] & b[6];
assign r6[4] = a[4] & b[6];
assign r6[5] = a[5] & b[6];
assign r6[6] = a[6] & b[6];
assign r6[7] = a[7] & b[6];
// a & b[7]
assign r7[0] = a[0] & b[7];
assign r7[1] = a[1] & b[7];
assign r7[2] = a[2] & b[7];
assign r7[3] = a[3] & b[7];
assign r7[4] = a[4] & b[7];
assign r7[5] = a[5] & b[7];
assign r7[6] = a[6] & b[7];
assign r7[7] = a[7] & b[7];

//iteration-1
wire [9:0]t0;
wire [7:0]c0;
assign t0[0]=r0[0];
HalfAdder h0(r0[1],r1[0],t0[1],c0[0]);

fullAdder f0(r0[2],r1[1],r2[0],t0[2],c0[1]);
fullAdder f1(r0[3],r1[2],r2[1],t0[3],c0[2]);
fullAdder f2(r0[4],r1[3],r2[2],t0[4],c0[3]);
fullAdder f3(r0[5],r1[4],r2[3],t0[5],c0[4]);
fullAdder f4(r0[6],r1[5],r2[4],t0[6],c0[5]);
fullAdder f5(r0[7],r1[6],r2[5],t0[7],c0[6]);

HalfAdder h1(r1[7],r2[6],t0[8],c0[7]);
assign t0[9]=r2[7];


wire [9:0]t1;
wire [7:0]c1;
assign t1[0]=r3[0];
HalfAdder h2(r3[1], r4[0],t1[1],c1[0]);

fullAdder f6(r3[2], r4[1],r5[0],t1[2],c1[1]);
fullAdder f7(r3[3], r4[2],r5[1],t1[3],c1[2]);
fullAdder f8(r3[4], r4[3],r5[2],t1[4],c1[3]);
fullAdder f9(r3[5], r4[4],r5[3],t1[5],c1[4]);
fullAdder f10(r3[6],r4[5],r5[4],t1[6],c1[5]);
fullAdder f11(r3[7],r4[6],r5[5],t1[7],c1[6]);

HalfAdder h3(r4[7],r5[6],t1[8],c1[7]);
assign t1[9]=r5[7];


//iteration-2
wire [12:0]t2;
wire [7:0]c2;
assign t2[0]=t0[0];
assign t2[1]=t0[1];
HalfAdder h4(t0[2],c0[0],t2[2],c2[0]);

fullAdder f12(t0[3],c0[1],t1[0],t2[3],c2[1]);
fullAdder f13(t0[4],c0[2],t1[1],t2[4],c2[2]);
fullAdder f14(t0[5],c0[3],t1[2],t2[5],c2[3]);
fullAdder f15(t0[6],c0[4],t1[3],t2[6],c2[4]);
fullAdder f16(t0[7],c0[5],t1[4],t2[7],c2[5]);
fullAdder f17(t0[8],c0[6],t1[5],t2[8],c2[6]);
fullAdder f18(t0[9],c0[7],t1[6],t2[9],c2[7]);

assign t2[10]=t1[7];
assign t2[11]=t1[8];
assign t2[12]=t1[9];
///////////////////////

wire [9:0]t3;
wire [7:0]c3;
assign t3[0]=c1[0];
HalfAdder h5(c1[1],r6[0],t3[1],c3[0]);

fullAdder f19(c1[2],r6[1],r7[0],t3[2],c3[1]);
fullAdder f20(c1[3],r6[2],r7[1],t3[3],c3[2]);
fullAdder f21(c1[4],r6[3],r7[2],t3[4],c3[3]);
fullAdder f22(c1[5],r6[4],r7[3],t3[5],c3[4]);
fullAdder f23(c1[6],r6[5],r7[4],t3[6],c3[5]);
fullAdder f24(c1[7],r6[6],r7[5],t3[7],c3[6]);

HalfAdder h14(r6[7],r7[6],t3[8],c3[7]);
assign t3[9]=r7[7];


//iteration-3
wire [14:0]t4;
wire [9:0]c4;
assign t4[0]=t2[0];
assign t4[1]=t2[1];
assign t4[2]=t2[2];
HalfAdder h6(t2[3],c2[0],t4[3],c4[0]);
HalfAdder h7(t2[4],c2[1],t4[4],c4[1]);

fullAdder f25(t2[5],c2[2],t3[0],t4[5],c4[2]);
fullAdder f26(t2[6],c2[3],t3[1],t4[6],c4[3]);
fullAdder f27(t2[7],c2[4],t3[2],t4[7],c4[4]);
fullAdder f28(t2[8],c2[5],t3[3],t4[8],c4[5]);
fullAdder f29(t2[9],c2[6],t3[4],t4[9],c4[6]);
fullAdder f30(t2[10],c2[7],t3[5],t4[10],c4[7]);

HalfAdder h8(t2[11],t3[6],t4[11],c4[8]);//
HalfAdder h9(t2[12],t3[7],t4[12],c4[9]);
assign t4[13]=t3[8];
assign t4[14]=t3[9];


//iteration-4
wire [14:0]t5;
wire [10:0]c5;
assign t5[0]=t4[0];
assign t5[1]=t4[1];
assign t5[2]=t4[2];
assign t5[3]=t4[3];
HalfAdder h10(t4[4],c4[0],t5[4],c5[0]);
HalfAdder h11(t4[5],c4[1],t5[5],c5[1]);
HalfAdder h12(t4[6],c4[2],t5[6],c5[2]);

fullAdder f31(t4[7],c4[3],c3[0],t5[7],c5[3]);
fullAdder f32(t4[8],c4[4],c3[1],t5[8],c5[4]);
fullAdder f33(t4[9],c4[5],c3[2],t5[9],c5[5]);
fullAdder f34(t4[10],c4[6],c3[3],t5[10],c5[6]);
fullAdder f35(t4[11],c4[7],c3[4],t5[11],c5[7]);
fullAdder f36(t4[12],c4[8],c3[5],t5[12],c5[8]);
fullAdder f37(t4[13],c4[9],c3[6],t5[13],c5[9]);

HalfAdder h15(t4[14],c3[7],t5[14],c5[10]);


//last iteration
wire [10:0]car;
assign result[0]=t5[0];
assign result[1]=t5[1];
assign result[2]=t5[2];
assign result[3]=t5[3];
assign result[4]=t5[4];

fullAdder f38(t5[5],c5[0],1'b0,result[5],car[0]);
fullAdder f39(t5[6],c5[1],car[0],result[6],car[1]);
fullAdder f40(t5[7],c5[2],car[1],result[7],car[2]);
fullAdder f41(t5[8],c5[3],car[2],result[8],car[3]);
fullAdder f42(t5[9],c5[4],car[3],result[9],car[4]);
fullAdder f43(t5[10],c5[5],car[4],result[10],car[5]);
fullAdder f44(t5[11],c5[6],car[5],result[11],car[6]);
fullAdder f45(t5[12],c5[7],car[6],result[12],car[7]);
fullAdder f46(t5[13],c5[8],car[7],result[13],car[8]);
fullAdder f47(t5[14],c5[9],car[8],result[14],car[9]);

HalfAdder h13(c5[10],car[9],result[15],car[10]);
// assign result[15]=car[10];

endmodule
///////////////////////////////////////////////////////
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