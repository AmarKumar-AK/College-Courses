module fullAdder(a,b,cin,sum,ca);
input a,b,cin;
output sum,ca;
	assign sum=a^b^cin;
	assign ca=(a&b)|(cin&a)|(cin & b);
endmodule
