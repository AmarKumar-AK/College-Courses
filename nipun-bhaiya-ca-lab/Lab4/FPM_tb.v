`include "../Lab4/Main.v"

module top;

reg [15:0] a;
reg [15:0] b;
wire [15:0]result;

	FPM main_0(a,b,result);

initial
begin
	a=`A;
	b=`B;
end

initial
begin
	$monitor("Time = %2d, a = %b, b = %b, Multiplication = %b",$time,a,b,result);
	$dumpfile("FloatingPointMult.vcd");
	$dumpvars(0, top);
end

endmodule