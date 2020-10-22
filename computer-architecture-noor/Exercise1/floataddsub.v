`include "rclas.v"
`include "barrel16.v"
`include "leftshift.v"

module FloatingPointAddSub(a,b,cin,out);
input [15:0]a,b;
input cin;
output [15:0]out;
wire [15:0]exdiff;
wire ca,cb;
wire [9:0]ma,mb;
wire [15:0]smallMan,bigMan,shifMan;
wire [4:0]ea,eb;
wire sa,sb;
wire [15:0]Ea,Eb;
wire [15:0]s;
wire carry;
wire [15:0]carry1;
wire [3:0]ctrl;
assign ma = a[9:0];
assign mb = b[9:0];

assign sa = a[15];
assign sb = b[15];
assign ea = a[14:10];
assign eb = b[14:10];

assign Ea[4:0]=ea;
assign Ea[15:5]=11'd0;
assign Eb[4:0]=eb;
assign Eb[15:5]=11'd0;



//subtraction of exponent
RCLAA RC_0(Ea,Eb,1'b1,s,ca);
assign carry1[0]=1'b0;
assign carry1[15:1]=15'd0;
RCLAA RC_1(carry1,s,ca,exdiff,cb);

//swapper
//if ca=1 ma should be shifted and if ca=0 mb should be shifted

assign smallMan[0] = mb[0]&&(~ca)||ma[0]&&(ca);
assign smallMan[1] = mb[1]&&(~ca)||ma[1]&&(ca);
assign smallMan[2] = mb[2]&&(~ca)||ma[2]&&(ca);
assign smallMan[3] = mb[3]&&(~ca)||ma[3]&&(ca);
assign smallMan[4] = mb[4]&&(~ca)||ma[4]&&(ca);
assign smallMan[5] = mb[5]&&(~ca)||ma[5]&&(ca);
assign smallMan[6] = mb[6]&&(~ca)||ma[6]&&(ca);
assign smallMan[7] = mb[7]&&(~ca)||ma[7]&&(ca);
assign smallMan[8] = mb[8]&&(~ca)||ma[8]&&(ca);
assign smallMan[9] = mb[9]&&(~ca)||ma[9]&&(ca);
assign smallMan[10]=1'b1;
assign smallMan[15:11]=5'd0;

assign bigMan[0] = ma[0]&&(~ca)||mb[0]&&(ca);
assign bigMan[1] = ma[1]&&(~ca)||mb[1]&&(ca);
assign bigMan[2] = ma[2]&&(~ca)||mb[2]&&(ca);
assign bigMan[3] = ma[3]&&(~ca)||mb[3]&&(ca);
assign bigMan[4] = ma[4]&&(~ca)||mb[4]&&(ca);
assign bigMan[5] = ma[5]&&(~ca)||mb[5]&&(ca);
assign bigMan[6] = ma[6]&&(~ca)||mb[6]&&(ca);
assign bigMan[7] = ma[7]&&(~ca)||mb[7]&&(ca);
assign bigMan[8] = ma[8]&&(~ca)||mb[8]&&(ca);
assign bigMan[9] = ma[9]&&(~ca)||mb[9]&&(ca);
assign bigMan[10]=1'b1;
assign bigMan[15:11]=5'd0;

wire finsign;
assign finsign = a[15]&&(~ca)||(b[15]^cin)&&(ca);

//shifter
assign ctrl=exdiff[3:0];
barrel_shifter_16bit barrel(smallMan, ctrl, shifMan);

//subtraction of mantissaa
wire [15:0]m1,m2,m3;
wire cc;
assign m1[9:0]=bigMan;
assign m2[9:0]=smallMan;
assign m1[15:10]=6'd0;
assign m2[15:10]=6'd0;
wire sign;
assign sign=a[15]^b[15]^cin;
RCLAA RC_2(bigMan,shifMan,sign,m3,cc);
wire [9:0]m4;
assign m4=m3[9:0];


reg [3:0]n;
always @(m3)
 begin
    if(m3[11]==0)
 	begin
 		if(m3[10]==1) assign n=4'b1010;
 		else if(m3[9]==1) assign n=4'b1001;
 		else if (m3[8]==1) assign n=4'b1000;
 		else if (m3[7]==1) assign n=4'b0111;
 		else if (m3[6]==1) assign n=4'b0110;
 		else if (m3[5]==1) assign n=4'b0101;
 		else if (m3[4]==1) assign n=4'b0100;
 		else if (m3[3]==1) assign n=4'b0011;
 		else if (m3[2]==1) assign n=4'b0010;
 		else if (m3[1]==1) assign n=4'b0001;
 		else if (m3[0]==1) assign n=4'b0000;
 		
 	end
 	else assign n=4'b1011;
end 
wire [15:0]n1,n2,n3,n4,n5,n6,n7,n8;
wire ce,cf,cg;
wire [15:0]carry2;
assign n1[3:0]=4'b1010;
assign n1[15:4]=12'd0;
assign n2[3:0]=n;
assign n2[15:4]=12'd0;
RCLAA RC_3(n1,n2,1'b1,n3,ce);
assign carry2[0]=1'b0;
assign carry2[15:1]=15'd0;
RCLAA RC_5(carry2,n3,ce,n6,cg);

wire [3:0]ctrl1;
assign ctrl1=n6[3:0];

barrel_leftshifter_16bit barrel1(m3, ctrl1, n4);

barrel_shifter_16bit barrel3(m3, ctrl1, n7);


assign n8[0]=n4[0]&&(~ce)||n7[0]&&(ce);
assign n8[1]=n4[1]&&(~ce)||n7[1]&&(ce);
assign n8[2]=n4[2]&&(~ce)||n7[2]&&(ce);
assign n8[3]=n4[3]&&(~ce)||n7[3]&&(ce);
assign n8[4]=n4[4]&&(~ce)||n7[4]&&(ce);
assign n8[5]=n4[5]&&(~ce)||n7[5]&&(ce);
assign n8[6]=n4[6]&&(~ce)||n7[6]&&(ce);
assign n8[7]=n4[7]&&(~ce)||n7[7]&&(ce);
assign n8[8]=n4[8]&&(~ce)||n7[8]&&(ce);
assign n8[9]=n4[9]&&(~ce)||n7[9]&&(ce);
assign n8[10]=n4[10]&&(~ce)||n7[10]&&(ce);
assign n8[11]=n4[11]&&(~ce)||n7[11]&&(ce);
assign n8[12]=n4[12]&&(~ce)||n7[12]&&(ce);
assign n8[13]=n4[13]&&(~ce)||n7[13]&&(ce);
assign n8[14]=n4[14]&&(~ce)||n7[14]&&(ce);
assign n8[15]=n4[15]&&(~ce)||n7[15]&&(ce);


    
wire [15:0]E;
assign E[0] = Eb[0]&&(ca)||Ea[0]&&(~ca);
assign E[1] = Eb[1]&&(ca)||Ea[1]&&(~ca);
assign E[2] = Eb[2]&&(ca)||Ea[2]&&(~ca);
assign E[3] = Eb[3]&&(ca)||Ea[3]&&(~ca);
assign E[4] = Eb[4]&&(ca)||Ea[4]&&(~ca);
assign E[15:5]=11'd0;
RCLAA RC_4(E,n3,1'b1,n5,cf);

assign out[9:0]=n8[9:0];
assign out[14:10]=n5[4:0];
assign out[15]=finsign;

always@(*)
begin
	if(Ea == 5'd0 )	
		$monitor("ouput is %b\n",b);
	else if(Eb == 5'd0)
		$monitor("ouput is %b\n",a);
	else if(Ea == 5'd31 && ma != 10'd0 )
		$monitor("NaN.\n");
	else if(Eb == 5'd31 && mb != 10'd0 )
		$monitor("NaN.\n");
	else if(Ea == 5'd31 && ma == 10'd0)
		$monitor("INFINITE.\n");
	else if(Eb == 5'd31 && mb == 10'd0)
		$monitor("INFINITE.\n");
	else if(out[14:10]==5'd31 )
		$monitor("OVERFLOW.\n");
	else if(out[14:10]==5'd0 )
		$monitor("UNDERFLOW.\n");
	
	else 
		$monitor(" a = %b, b = %b, cin = %b, output = %b",a,b,cin,out);
	
end	
endmodule

