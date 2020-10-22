`include "AND.v"
`include "EXOR.v"
`include "KGP.v"
`include "RDM.v"


module CLA(input [15:0]a, input [15:0]b, input cin, output [15:0]y, output cout);

wire [16:0] kgp1,kgp2;
wire [15:0] kgp;

KGP k1(kgp1,kgp2,a,b);

assign kgp1[0]=1'b0; // It's cin!!!
assign kgp2[0]=1'b0;

RDM r1(kgp1,kgp2,kgp);
EXOR e1(y,a,b,kgp);
AND a1(cout,a,b,kgp);

endmodule
