.memory 1 1
.mult 1 11
.add 1 4
.logical 1 1
LDR  F6, 34(R2)
LDR  F2, 45(R3)
MUL  F0, F2, F4
STR  30(R0), F0
CMP  F3, F4
ADD  F6, F8, F2