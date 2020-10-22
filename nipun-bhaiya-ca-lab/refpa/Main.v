`include "expChecker.v"
`include "manChecker.v"
`include "expManZeroOne.v"
`include "CLA.v"
`include "mantissaCompute.v"
`include "LeadingZero.v"

module FPA(input [15:0]a, input [15:0]b, input addOrSub, output [15:0]result);

wire isExpAZero,isExpBZero,isExpAOne,isExpBOne,finalSign,checkSubtraction,isManAZero,isManBZero,isManAOne,isManBOne;
wire manAIsBig,manBIsBig,manEqual;
wire [4:0] expDiff,finalExp,tempExp;
wire [10:0] tempMan,finalMan,tempMan2;
wire [15:0] bigMan,smallMan,tempMan1;
wire expAIsBig,expBIsBig,expEqual;

// Checking Which Exponent is Bigger
expChecker EX1(a,b,expAIsBig,expBIsBig,expEqual,tempExp,expDiff);
manChecker MAN1(a,b,manAIsBig,manBIsBig,manEqual);
expManZeroOne EXMA01(a,b,isExpAZero,isExpBZero,isExpAOne,isExpBOne,isManAZero,isManBZero,isManAOne,isManBOne);

// Normal Case Classification
assign finalSign = addOrSub ? (expEqual ? (manAIsBig ? a[15] : ~b[15]) : (expAIsBig ? a[15] : ~b[15])) : (expEqual ? (manAIsBig ? a[15] : b[15]) : (expAIsBig ? a[15] : b[15]));
assign checkSubtraction = a[15]^b[15]^addOrSub;	

// Edge Case Classification
// Exp - 1 & Man != 0 NaN  
// Exp - 1 & Man - 0  Infinity
// Exp - 0 & Man - 0  Zero

// Mantisa Related Calculation

assign bigMan = expEqual ? (manAIsBig ? {5'b0,isExpAZero,a[9:0]} : {5'b0,isExpBZero,b[9:0]}) : (expAIsBig ? {5'b0,isExpAZero,a[9:0]} : {5'b0,isExpBZero,b[9:0]});
assign tempMan = expEqual ? (manAIsBig ? {isExpBZero,b[9:0]} : {isExpAZero,a[9:0]}) : (expAIsBig ? {isExpBZero,b[9:0]} : {isExpAZero,a[9:0]});

wire [10:0] bs1,bs2,bs3,bs4;
assign bs1 = expDiff[0] ? {1'b0,tempMan[10:1]} : tempMan; 
assign bs2 = expDiff[1] ? {2'b0,bs1[10:2]} : bs1;
assign bs3 = expDiff[2] ? {4'b0,bs2[10:4]} : bs2;	
assign bs4 = expDiff[3] ? {8'b0,bs3[10:8]} : bs3;
assign smallMan = expDiff[4] ? {11'b0} : bs4;

// Computing and Getting Final Value

computeMantissa CM1(bigMan,smallMan,tempMan1,checkSubtraction);
detectingLeadingZero LZD1(tempMan1,tempMan2);


assign finalMan = (isExpAOne | isExpBOne) ? ((isManAZero & isManBZero) ? 11'h7ff : 11'b0) : ((isExpAZero | isExpBZero) ? ((isManAZero & isManBZero) ? tempMan2 : 11'b0) : tempMan2);
assign finalExp = (isExpAOne | isExpBOne) ? 5'h1f : ((isExpAZero & isExpBZero) ? tempExp : 5'b0);

assign result = {finalSign,finalExp,finalMan[10:1]};

endmodule