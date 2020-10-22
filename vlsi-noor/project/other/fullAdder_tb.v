`include "fullAdder.v"

module top;

reg a, b, cin;
wire sum, ca;

	fullAdder FA_0(a,b,cin,sum,ca);

initial
begin
	#0 a=0; b=0 ; cin=0;
	
end

initial
begin
	$monitor("%d",sum);
end

endmodule
