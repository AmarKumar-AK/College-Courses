 `include "fullAdder16.v"
 `include "fullAdder8.v"
 `include "fullAdder4.v"
 `include "fullAdder.v"

module top;

reg [31:0]a, b;
reg cin;
wire [31:0]sum;
wire ca;

	fullAdder32 FA_0(a,b,cin,sum,ca);

initial
begin
	// a=32'b10101010101010101010101010101010; b=32'b10101010101010101010101010101010 ; cin=1'b0;
    // #5 a=32'b10101010101010101010101010101010; b=32'b10101010101010101010101010101010 ; cin=1'b1;
    // #5 a=32'b10111011101110111011101110111011; b=32'b10101010101010101010101010101010 ; cin=1'b0;
    // #5 a=32'b10111011101110111011101110111011; b=32'b10101010101010101010101010101010 ; cin=1'b1;
	a={$random}%42949; b={$random}%42949; cin=1'b0;
	#5 a={$random}%42949; b={$random}%42949; cin=1'b0;
	
end

initial
begin
	$monitor($time, " a = %d, b = %d, c = %b, Sum = %d, ca = %b",a,b,cin,sum, ca);
	$dumpfile("fullAdder32.vcd");
	$dumpvars;
end

endmodule
