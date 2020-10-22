`include "multiplier/multi16.v"
module top;
reg [15:0]a, b;
wire [31:0]mul;
	multi16 FA_0(a,b,mul);
initial
begin
	#0 a=0.33900928792569657; b=-9 ;
end
initial
begin
	$monitor("%d",mul);
end
endmodule