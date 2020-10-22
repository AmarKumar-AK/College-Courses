//-----------------------------------------------------
// Design Name : mux_using_assign
// File Name   : mux_using_assign.v
// Function    : 2:1 Mux using Assign
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module  mux_using_assign(
din_0      , // Mux first input
din_1      , // Mux Second input
sel        , // Select input
mux_out      // Mux output
);
//-----------Input Ports---------------
input din_0, din_1, sel ;
//-----------Output Ports---------------
output mux_out;
//------------Internal Variables--------
wire  mux_out;
//-------------Code Start-----------------
assign mux_out = (sel) ? din_1 : din_0;

endmodule //End Of Module mux



//-----------------------------------------------------
// Design Name : mux_using_if
// File Name   : mux_using_if.v
// Function    : 2:1 Mux using If
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module  mux_using_if(
din_0      , // Mux first input
din_1      , // Mux Second input
sel        , // Select input
mux_out      // Mux output
);
//-----------Input Ports---------------
input din_0, din_1, sel ;
//-----------Output Ports---------------
output mux_out;
//------------Internal Variables--------
reg  mux_out;
//-------------Code Starts Here---------
always @ (sel or din_0 or din_1)
begin : MUX
  if (sel == 1'b0) begin
      mux_out = din_0;
  end else begin
      mux_out = din_1 ;
  end
end

endmodule //End Of Module mux



//-----------------------------------------------------
// Design Name : mux_using_case
// File Name   : mux_using_case.v
// Function    : 2:1 Mux using Case
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module  mux_using_case(
din_0      , // Mux first input
din_1      , // Mux Second input
sel           , // Select input
mux_out   // Mux output
);
//-----------Input Ports---------------
input din_0, din_1, sel ;
//-----------Output Ports---------------
output mux_out;
//------------Internal Variables--------
reg  mux_out;
//-------------Code Starts Here---------
always @ (sel or din_0 or din_1)
begin : MUX
 case(sel ) 
    1'b0 : mux_out = din_0;
    1'b1 : mux_out = din_1;
 endcase 
end

endmodule //End Of Module mux




//-----------------------------------------------------
// Design Name : encoder_using_if
// File Name   : encoder_using_if.v
// Function    : Encoder using If
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module encoder_using_if(
binary_out , //  4 bit binary output
encoder_in , //  16-bit input
enable       //  Enable for the encoder
); 
//-----------Output Ports---------------
output [3:0] binary_out  ;
//-----------Input Ports---------------
input  enable ; 
input [15:0] encoder_in ; 
//------------Internal Variables--------
reg [3:0] binary_out ;  
//-------------Code Start-----------------
always @ (enable or encoder_in)
 begin 
   binary_out = 0; 
   if (enable) begin
     if (encoder_in == 16'h0002) begin
      binary_out = 1;
     end  if (encoder_in == 16'h0004) begin 
      binary_out = 2; 
     end  if (encoder_in == 16'h0008) begin 
      binary_out = 3; 
     end  if (encoder_in == 16'h0010) begin 
      binary_out = 4; 
     end  if (encoder_in == 16'h0020) begin 
      binary_out = 5; 
     end  if (encoder_in == 16'h0040) begin 
      binary_out = 6; 
     end  if (encoder_in == 16'h0080) begin 
      binary_out = 7; 
     end  if (encoder_in == 16'h0100) begin 
      binary_out = 8; 
     end  if (encoder_in == 16'h0200) begin 
      binary_out = 9; 
     end if (encoder_in == 16'h0400) begin 
      binary_out = 10; 
     end  if (encoder_in == 16'h0800) begin 
      binary_out = 11; 
     end  if (encoder_in == 16'h1000) begin
      binary_out = 12; 
     end  if (encoder_in == 16'h2000) begin 
      binary_out = 13;
     end  if (encoder_in == 16'h4000) begin 
      binary_out = 14; 
     end if (encoder_in == 16'h8000) begin 
      binary_out = 15; 
     end
  end
end
      
endmodule





//-----------------------------------------------------
// Design Name : encoder_using_case
// File Name   : encoder_using_case.v
// Function    : Encoder using Case
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module encoder_using_case(
binary_out , //  4 bit binary Output
encoder_in , //  16-bit Input
enable       //  Enable for the encoder
);
output [3:0] binary_out  ;
input  enable ; 
input [15:0] encoder_in ; 
     
reg [3:0] binary_out ;
      
always @ (enable or encoder_in)
begin
  binary_out = 0;
  if (enable) begin
    case (encoder_in) 
      16'h0002 : binary_out = 1; 
      16'h0004 : binary_out = 2; 
      16'h0008 : binary_out = 3; 
      16'h0010 : binary_out = 4;
      16'h0020 : binary_out = 5; 
      16'h0040 : binary_out = 6; 
      16'h0080 : binary_out = 7; 
      16'h0100 : binary_out = 8;
      16'h0200 : binary_out = 9;
      16'h0400 : binary_out = 10; 
      16'h0800 : binary_out = 11; 
      16'h1000 : binary_out = 12; 
      16'h2000 : binary_out = 13; 
      16'h4000 : binary_out = 14; 
      16'h8000 : binary_out = 15; 
   endcase
  end
end

endmodule




//-----------------------------------------------------
// Design Name : decoder_using_case
// File Name   : decoder_using_case.v
// Function    : decoder using case
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module decoder_using_case (
binary_in   , //  4 bit binary input
decoder_out , //  16-bit  out
enable        //  Enable for the decoder
);
input [3:0] binary_in  ;
input  enable ;
output [15:0] decoder_out ;

reg [15:0] decoder_out ;

always @ (enable or binary_in)
begin
  decoder_out = 0;
  if (enable) begin
    case (binary_in)
      4'h0 : decoder_out = 16'h0001;
      4'h1 : decoder_out = 16'h0002;
      4'h2 : decoder_out = 16'h0004;
      4'h3 : decoder_out = 16'h0008;
      4'h4 : decoder_out = 16'h0010;
      4'h5 : decoder_out = 16'h0020;
      4'h6 : decoder_out = 16'h0040;
      4'h7 : decoder_out = 16'h0080;
      4'h8 : decoder_out = 16'h0100;
      4'h9 : decoder_out = 16'h0200;
      4'hA : decoder_out = 16'h0400;
      4'hB : decoder_out = 16'h0800;
      4'hC : decoder_out = 16'h1000;
      4'hD : decoder_out = 16'h2000;
      4'hE : decoder_out = 16'h4000;
      4'hF : decoder_out = 16'h8000;
    endcase
  end
end

endmodule





//-----------------------------------------------------
// Design Name : decoder_using_assign
// File Name   : decoder_using_assign.v
// Function    : decoder using assign
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module decoder_using_assign (
binary_in   , //  4 bit binary input
decoder_out , //  16-bit out 
enable        //  Enable for the decoder
);
input [3:0] binary_in  ;
input  enable ; 
output [15:0] decoder_out ; 
        
wire [15:0] decoder_out ; 

assign decoder_out = (enable) ? (1 << binary_in) : 16'b0 ;

endmodule





//-----------------------------------------------------
// Design Name : up_counter
// File Name   : up_counter.v
// Function    : Up counter
// Coder     : Deepak
//-----------------------------------------------------
module up_counter    (
out     ,  // Output of the counter
enable  ,  // enable for counter
clk     ,  // clock Input
reset      // reset Input
);
//----------Output Ports--------------
    output [7:0] out;
//------------Input Ports--------------
     input enable, clk, reset;
//------------Internal Variables--------
    reg [7:0] out;
//-------------Code Starts Here-------
always @(posedge clk)
if (reset) begin
  out <= 8'b0 ;
end else if (enable) begin
  out <= out + 1;
end


endmodule 




//-----------------------------------------------------
// Design Name : half_adder_gates
// File Name   : half_adder_gates.v
// Function    : CCITT Serial CRC
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module half_adder_gates(x,y,sum,carry);
input x,y;
output sum,carry;

and U_carry (carry,x,y);
xor U_sum (sum,x,y);

endmodule







//-----------------------------------------------------
// Design Name : full_adder_gates
// File Name   : full_adder_gates.v
// Function    : Full Adder Using Gates
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module full_adder_gates(x,y,z,sum,carry);
input x,y,z;
output sum,carry;
wire and1,and2,and3,sum1;

and U_and1 (and1,x,y),
    U_and2 (and2,x,z),
    U_and3 (and3,y,z);
or  U_or   (carry,and1,and2,and3);
xor U_sum (sum,x,y,z);

endmodule







//-----------------------------------------------------
// Design Name : full_subtracter_gates
// File Name   : full_subtracter_gates.v
// Function    : Full Subtracter Using Gates
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module full_subtracter_gates(x,y,z,difference,borrow);
input x,y,z;
output difference,borrow;

wire inv_x,borrow1,borrow2,borrow3;

not (inv_x,x);
and U_borrow1 (borrow1,inv_x,y),
    U_borrow2 (borrow2,inv_x,z),
    U_borrow3 (borrow3,y,z);

xor U_diff (difference,borrow1,borrow2,borrows);

endmodule





//-----------------------------------------------------
// Design Name : mux_2to1_gates
// File Name   : mux_2to1_gates.v
// Function    : 2:1 Mux using Gate Primitives
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module mux_2to1_gates(a,b,sel,y);
input a,b,sel;
output y;

wire sel,a_sel,b_sel;

not U_inv (inv_sel,sel);
and U_anda (asel,a,inv_sel),
    U_andb (bsel,b,sel);
or U_or (y,asel,bsel);

endmodule



//-----------------------------------------------------
// Design Name : mux_4to1_gates
// File Name   : mux_4to1_gates.v
// Function    : 4:1 Mux Using Gates
// Coder       : Deepak Kumar Tala
//-----------------------------------------------------
module mux_4to1_gates(a,b,c,d,sel,y);
input a,b,c,d;
input [1:0] sel;
output y;

wire mux_1,mux_2;

mux_2to1_gates U_mux1 (a,b,sel[0],mux_1),
               U_mux2 (c,d,sel[0],mux_2),
               U_mux3 (mux_1,mux_2,sel[1],y);

endmodule