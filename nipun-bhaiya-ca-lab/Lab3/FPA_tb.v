`include "../Lab3/Main.v"
module top;

reg [15:0] a;
reg [15:0] b;
reg addOrSub;
wire [15:0]result;

	FPA main_0(a,b,addOrSub,result);

initial
begin
	a=`A;
	b=`B;
	addOrSub=`addOrSub;
end

initial
begin
	$monitor("Time = %2d, a = %b, b = %b, Sum = %b",$time,a,b,result);
	$dumpfile("FloatingPointAdder.vcd");
	$dumpvars(0, top);
end

endmodule