`include "fullAdder/fullAdder64.v"
`include "fullAdder/fullAdder32.v"
`include "fullAdder/fullAdder16.v"
`include "fullAdder/fullAdder8.v"
`include "fullAdder/fullAdder4.v"
`include "fullAdder/fullAdder.v"
module top;
reg [63:0]a, b;
reg cin;
wire [63:0]sum;
wire ca;
	fullAdder64 FA_0(a,b,cin,sum,ca);
initial
begin
	#0 a=1; b=11 ; cin=0;
end
initial
begin
	$monitor("%d",sum);
end
endmodule