// `include "Main.v"

module top;

reg [31:0] a;
reg [31:0] b;
wire [31:0] sum;
wire overflow;

	RCA main_0(a,b,overflow,sum);

initial
begin
	a=32'b1000100000010001_0001000110001000;
	b=32'b0001000110001000_1000100000010001;
end

initial
begin
	$monitor("Time = %2d, a = %b, b = %b, overflow = %h, Sum = %b",$time,a,b,overflow,sum);
	$dumpfile("Adder.vcd");
	$dumpvars(0, top);
end

endmodule