 `include "fullAdder4.v"
 `include "fullAdder.v"

module top;

reg [7:0]a, b;
reg cin;
wire [7:0]sum;
wire ca;

	fullAdder8 FA_0(a,b,cin,sum,ca);

initial
begin
	// a=8'b10101010; b=8'b10101010 ; cin=1'b0;
    // #5 a=8'b10101010; b=8'b10101010 ; cin=1'b1;
    // #5 a=8'b10111011; b=8'b10101010 ; cin=1'b0;
    // #5 a=8'b10111011; b=8'b10101010 ; cin=1'b1;
	a={$random}%256; b={$random}%256; cin=1'b0;
	#5 a={$random}%256; b={$random}%256; cin=1'b0;
	
end

initial
begin
	$monitor($time, " a = %d, b = %d, c = %b, Sum = %d, ca = %b",a,b,cin,sum, ca);
	$dumpfile("fullAdder8.vcd");
	$dumpvars;
end

endmodule
