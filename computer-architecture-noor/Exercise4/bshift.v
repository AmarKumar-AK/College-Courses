//barrel shift
module bshift(a,select,direction,out);
input [15:0]a;
input [3:0]select;
input direction;
output [15:0]out;
reg [15:0]w3,w2,w1,w0;
always @(*)
begin
if(direction)
begin

    w3 <= select[0] ? {1'b0,a[15:1]} : a;
    w2 <= select[1] ? {2'b0,w3[15:2]} : w3;
    w1 <= select[2] ? {4'b0,w2[15:4]} : w2;
    w0 <= select[3] ? {8'b0,w1[15:8]} : w1;
end
else
begin
    w3 <= select[0] ? {a[14:0],1'b0} : a;
    w2 <= select[1] ? {w3[13:0],2'b0} : w3;
    w1 <= select[2] ? {w2[11:0],4'b0} : w2;
    w0 <= select[3] ? {w1[7:0],8'b0} : w1;
end
end
assign out = w0;
endmodule