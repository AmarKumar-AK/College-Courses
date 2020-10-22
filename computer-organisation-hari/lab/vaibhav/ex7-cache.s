Vector1:
.skip 400
Vector2:
.skip 400
File: .asciz "ex7file.txt"
      .align
NewLine: .asciz "\r\n"
mov r0,#0	 		@r0-index
mov r5,#4
mov r8,#5
ldr r1,=Vector1 		@r1-base address
ldr r3,=Vector2

InitializeLoop:
cmp r0,#100
beq NextPart
mul r2,r0,r5
add r2,r1,r2
str r0,[r2]
add r0,r0,#1
b InitializeLoop

NextPart:
mov r0,#0

IncrementLoop:
cmp r0,#100
beq NextPart2
mul r2,r0,r5
mov r4,r2
add r2,r1,r2
add r4,r3,r4
ldr r6,[r2]
add r6,r6,#5
str r6,[r4]
add r0,r0,#1
b IncrementLoop

NextPart2:
mov r0,#0

AddLoop:
cmp r0,#100
beq NextPart3
mul r2,r0,r5
mov r4,r2
add r2,r1,r2
add r4,r3,r4
ldr r6,[r2]
ldr r7,[r4]
add r6,r6,r7
str r6,[r2]
add r0,r0,#1
b AddLoop

NextPart3:
mov r0,#0

MulLoop:
cmp r0,#100
beq NextPart4
mul r2,r0,r5
add r2,r1,r2
ldr r6,[r2]
mul r7,r6,r8
str r7,[r2]
add r0,r0,#1
b MulLoop

NextPart4:
mov r0,#0

DivLoop:
cmp r0,#100
beq NextPart5
mul r2,r0,r5
add r2,r1,r2
ldr r6,[r2]
mov r6,r6,asr #2
str r6,[r2]
add r0,r0,#1
b DivLoop

NextPart5:
mov r0,#0

AdditionLoop:
cmp r0,#100
beq CopyToFilePart
mul r2,r0,r5
add r2,r1,r2
ldr r6,[r2]
add r6,r6,#16384
str r6,[r2]
add r0,r0,#1
b AdditionLoop

CopyToFilePart:
mov r10,#0
ldr r0,=File
mov r11,r1		@base address now in r11
mov r1,#1
swi 0x66

AccessLoop:
cmp r10,#100
beq End
mul r2,r10,r5
add r2,r11,r2
ldr r6,[r2]
mov r1,r6
swi 0x6b
ldr r1,=NewLine
swi 0x69
add r10,r10,#1
b AccessLoop


End:
swi 0x68
swi 0x11
