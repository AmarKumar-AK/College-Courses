`include "../Wallace_tree_mult/Main.v"
// `ifndef IN
// `define A 20
// `define B 30
// `endif

module top;

reg [15:0] a;
reg [15:0] b;
wire [31:0] sum;

	WallaceTree main_0(.a(a),.b(b),.out(sum));

initial
begin
	a<=`A;
	b<=`B;
	#10
	$finish;
end

initial
begin
	$monitor("Time = %2d, a = %d, b = %d, Multiplication = %d",$time,a,b,sum);
	$dumpfile("Adder.vcd");
	$dumpvars(0, top);
end

endmodule