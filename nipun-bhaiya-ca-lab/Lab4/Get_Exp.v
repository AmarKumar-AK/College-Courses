module Get_Exp(input [15:0]a, input[15:0]b, input [4:0]bias, output [5:0] T_Exp1, output [5:0] T_Exp2);

wire t1,t2,t3,t4;
wire [31:0] temp1,temp2,temp3,temp4;

CLA c1({27'b0,a[14:10]},{27'b0,b[14:10]},t1,temp1);
CLA c2(temp1,{27'b1,bias},t2,temp2);
CLA c3(~temp2,{32'b1},t3,temp3);					// Remove bitwise Not to get +1 value in temp3 or keeping it same will give -1 value in temp4 
CLA c4({26'b0,~temp3[5:0]},{31'b0,1'b0},t4,temp4);

assign T_Exp1 = temp2[5] ? 6'h2f : temp2[5:0];  
assign T_Exp2 = temp4[5] ? 6'h2f : temp4[5:0];

endmodule