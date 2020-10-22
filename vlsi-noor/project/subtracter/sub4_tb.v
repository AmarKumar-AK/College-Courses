`include "subtracter/sub4.v"
module top;
reg [3:0]a,b;
reg c;
wire [3:0]d;
wire br;

sub4 S1(a,b,c,d,br);

initial
begin
	#0 a=15; b=2 ; c=0;
end
initial
begin
	$monitor("%d",d);
end
endmodule