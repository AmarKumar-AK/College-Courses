`include "recursive_doubling/doub.v"

module top;

reg [15:0]x;
reg [15:0]y;
reg cin;
wire [15:0]sum;
wire ca;

doub CLA(x,y,cin,sum,ca);

initial
    begin
    #0 x={$random}%10051;     y={$random}%10460;     cin=1'd0;

    end

initial
begin
	$monitor($time, " x = %d, y = %d, cin = %b ,sum=%d",x,y,cin,sum);
end

endmodule