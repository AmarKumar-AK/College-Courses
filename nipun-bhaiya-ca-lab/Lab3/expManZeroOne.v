module expManZeroOne(input [15:0]a, input [15:0]b, output isExpAZero, output isExpBZero, output isExpAOne, output isExpBOne, output isManAZero, output isManBZero, output isManAOne, output isManBOne);

assign isExpAZero = a[14]|a[13]|a[12]|a[11]|a[10]; 
assign isExpBZero = b[14]|b[13]|b[12]|b[11]|b[10];
assign isExpAOne = a[14]&a[13]&a[12]&a[11]&a[10]; 
assign isExpBOne = b[14]&b[13]&b[12]&b[11]&b[10];
assign isManAZero = a[9]|a[8]|a[7]|a[6]|a[5]|a[4]|a[3]|a[2]|a[1]|a[0];
assign isManBZero = b[9]|b[8]|b[7]|b[6]|b[5]|b[4]|b[3]|b[2]|b[1]|b[0];
assign isManAOne = a[9]&a[8]&a[7]&a[6]&a[5]&a[4]&a[3]&a[2]&a[1]&a[0];
assign isManBOne = b[9]&b[8]&b[7]&b[6]&b[5]&b[4]|b[3]&b[2]&b[1]&b[0]; 

endmodule