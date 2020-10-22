`include"arrmul.v"
module top;
reg [3:0]a,b;
wire [7:0]p;

arrmul AM1(a,b,p);

initial
begin
    a=4'b0101; b=4'b1010;
end

initial
begin
    $monitor($time ,"  a=%d , b=%d , mul=%d ",a, b, p);
    $dumpfile("arrmul.vcd");
	$dumpvars;
end

endmodule