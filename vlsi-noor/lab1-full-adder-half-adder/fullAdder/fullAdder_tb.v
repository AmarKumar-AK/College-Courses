// `include "fullAdder.v"

module top;

reg a, b, cin;
wire sum, ca;

	fullAdder HA_0(a,b,cin,sum,ca);

initial
begin
	a=0; b=0 ; cin=0;
	#10 a=0; b=0 ; cin=1;
	#10 a=0; b=1 ; cin=0;
	#10 a=0; b=1 ; cin=1;
	#10 a=1; b=0 ; cin=0;
	#10 a=1; b=0 ; cin=1;
	#10 a=1; b=1 ; cin=0;
	#10 a=1; b=1 ; cin=1;
end

initial
begin
	$monitor($time, " a = %d, b = %d, c = %d, Sum = %d, ca = %d",a,b,cin,sum, ca);
	$dumpfile("fullAdder.vcd");
	$dumpvars;
end

endmodule
