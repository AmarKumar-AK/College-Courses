`include "../16bit_Adder/XOR.v"
`include "../16bit_Adder/KGP_module.v"
`include "../16bit_Adder/Parallel_prefix.v"

module RCA(a, b, overflow, cin, sum);
input [15:0] a;
input [15:0] b;
input cin;
output [15:0] sum;
output overflow;
wire [15:0] xor_output;
wire [16:0] kgp_one;
wire [16:0] kgp_two;
wire [15:0] final_kgp;

XOR_sum get_output(a, b, xor_output);
KGP generate_kgp(a, b, kgp_one, kgp_two, cin);
Parallel_Prefix parallel_prefix01(kgp_one, kgp_two, final_kgp);
assign sum = xor_output^final_kgp;
assign overflow = ((a[15]^b[15])&final_kgp[15])+(a[15]&b[15]);

endmodule