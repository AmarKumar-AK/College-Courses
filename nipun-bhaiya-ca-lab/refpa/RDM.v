module RDM(input [16:0] kgp1, input [16:0] kgp2, output [15:0] kgp);

wire [15:0] temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8;

genvar i;	
generate
	
	for(i=15;i>0;i=i-1) begin
		assign temp1[i]=kgp1[i] | kgp1[i-1] & kgp2[i];
		assign temp2[i]=kgp2[i] & kgp2[i-1];
	end
	
	assign temp1[0]=kgp1[0];
	assign temp2[0]=kgp2[0];

	for(i=15;i>1;i=i-1) begin
		assign temp3[i]=temp1[i] | temp1[i-2] & temp2[i];
		assign temp4[i]=temp2[i] & temp2[i-2];
	end

	assign temp3[0]=temp1[0];
	assign temp4[0]=temp2[0];
	assign temp3[1]=temp1[1];
	assign temp4[1]=temp2[1];

	for(i=15;i>3;i=i-1) begin
		assign temp5[i]=temp3[i] | temp3[i-4] & temp4[i];
		assign temp6[i]=temp4[i] & temp4[i-4];
	end
	
	for(i=3;i>=0;i=i-1) begin
		assign temp5[i]=temp3[i];
		assign temp6[i]=temp4[i];
	end	

	for(i=15;i>7;i=i-1) begin
		assign temp7[i]=temp5[i] | temp5[i-8] & temp6[i];
		assign temp8[i]=temp6[i] & temp6[i-8];
	end

	for(i=0;i<8;i=i+1) begin
		assign temp7[i]=temp5[i];
		assign temp8[i]=temp6[i];
	end

	for(i=0;i<16;i=i+1) begin
		assign kgp[i]=temp7[i];
	end
endgenerate

endmodule