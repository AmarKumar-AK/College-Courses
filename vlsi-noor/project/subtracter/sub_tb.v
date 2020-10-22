`include "subtracter/sub.v"
module top;
reg a,b,c;
wire d,br;

sub1 S1(a,b,c,d,br);

initial
begin
	#0 a=0; b=1 ; c=0;
end
initial
begin
	$monitor("%d",d);
end
endmodule