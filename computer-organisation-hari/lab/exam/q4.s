;checking whether two strings one from file1 and other from file2 are same or not

fileName1: .asciz "file1.txt"
fileName2: .asciz "file2.txt"
array1: .skip 80
array2: .skip 80
.align

ldr r0,=fileName1
mov r1,#0
swi 0x66

ldr r0,=fileName2
mov r1,#0
swi 0x66

mov r0,#3
ldr r1,=array1
mov r2,#80
swi 0x6a


mov r0,#4
ldr r1,=array2
mov r2,#80
swi 0x6a


.align

ldr r4,=array1
ldr r4,[r4]
ldr r5,=array2
ldr r5,[r5] 
cmp r4,r5
beq printy
bne printn



printy:
	ldr r0,=y
	swi 0x02
	swi 0x11

printn:
	ldr r0,=n
	swi 0x02
	swi 0x11

y: .asciz "yes"
n: .asciz "no"