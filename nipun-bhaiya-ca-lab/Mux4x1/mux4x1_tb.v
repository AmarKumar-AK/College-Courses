module mux4x1_tb();
reg [3:0]in;
reg [1:0]sel;
wire res;

mux4x1 mux8x1_always_tb(
	.in(in),
	.sel(sel),
	.result(res)
);

	initial
		begin
				 in=8'b1010;
				 sel=3'b00;
			#10; sel=3'b01;
			#10; sel=3'b10;
			#10; sel=3'b11;
		end

	initial
		begin
			$dumpfile("mux4x1.vcd");
			$dumpvars(0, mux4x1_tb);
			$monitor("time = %2d, input = %b, select = %b result = %b", $time, in, sel, res);
		end

endmodule