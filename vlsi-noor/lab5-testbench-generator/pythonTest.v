//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:31:28 03/28/2017 
// Design Name: 
// Module Name:    mac 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////

module pythonTest1(a1,a2,	//set1
b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,
c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,
d0,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,
e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,
f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,
g0,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,
a, b, c,d,
x1,x2,x3,x4,
p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,
q0,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,
r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,
s0,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,
x,y,p,q
);

input a1,a2;
input b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10, //set2
c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10, //set2
d0,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10; //set3
input e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10; //set4
input f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10, 
g0,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10;
input [30:0] a,		//in1
			 b;
input [15:0] c,d;
output x1,x2,x3,x4;	//set1
output p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
output q0,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10, //set2
r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,
s0,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
output [32:0] x,		// out1
			  y;
output [16:0] p, q;

wire e,f;
wire [4:0] g,
    h;

assign x1 = (a1^a2);
assign x2 = (a1|a2);

assign {x3,x4,p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,
q0,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,
r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,
s0,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10
} = a*{b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,a1,a2};

assign x = {e,f,b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,d0,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10} + {a2,a1,e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,g0,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10};

assign e = ~a1;
assign f = a1|a2;
assign g = {b10,c0,c1,c2};
assign h = {a1,e0,e1,e2};
assign y = (c*d)+g+h;
assign p = c+d;
assign q=c-d;

endmodule



