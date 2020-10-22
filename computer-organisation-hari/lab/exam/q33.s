;same as q3 but starts with address 2000
.skip 4096
mov r7,#10
mov r1,#5
mov r0,#3
mov r2,#8
loop:
	add r1,r2,r0
	subs r0,r0,#1
	beq end
b loop
nop
nop
nop

end:
b end