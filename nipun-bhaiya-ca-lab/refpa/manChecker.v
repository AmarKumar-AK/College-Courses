
module manChecker(input [15:0]a, input [15:0]b, output ManA_Big, output ManB_Big, output ManEqual);

wire [15:0] Man_A,Man_B;
wire tt1,tt2,tt3,tt4,tt5,tt6,tt7;
wire [15:0] ttemp1,ttemp2;


CLA c7({5'b0,1'b1,~b[9:0]},{15'b0,1'b1},tt1,Man_B,tt2);
assign Man_A = {6'b0,a[9:0]};
CLA c8(Man_A,Man_B,tt3,ttemp1,tt4);
CLA c9({15'b0,1'b1},{6'b0,~ttemp1[9:0]},tt6,ttemp2,tt7);
assign tt5 = ~(ttemp1[0]|ttemp1[1]|ttemp1[2]|ttemp1[3]|ttemp1[4]|ttemp1[5]|ttemp1[6]|ttemp1[7]|ttemp1[8]|ttemp1[9]);

assign ManA_Big = tt5 ? 0 : (ttemp1[10] ? 0 : 1);
assign ManB_Big = tt5 ? 0 : (ttemp1[10] ? 1 : 0);
assign ManEqual = tt5 ? 1 : 0;


//always @ (*) begin
//	$monitor("(%d) (%b)\n(%d) (%b)\n",a[9:0],ttemp1,b[9:0],ttemp2);
//end

endmodule