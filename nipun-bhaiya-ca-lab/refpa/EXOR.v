module EXOR(output [15:0]y ,input [15:0]a, input [15:0]b, input [15:0]kgp);

	genvar i;	
generate 
	
	
	for(i=0;i<16;i=i+1) begin
		assign y[i] =  a[i] ^ b[i] ^ kgp[i];  
	end
endgenerate

endmodule