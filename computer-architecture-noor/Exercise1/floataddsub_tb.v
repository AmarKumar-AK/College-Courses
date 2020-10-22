`include "floataddsub.v"
 
 module top;
 
reg [15:0]a,b; 
reg cin;
wire [15:0]c;

FloatingPointAddSub FPA(a,b,cin,c);

initial
begin
	 #0 a=16'b0100110100011101; b=16'b0101101100110010; cin=1'b0;
end
endmodule
