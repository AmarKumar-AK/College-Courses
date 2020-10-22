// `include "Main.v"

module top;

reg [15:0] a;
reg [15:0] b;
wire [15:0] sum;
wire overflow;

	RCA main_0(a,b,overflow,sum);

initial
begin
	a=16'h000a;
	b=16'h0003;
end

initial
begin
	$monitor("Time = %2d, a = %b, b = %b, overflow = %h, Sum = %h",$time,a,b,overflow,sum);
	$dumpfile("Adder.vcd");
	$dumpvars(0, top);
end

endmodule