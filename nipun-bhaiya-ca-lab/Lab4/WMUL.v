`include "../Lab4/PP.v"
`include "../Lab4/FA.v"
`include "../Lab4/CLA.v"

module WMUL(input [15:0]a, input [15:0]b, output [31:0]y);

wire overflow1,overflow2,cin;
assign cin=1'b0;
wire [31:0] p1,p2,p3,p4,p5,p6,p7,p8;
wire [31:0] p9,p10,p11,p12,p13,p14,p15,p16;

PP pp1(a,b,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16);

wire [31:0] h11,h21,h31,h41,h51,h61,h71,h81,h91,h101,h111,h121,h131,h141;
wire [31:0] h12,h22,h32,h42,h52,h62,h72,h82,h92,h102,h112,h122,h132,h142;

FA fa1(h11,h12,p1,p2,p3);
FA fa2(h21,h22,p4,p5,p6);
FA fa3(h31,h32,p7,p8,p9);
FA fa4(h41,h42,p10,p11,p12);
FA fa5(h51,h52,p13,p14,p15);
FA fa6(h61,h62,h11,h12,h21);
FA fa7(h71,h72,h22,h31,h32);
FA fa8(h81,h82,h41,h42,h51);
FA fa9(h91,h92,h61,h62,h71);
FA fa10(h101,h102,h72,h81,h82);
FA fa11(h111,h112,h91,h92,h101);
FA fa12(h121,h122,h102,h52,p16);
FA fa13(h131,h132,h111,h112,h121);
FA fa14(h141,h142,h131,h132,h122);

CLA cla1(h141,h142,overflow1,y);

endmodule