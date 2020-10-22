`include "recursive_doubling/doub64.v"
module top;
reg [63:0]a, b;
reg cin;
wire [63:0]sum;
wire ca;
	doub64 d1(a,b,cin,sum,ca);
initial
begin
	#0 a=258; b=0 ; cin=0;
end
initial
begin
	$monitor("%d",sum);
end
endmodule