module top;
reg [7:0]a;
reg [7:0]b;
wire [15:0]result;

wallace W(a,b,result);

initial
begin
    // a=8'b00001000;   b=8'b00000001;
	a={$random}%256; b={$random}%256;
	#5 a={$random}%256; b={$random}%256;
	#5 a={$random}%256; b={$random}%256; 
	#5 a={$random}%256; b={$random}%256;
end

initial
begin
	$monitor($time, " a = %d, b = %d, result = %d",a,b,result);
	$dumpfile("wallace.vcd");
	$dumpvars;
end

endmodule