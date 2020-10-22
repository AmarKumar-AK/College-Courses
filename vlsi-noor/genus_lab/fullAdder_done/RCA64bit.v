`include "RCA16bit.v"
module RCA64bit(a,b,cin,sum,cout);

input [63:0] a;
input [63:0] b;
input cin;

	// Outputs
output [63:0] sum;
output cout;//temporary variable as wire

wire cout1,cout2,cout3;
RCA16bit RA16_0(a[15:0],b[15:0],cin,sum[15:0],cout1);
RCA16bit RA16_1(a[31:16],b[31:16],cout1,sum[31:16],cout2);
RCA16bit RA16_2(a[47:32],b[47:32],cout2,sum[47:32],cout3);
RCA16bit RA16_3(a[63:48],b[63:48],cout3,sum[63:48],cout);
endmodule