module LogicalUnit(input [15:0]a, input [15:0]b, input select, output [15:0] out);
	
	assign out = select == 1 ? ~a : {select == 2 ? a&b : {select == 3 ? a^b : {select == 4 ? a >> b : a << b}}};

endmodule