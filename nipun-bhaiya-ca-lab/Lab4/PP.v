module PP(input [15:0]a, input [15:0]b, output [31:0]p1, output [31:0]p2, output [31:0]p3, output [31:0]p4, output [31:0]p5, output [31:0]p6, output [31:0]p7, output [31:0]p8, output [31:0]p9, output [31:0]p10, output [31:0]p11, output [31:0]p12, output [31:0]p13, output [31:0]p14, output [31:0]p15, output [31:0]p16);

assign p1=b[0]?{16'b0,a}:16'b0;
assign p2=b[1]?{15'b0,a,1'b0}:16'b0;
assign p3=b[2]?{14'b0,a,2'b0}:16'b0;
assign p4=b[3]?{13'b0,a,3'b0}:16'b0;
assign p5=b[4]?{12'b0,a,4'b0}:16'b0;
assign p6=b[5]?{11'b0,a,5'b0}:16'b0;
assign p7=b[6]?{10'b0,a,6'b0}:16'b0;
assign p8=b[7]?{9'b0,a,7'b0}:16'b0;
assign p9=b[8]?{8'b0,a,8'b0}:16'b0;
assign p10=b[9]?{7'b0,a,9'b0}:16'b0;
assign p11=b[10]?{6'b0,a,10'b0}:16'b0;
assign p12=b[11]?{5'b0,a,11'b0}:16'b0;
assign p13=b[12]?{4'b0,a,12'b0}:16'b0;
assign p14=b[13]?{3'b0,a,13'b0}:16'b0;
assign p15=b[14]?{2'b0,a,14'b0}:16'b0;
assign p16=b[15]?{1'b0,a,15'b0}:16'b0;

endmodule