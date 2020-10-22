`include "full_add.v"
module RCA4bit(a,b,cin,sum,cout);

input [3:0] a;
input [3:0] b;
input cin;

// reg cout,cout2;//temporary variable as wire
// output  tmp;
	// Outputs
output [3:0] sum;

output cout;

// full_Adder FA_0(a,b,cin,sum,cout);
wire cout1,cout2,cout3;//temporary variable as wire
full_Adder FA_0(a[0],b[0],cin,sum[0],cout1);
full_Adder FA_1(a[1],b[1],cout1,sum[1],cout2);
full_Adder FA_2(a[2],b[2],cout2,sum[2],cout3);
full_Adder FA_3(a[3],b[3],cout3,sum[3],cout);
// full_Adder(a[0],b[0],cin,sum[0],cout[0]);
endmodule