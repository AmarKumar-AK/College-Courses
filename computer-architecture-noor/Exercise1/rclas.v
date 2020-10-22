module RCLAA(a, b, cin, sum, carry);

	input [16:1] a, b;					
	input cin;
	output [16:1] sum;
	output carry;

	wire [32:1] c;			
	wire [32:1] p;
	wire [32:1] q;
	wire [32:1] r;
	wire [32:1] s;
	wire [16:1] t;
	wire [16:1] d;


	
	assign c[1]=(a[1]&(b[1]^cin))|((b[1]^cin)&cin)|(cin&a[1]);								
	assign c[2]=(a[1]&(b[1]^cin))|((b[1]^cin)&cin)|(cin&a[1]);				
	assign c[3]=a[2]&(b[2]^cin);
	assign c[4]=a[2]|(b[2]^cin);
	assign c[5]=a[3]&(b[3]^cin);
	assign c[6]=a[3]|(b[3]^cin);
	assign c[7]=a[4]&(b[4]^cin);
	assign c[8]=a[4]|(b[4]^cin);
	assign c[9]=a[5]&(b[5]^cin);
	assign c[10]=a[5]|(b[5]^cin);
	assign c[11]=a[6]&(b[6]^cin);
	assign c[12]=a[6]|(b[6]^cin);
	assign c[13]=a[7]&(b[7]^cin);
	assign c[14]=a[7]|(b[7]^cin);
	assign c[15]=a[8]&(b[8]^cin);
	assign c[16]=a[8]|(b[8]^cin);
	assign c[17]=a[9]&(b[9]^cin);
	assign c[18]=a[9]|(b[9]^cin);
	assign c[19]=a[10]&(b[10]^cin);
	assign c[20]=a[10]|(b[10]^cin);
	assign c[21]=a[11]&(b[11]^cin);
	assign c[22]=a[11]|(b[11]^cin);						
	assign c[23]=a[12]&(b[12]^cin);
	assign c[24]=a[12]|(b[12]^cin);
	assign c[25]=a[13]&(b[13]^cin);
	assign c[26]=a[13]|(b[13]^cin);
	assign c[27]=a[14]&(b[14]^cin);
	assign c[28]=a[14]|(b[14]^cin);
	assign c[29]=a[15]&(b[15]^cin);
	assign c[30]=a[15]|(b[15]^cin);
	assign c[31]=a[16]&(b[16]^cin);
	assign c[32]=a[16]|(b[16]^cin);
	
//recurrsive method- row1
	assign p[2:1]=c[2:1];						
	assign p[3]=c[3]|(c[4]&c[1]);
	assign p[4]=c[3]|(c[4]&c[2]);	
	assign p[5]=c[5]|(c[6]&c[3]);
	assign p[6]=c[5]|(c[6]&c[4]);
	assign p[7]=c[7]|(c[8]&c[5]);
	assign p[8]=c[7]|(c[8]&c[6]);
	assign p[9]=c[9]|(c[10]&c[7]);
	assign p[10]=c[9]|(c[10]&c[8]);
	assign p[11]=c[11]|(c[12]&c[9]);
	assign p[12]=c[11]|(c[12]&c[10]);
	assign p[13]=c[13]|(c[14]&c[11]);
	assign p[14]=c[13]|(c[14]&c[12]);
	assign p[15]=c[15]|(c[16]&c[13]);
	assign p[16]=c[15]|(c[16]&c[14]);
	assign p[17]=c[17]|(c[18]&c[15]);
	assign p[18]=c[17]|(c[18]&c[16]);
	assign p[19]=c[19]|(c[20]&c[17]);
	assign p[20]=c[19]|(c[20]&c[18]);
	assign p[21]=c[21]|(c[22]&c[19]);
	assign p[22]=c[21]|(c[22]&c[20]);
	assign p[23]=c[23]|(c[24]&c[21]);
	assign p[24]=c[23]|(c[24]&c[22]);
	assign p[25]=c[25]|(c[26]&c[23]);
	assign p[26]=c[25]|(c[26]&c[24]);
	assign p[27]=c[27]|(c[28]&c[25]);
	assign p[28]=c[27]|(c[28]&c[26]);
	assign p[29]=c[29]|(c[30]&c[27]);
	assign p[30]=c[29]|(c[30]&c[28]);
	assign p[31]=c[31]|(c[32]&c[29]);
	assign p[32]=c[31]|(c[32]&c[30]);

//recurrsive method to get row 2	
	assign q[4:1]=p[4:1];						
	assign q[5]=p[5]|(p[6]&p[1]);
	assign q[6]=p[5]|(p[6]&p[2]);
	assign q[7]=p[7]|(p[8]&p[3]);
	assign q[8]=p[7]|(p[8]&p[4]);
	assign q[9]=p[9]|(p[10]&p[5]);
	assign q[10]=p[9]|(p[10]&p[6]);
	assign q[11]=p[11]|(p[12]&p[7]);
	assign q[12]=p[11]|(p[12]&p[8]);
	assign q[13]=p[13]|(p[14]&p[9]);
	assign q[14]=p[13]|(p[14]&p[10]);
	assign q[15]=p[15]|(p[16]&p[11]);
	assign q[16]=p[15]|(p[16]&p[12]);
	assign q[17]=p[17]|(p[18]&p[13]);
	assign q[18]=p[17]|(p[18]&p[14]);
	assign q[19]=p[19]|(p[20]&p[15]);
	assign q[20]=p[19]|(p[20]&p[16]);
	assign q[21]=p[21]|(p[22]&p[17]);
	assign q[22]=p[21]|(p[22]&p[18]);
	assign q[23]=p[23]|(p[24]&p[19]);
	assign q[24]=p[23]|(p[24]&p[20]);
	assign q[25]=p[25]|(p[26]&p[21]);
	assign q[26]=p[25]|(p[26]&p[22]);
	assign q[27]=p[27]|(p[28]&p[23]);
	assign q[28]=p[27]|(p[28]&p[24]);
	assign q[29]=p[29]|(p[30]&p[25]);
	assign q[30]=p[29]|(p[30]&p[26]);
	assign q[31]=p[31]|(p[32]&p[27]);
	assign q[32]=p[31]|(p[32]&p[28]);

	
