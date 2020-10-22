`include "subtracter/sub64.v"
module top;
reg [63:0]a, b;
reg cin;
wire [63:0]d;
wire br;
	sub64 S1(a,b,cin,d,br);
initial
begin
	#0 a=140.75; b=126 ; cin=0;
end
initial
begin
	$monitor("%d",d);
end
endmodule