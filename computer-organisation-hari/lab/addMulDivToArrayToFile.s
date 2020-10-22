space: .asciz " "
a: 	.word 1
   	.word 2
	.word 3
	.word 4
	.word 5
	.word 6
	.word 7
	.word 8
	.word 9
	.word 10
b: 	.skip 40
.align
mov r7,#10
ldr r0,=a
ldr r1,=b
increment:
	ldr r2,[r0]
	add r2,r2,#1
	str r2,[r1]
	add r0,r0,#4
	add r1,r1,#4
	sub r7,r7,#1
	cmp r7,#0
	bne increment

ldr r0,=a
ldr r1,=b
mov r7,#10
adding:
	ldr r3,[r0]
	ldr r4,[r1]
	add r3,r3,r4
	str r3,[r0]
	add r0,r0,#4
	add r1,r1,#4
	sub r7,r7,#1
	cmp r7,#0
	bne adding

ldr r0,=a
mov r7,#10
mov r8,#5
multiplication:
	ldr r2,[r0]
	mul r9,r2,r8
	str r9,[r0]
	add r0,r0,#4
	sub r7,r7,#1
	cmp r7,#0
	bne multiplication

ldr r0,=a
mov r7,#10
division:
	ldr r2,[r0]
	mov r2,r2,lsr #2
	str r2,[r0]
	add r0,r0,#4
	sub r7,r7,#1
	cmp r7,#0
	bne division

ldr r0,=a
mov r7,#10
newAdd:
	ldr r2,[r0]
	add r2,r2,#16384
	str r2,[r0]
	add r0,r0,#4
	sub r7,r7,#1
	cmp r7,#0
	bne newAdd


fileName:	.asciz "number.txt"
.align
ldr r0,=fileName
mov r1,#1
swi 0x66
mov r7,#10
ldr r2,=a
print:	
	ldr r1,[r2]
	swi 0x6b
	ldr r1,=space
	swi 0x69
	add r2,r2,#4
	sub r7,r7,#1
	cmp r7,#0
	bne print
	
end:
	swi 0x68
	swi 0x11