//recursive method to get row 3
	assign r[8:1]=q[8:1];					
	assign r[9]=q[9]|(q[10]&q[1]);
	assign r[10]=q[9]|(q[10]&q[2]);
	assign r[11]=q[11]|(q[12]&q[3]);
	assign r[12]=q[11]|(q[12]&q[4]);
	assign r[13]=q[13]|(q[14]&q[5]);
	assign r[14]=q[13]|(q[14]&q[6]);
	assign r[15]=q[15]|(q[16]&q[7]);
	assign r[16]=q[15]|(q[16]&q[8]);
	assign r[17]=q[17]|(q[18]&q[9]);	
	assign r[18]=q[17]|(q[18]&q[10]);
	assign r[19]=q[19]|(q[20]&q[11]);
	assign r[20]=q[19]|(q[20]&q[12]);
	assign r[21]=q[21]|(q[22]&q[13]);
	assign r[22]=q[21]|(q[22]&q[14]);
	assign r[23]=q[23]|(q[24]&q[15]);
	assign r[24]=q[23]|(q[24]&q[16]);
	assign r[25]=q[25]|(q[26]&q[17]);
	assign r[26]=q[25]|(q[26]&q[18]);
	assign r[27]=q[27]|(q[28]&q[19]);
	assign r[28]=q[27]|(q[28]&q[20]);	
	assign r[29]=q[29]|(q[30]&q[21]);
	assign r[30]=q[29]|(q[30]&q[22]);
	assign r[31]=q[31]|(q[32]&q[23]);
	assign r[32]=q[31]|(q[32]&q[24]);

//recursive method to get row 4
	assign s[16:1]=r[16:1];					
	assign s[17]=r[17]|(r[18]&r[1]);
	assign s[18]=r[17]|(r[18]&r[2]);
	assign s[19]=r[19]|(r[20]&r[3]);
	assign s[20]=r[19]|(r[20]&r[4]);
	assign s[21]=r[21]|(r[22]&r[5]);
	assign s[22]=r[21]|(r[22]&r[6]);
	assign s[23]=r[23]|(r[24]&r[7]);
	assign s[24]=r[23]|(r[24]&r[8]);
	assign s[25]=r[25]|(r[26]&r[9]);
	assign s[26]=r[25]|(r[26]&r[10]);
	assign s[27]=r[27]|(r[28]&r[11]);
	assign s[28]=r[27]|(r[28]&r[12]);
	assign s[29]=r[29]|(r[30]&r[13]);
	assign s[30]=r[29]|(r[30]&r[14]);
	assign s[31]=r[31]|(r[32]&r[15]);
	assign s[32]=r[31]|(r[32]&r[16]);


//k to 0 and g to 1
	assign t[1]=s[1]&s[2];					
	assign t[2]=s[3]&s[4];
	assign t[3]=s[5]&s[6];
	assign t[4]=s[7]&s[8];
	assign t[5]=s[9]&s[10];
	assign t[6]=s[11]&s[12];
	assign t[7]=s[13]&s[14];
	assign t[8]=s[15]&s[16];
	assign t[9]=s[17]&s[18];
	assign t[10]=s[19]&s[20];
	assign t[11]=s[21]&s[22];
	assign t[12]=s[23]&s[24];
	assign t[13]=s[25]&s[26];
	assign t[14]=s[27]&s[28];
	assign t[15]=s[29]&s[30];
	assign t[16]=s[31]&s[32];

//final XOR for sum and obtained number

	assign sum[1]=a[1]^b[1]^cin^cin;			
	assign sum[2]=a[2]^b[2]^cin^t[1];
	assign sum[3]=a[3]^b[3]^cin^t[2];
	assign sum[4]=a[4]^b[4]^cin^t[3];
	assign sum[5]=a[5]^b[5]^cin^t[4];
	assign sum[6]=a[6]^b[6]^cin^t[5];
	assign sum[7]=a[7]^b[7]^cin^t[6];
	assign sum[8]=a[8]^b[8]^cin^t[7];
	assign sum[9]=a[9]^b[9]^cin^t[8];
	assign sum[10]=a[10]^b[10]^cin^t[9];
	assign sum[11]=a[11]^b[11]^cin^t[10];
	assign sum[12]=a[12]^b[12]^cin^t[11];
	assign sum[13]=a[13]^b[13]^cin^t[12];
	assign sum[14]=a[14]^b[14]^cin^t[13];
	assign sum[15]=a[15]^b[15]^cin^t[14];
	assign sum[16]=a[16]^b[16]^cin^t[15];
	assign carry=0^0^t[16]^cin;

endmodule
