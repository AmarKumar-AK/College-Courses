`include "../Lab4/WMUL.v"
`include "../Lab4/Get_Exp.v"
`include "../Lab4/Get_Man.v"

module FPM(input [15:0]a, input [15:0]b, output [15:0]y);

wire [4:0] Bias;
assign Bias = 5'b10001;

wire ExpAZero,ExpBZero,ExpAOne,ExpBOne,Final_Sign,ManAZero,ManBZero,ManAOne,ManBOne;
wire InfA,InfB,NaNA,NaNB,ZeroA,ZeroB;
wire [4:0] Final_Exp;
wire [5:0] TempExp1,TempExp2;
wire [9:0] ManFinal;
wire [31:0] TempMan,TempMan1;

assign ExpAZero = a[14]|a[13]|a[12]|a[11]|a[10];
assign ExpBZero = b[14]|b[13]|b[12]|b[11]|b[10];
assign ExpAOne = a[14]&a[13]&a[12]&a[11]&a[10];
assign ExpBOne = b[14]&b[13]&b[12]&b[11]&b[10];
assign ManAZero = a[9]|a[8]|a[7]|a[6]|a[5]|a[4]|a[3]|a[2]|a[1]|a[0];
assign ManBZero = b[9]|b[8]|b[7]|b[6]|b[5]|b[4]|b[3]|b[2]|b[1]|b[0];
assign ManAOne = a[9]&a[8]&a[7]&a[6]&a[5]&a[4]&a[3]&a[2]&a[1]&a[0];
assign ManBOne = b[9]&b[8]&b[7]&b[6]&b[5]&b[4]|b[3]&b[2]&b[1]&b[0]; 
assign InfA = ExpAOne & ~ManAZero ;
assign InfB = ExpBOne & ~ManBZero ;
assign NaNA = ~InfA & ExpAOne;
assign NaNB = ~InfB & ExpBOne;
assign ZeroA = ~ExpAZero & ~ManAZero;
assign ZeroB = ~ExpBZero & ~ManBZero;


// Calculating Final Exponent
Get_Exp ge1(a,b,Bias,TempExp1,TempExp2);

// Calculating Mantisa
Get_Man gm1(a,b,ExpAZero,ExpBZero,TempMan);
	
// Calculating Final Sign
assign Final_Sign = a[15]^b[15];

// Checking Overflow in Exponent and Rounding off Mantisa
assign Final_Exp = (NaNA | NaNB) ? 5'h1f : ((InfA | InfB) ? 5'h1f : ((ZeroA | ZeroB) ? 5'b0 : (TempMan[21] ? (TempExp1[5] ? 5'h1f : TempExp1[4:0]) : (TempExp2[5] ? 5'h1f : TempExp2[4:0]))));
assign TempMan1 = (NaNA | NaNB) ? 32'hfffff : ((InfA | InfB) ? 32'b0 : ((ZeroA | ZeroB) ? 32'b0 : (TempMan[21] ? {TempMan[20:11],22'b0} : {TempMan[19:10],22'b0})));

assign ManFinal = TempMan1[31:22];

assign y = {Final_Sign,Final_Exp,ManFinal};

endmodule