module mux(a,b,c,d,s,out);

input a,b,c,d;
input [1:0]s;
output out;
assign out=s[1]?(s[0]?d:c):(s[0]?b:a);

endmodule
