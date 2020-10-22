`include "RCA4bit.v"
module RCA8bit(a,b,cin,sum,cout);

input [7:0] a;
input [7:0] b;
input cin;

	// Outputs
output [7:0] sum;
output cout;//temporary variable as wire

wire cout1;
// wire [3:0]
RCA4bit RA4_0(a[3:0],b[3:0],cin,sum[3:0],cout1);
RCA4bit RA4_1(a[7:4],b[7:4],cout1,sum[7:4],cout);

endmodule