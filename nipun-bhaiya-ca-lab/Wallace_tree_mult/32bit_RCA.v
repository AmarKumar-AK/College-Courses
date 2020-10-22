// `include "XOR.v"
// `include "KGP_module.v"
// `include "Parallel_prefix.v"

module RCA(a, b, overflow, sum);
input [31:0] a;
input [31:0] b;
output [31:0] sum;
output overflow;
wire [31:0] xor_output;
wire [32:0] kgp_one;
wire [32:0] kgp_two;
wire [31:0] final_kgp;

XOR_sum get_output(a, b, xor_output);
KGP generate_kgp(a, b, kgp_one, kgp_two);
Parallel_Prefix parallel_prefix01(kgp_one, kgp_two, final_kgp);
assign sum = xor_output^final_kgp;
assign overflow = ((a[31]^b[31])&final_kgp[30])+(a[31]&b[31]);

endmodule