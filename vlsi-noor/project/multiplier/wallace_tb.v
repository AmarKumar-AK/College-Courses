module top;
reg [7:0]a;
reg [7:0]b;
wire [15:0]result;

wallace W(a,b,result);

initial
begin
	#0 a=0; b=0;
end

initial
begin
	$monitor("%d",result);
end

endmodule