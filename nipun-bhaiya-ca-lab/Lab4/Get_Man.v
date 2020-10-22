
module Get_Man(input [15:0]a, input [15:0]b, input ia, input ib, output [31:0] ManVal);

wire [31:0] temp4;

WMUL w1({5'b0,ia,a[9:0]},{5'b0,ib,b[9:0]},temp4);
assign ManVal = temp4;

endmodule