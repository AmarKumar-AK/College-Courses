;some random program given in the exam
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