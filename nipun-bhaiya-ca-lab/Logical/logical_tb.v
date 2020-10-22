`include "../Logical/Main.v"

module top;

reg [15:0] a;
reg [15:0] b;
reg select;
wire [15:0] out;

	LogicalUnit main_0(a,b,select,out);

initial
begin
	a=`A;
	b=`B;
	select=`select;
end

initial
begin
	$monitor("Time = %2d, a = %d, b = %d, output = %d",$time,a,b,out);
	$dumpfile("Adder.vcd");
	$dumpvars(0, top);
end

endmodule