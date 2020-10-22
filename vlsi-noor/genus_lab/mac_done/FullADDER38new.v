module FullAdder38new (a,b,sum,ca);
input [37:0]a;
input [37:0]b;
output [37:0]sum ;
output ca;


assign {ca,sum} = a+b;



endmodule // FullAdder38new
