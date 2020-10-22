`include "Wallaccorrected.v"


module wall16bit (a,b,asn);
input [15:0] a;
input [15:0] b;
output [31:0] asn;


//ml = [7:0]a  mh = [15:8]a
//nl = [7:0]b  nh = [15:8]b


wire [15:0] in1,tmp1,tmp2,tmp3,tmp4;
wire [23:0] in2,in3;
wire [31:0] in4;
//in1 for first product
//





wallace w1(a[7:0],b[7:0],tmp1);//ml nl
wallace w2(a[7:0],b[15:8],tmp2);//ml nh
wallace w3(a[15:8],b[7:0],tmp3);//mh nl
wallace w4(a[15:8],b[15:8],tmp4);// mh nh



assign in1 = tmp1;
assign in2 = tmp2<<8;
assign in3 = tmp3<<8;
assign in4 = tmp4<<16;

// assign in1 = a;
// assign in2 = tmp2<<8;
// assign in3 = tmp3<<8;
// assign in4 = tmp4<<16;
//
//
//
//
// wallace w1([7:0]a,[7:0]b,tmp1);//ml nl
// wallace w2([7:0]a,[15:8]b,tmp2);//ml nh
// wallace w3([15:8]a,[7:0]b,tmp3);//mh nl
// wallace w4([15:8]a,[15:8]b,tmp4);// mh nh

assign asn = in1+in2+in3+in4;

endmodule
