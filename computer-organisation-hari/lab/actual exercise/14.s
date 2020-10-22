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
	.word 11
   	.word 12
	.word 13
	.word 14
	.word 15
	.word 16
	.word 17
	.word 18
	.word 19
	.word 20
	.word 21
   	.word 22
	.word 23
	.word 24
	.word 25
	.word 26
	.word 27
	.word 28
	.word 29
	.word 30
	.word 31
   	.word 32
	.word 33
	.word 34
	.word 35
	.word 36
	.word 37
	.word 38
	.word 39
	.word 40
	.word 41
   	.word 42
	.word 43
	.word 44
	.word 45
	.word 46
	.word 47
	.word 48
	.word 49
	.word 50
	.word 51
   	.word 52
	.word 53
	.word 54
	.word 55
	.word 56
	.word 57
	.word 58
	.word 59
	.word 60
	.word 61
   	.word 62
	.word 63
	.word 64
	.word 65
	.word 66
	.word 67
	.word 68
	.word 69
	.word 70
	.word 71
   	.word 72
	.word 73
	.word 74
	.word 75
	.word 76
	.word 77
	.word 78
	.word 79
	.word 80
	.word 81
   	.word 82
	.word 83
	.word 84
	.word 85
	.word 86
	.word 87
	.word 88
	.word 89
	.word 90
	.word 91
   	.word 92
	.word 93
	.word 94
	.word 95
	.word 96
	.word 97
	.word 98
	.word 99
	.word 100
	
b: 	.skip 400
.align
mov r7,#100
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
mov r7,#100
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
mov r7,#100
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
mov r7,#100
division:
	ldr r2,[r0]
	mov r2,r2,lsr #2
	str r2,[r0]
	add r0,r0,#4
	sub r7,r7,#1
	cmp r7,#0
	bne division

ldr r0,=a
mov r7,#100
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
mov r7,#100
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