`include "RCA8bit.v"
module RCA16bit(a,b,cin,sum,cout);

input [15:0] a;
input [15:0] b;
input cin;

	// Outputs
output [15:0] sum;
output cout;//temporary variable as wire

wire cout1;
RCA8bit RA4_0(a[7:0],b[7:0],cin,sum[7:0],cout1);
RCA8bit RA4_1(a[15:8],b[15:8],cout1,sum[15:8],cout);

endmodule