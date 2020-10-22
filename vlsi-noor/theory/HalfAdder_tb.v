`include "HalfAdder.v"

module top;

reg a, b;
wire sum, ca;

	HalfAdder HA_0(a,b,sum,ca);

initial
begin
	a=0;
	#10 b=0;
	#10 a=1;
	#10 b=1;
end

initial
begin
	$monitor($time, "a = %b, b = %b, Sum = %b, ca = %b",a,b,sum, ca);
	$dumpfile("HalfAdder.vcd");
	$dumpvars;
end

endmodule