
module detectingLeadingZero(input [15:0]t1, output [10:0]tt2);

wire [15:0] check_zero,arr;
wire [15:0] dz1,dz2,dz3,dz4,dz5,dz6,dz7,dz8,dz9,dz10,dz11,dz12,dz13,dz14,dz15,dz16;
assign check_zero[15] = t1[15];

genvar i;
generate
	for(i=14;i>=0;i=i-1) begin
		assign check_zero[i] = (check_zero[i+1] | t1[i]);
	end
endgenerate

assign dz1 = check_zero[15] ? t1 : {t1[14:0],1'b0};  
assign dz2 = check_zero[14] ? dz1 : {dz1[14:0],1'b0};
assign dz3 = check_zero[13] ? dz2 : {dz2[14:0],1'b0};
assign dz4 = check_zero[12] ? dz3 : {dz3[14:0],1'b0};
assign dz5 = check_zero[11] ? dz4 : {dz4[14:0],1'b0};
assign dz6 = check_zero[10] ? dz5 : {dz5[14:0],1'b0};
assign dz7 = check_zero[9] ? dz6 : {dz6[14:0],1'b0};
assign dz8 = check_zero[8] ? dz7 : {dz7[14:0],1'b0};
assign dz9 = check_zero[7] ? dz8 : {dz8[14:0],1'b0};
assign dz10 = check_zero[6] ? dz9 : {dz9[14:0],1'b0};
assign dz11 = check_zero[5] ? dz10 : {dz10[14:0],1'b0};
assign dz12 = check_zero[4] ? dz11 : {dz11[14:0],1'b0};
assign dz13 = check_zero[3] ? dz12 : {dz12[14:0],1'b0};
assign dz14 = check_zero[2] ? dz13 : {dz13[14:0],1'b0};
assign dz15 = check_zero[1] ? dz14 : {dz14[14:0],1'b0};
assign dz16 = check_zero[0] ? dz15 : {dz15[14:0],1'b0};

assign tt2 = dz16[15:4];

endmodule