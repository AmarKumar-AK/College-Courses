module full_Adder (a,b,cin,sum, ca);
input a, b,cin;
output sum, ca;
	// assign sum = a ^ b;
	// assign ca  = a&b;
    assign {ca,sum} =  cin + a + b;
endmodule