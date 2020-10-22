

module expChecker(input [15:0]a, input [15:0]b, output aBig, output bBig, output bothEqual, output [4:0]final, output [4:0]diff);

wire [15:0] expA,expB;
wire t1,t2,t3,t4,t5,t6,t7;
wire [15:0] temp1,temp2;

CLA c1({10'b0,1'b1,~b[14:10]},{15'b0,1'b1},t1,expB,t2);
assign expA = {11'b0,a[14:10]};
CLA c2(expA,expB,t3,temp1,t4);
CLA c3({15'b0,1'b1},{11'b0,~temp1[4:0]},t6,temp2,t7);
assign t5 = ~(temp1[0]|temp1[1]|temp1[2]|temp1[3]|temp1[4]);

assign aBig = t5 ? 0 : (temp1[5] ? 0 : 1);
assign bBig = t5 ? 0 : (temp1[5] ? 1 : 0);
assign bothEqual =t5 ? 1 : 0;

assign diff = bothEqual ? (5'b0) : (aBig ? temp1[4:0] : temp2[4:0]); 
assign final= bothEqual ? (a[14:10]) : (aBig ? a[14:10] : b[14:10]);

//always @ (*) begin
//	$monitor("(%b)\n(%b)\naBig = (%b) (%b)\nbBig = (%b) (%b)\nIs_Equal = (%b)\nDiff = (%b)\nExp_Final = (%b)\n",expA,expB,aBig,a[14:10],bBig,b[14:10],bothEqual,diff,final);
//end

endmodule