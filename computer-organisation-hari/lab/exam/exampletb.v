module exampletb;
reg input1;
reg input2;
reg input3;
wire out;

example uut(
.x(input1),
.y(input2),
.z(input3),
.A(out)
);

initial begin

input1 =0;
input2 =0;
input3 =0;

#20; input1 =1;
#20; input2 =1;
#20; input1 =0;
#20; input3 =1;
#20; input2 =0;
#20; input1 =1;
#20; input2 =1;
#40;
end

initial begin
$monitor("time = %2d, IN3 =%1b, IN2=%1b, IN1=%1b, COUT=%1b, OUT=%1b", $time,input3,input2, input1,out);
$dumpfile("amar.vcd");
$dumpvars(0,input3,input2, input1,out);
end
endmodule
