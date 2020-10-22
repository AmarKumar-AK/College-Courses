module dflip38flop (d,clk,reset,q);

  input clk,reset;
  input [37:0] d;
  output [37:0] q;
  reg [37:0] q;

  always @ (posedge clk or posedge reset)
    if(reset)
      q<=38'b0 ;
    else
      q<=d;

  // end



endmodule // dflip38flop
