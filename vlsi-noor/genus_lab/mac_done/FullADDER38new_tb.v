module top ;
reg [37:0]a ;
reg [37:0]b ;

wire [37:0]sum  ;
wire ca ;

FullAdder38new  Fu_1 (a,b,sum,ca);


initial
begin

a = 37'd0 ; b = 37'd1 ; #10;
a = 37'd120 ; b = 37'd1 ; #10;

a = 37'd4560 ; b = 37'd132 ; #10;
a = 37'd5609 ; b = 37'd1345 ; #10;


;end
initial

begin
$monitor("  a,b,sum,ca  %d , %d , %d , %d , ",a,b,sum,ca) ;
end

endmodule
