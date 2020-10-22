module FA(output [31:0]t1, output [31:0]t2, input [31:0]i1, input [31:0]i2, input [31:0]i3);

wire [31:0] temp;

assign t1=i1 ^ i2 ^ i3;
assign temp=((i1 & i2) | (i1 & i3) | (i2 & i3));

assign t2={temp,1'b0};
endmodule