`include "rclas.v"

module top;

reg [16:1] a, b;
reg cin;
wire [16:1] sum;
wire carry;

RCLAA RC_0(a, b, cin, sum, carry);

initial
begin
	/*
	#0 a=$urandom%5000; b=$urandom%5000; cin=$urandom%2;
	#10 a=$urandom%5000; b=$urandom%5000; cin=$urandom%2;
	#10 a=$urandom%5000; b=$urandom%5000; cin=$urandom%2;
	#10 a=$urandom%5000; b=$urandom%5000; cin=$urandom%2;
	#10 a=$urandom%5000; b=$urandom%5000; cin=$urandom%2;
	#10 a=$urandom%5000; b=$urandom%5000; cin=$urandom%2;
	*/
	#0 a=16'd0; b=16'b1111111111111110; cin=1;

end

initial
begin
	$monitor($time, " a=%b, b=%b, cin=%d, sum=%b, carry=%d\n", a, b, cin, sum, carry);	

end

endmodule
