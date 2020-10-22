 `include "fullAdder8.v"
 `include "fullAdder4.v"
 `include "fullAdder.v"

module top;

reg [15:0]a, b;
reg cin;
wire [15:0]sum;
wire ca;

	fullAdder16 FA_0(a,b,cin,sum,ca);

initial
begin
	// a=16'b1010101010101010; b=16'b1010101010101010 ; cin=1'b0;
    // #5 a=16'b1010101010101010; b=16'b1010101010101010 ; cin=1'b1;
    // #5 a=16'b1011101110111011; b=16'b1010101010101010 ; cin=1'b0;
    // #5 a=16'b1011101110111011; b=16'b1010101010101010 ; cin=1'b1;
	a={$random}%65536; b={$random}%65536; cin=1'b0;
	#5 a={$random}%65536; b={$random}%65536; cin=1'b0;
end

initial
begin
	$monitor($time, " a = %d, b = %d, c = %b, Sum = %d, ca = %b",a,b,cin,sum, ca);
	$dumpfile("fullAdder16.vcd");
	$dumpvars;
end

endmodule
