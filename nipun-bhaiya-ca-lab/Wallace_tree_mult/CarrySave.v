module CarrySave(input [31:0]a, input [31:0]b, input [31:0]c, output [31:0]sum, output [31:0]carry);

assign sum = a^b^c;
assign carry = {((a^b)&c)+(a&b), 1'b0};

endmodule