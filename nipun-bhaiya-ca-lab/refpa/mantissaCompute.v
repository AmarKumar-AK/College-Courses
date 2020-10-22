
module computeMantissa(input [15:0]M_Big, input [15:0]M_Small, output [15:0]M_Final, input Case);


wire cc1,cc2,cc3,cc4,cc5,cc6;
wire [15:0] t_b,t_s;
wire [15:0] tp1,tp2,tp3;

CLA c4({4'b0,1'b1,~M_Big[10:0]},{15'b0,1'b1},cc1,tp1,cc2);

assign t_b = Case ? tp1 : M_Big;
assign t_s = M_Small;

CLA c5(t_b,t_s,cc3,tp2,cc4);
CLA c6({15'b0,1'b1},{5'b0,~tp2[10:0]},cc5,tp3,cc6);

assign M_Final = Case ? {5'b0,tp3[10:0]} : {5'b0,tp2[10:0]};

endmodule