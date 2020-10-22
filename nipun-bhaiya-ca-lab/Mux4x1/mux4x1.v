module mux4x1(input [3:0]in, input [1:0]sel, output reg result);

always @ *
	begin
		if(sel == 2'b00) begin
			result <= in[0];
		end
		else if(sel == 2'b01) begin
			result <= in[1];
		end
		else if(sel == 2'b10) begin
			result <= in[2];
		end
		else result <= in[3];
	end

endmodule