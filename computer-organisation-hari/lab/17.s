;note-when every string is read the carry bit is set to 1
InFile: .asciz "printMultiLineToStdoutFromFile.s"
mov r7,#1

array: .skip 50
enter: .asciz "\n"

ldr r0,=InFile
mov r1,#0	;read mode
swi 0x66	;open file



loop:
mov r0,#3
ldr r1,=array
mov r2,#50
swi 0x6a
bcs out
add r7,r7,#1
cmp r7,#5
bne loop


loop1:

mov r0,#3
ldr r1,=array
mov r2,#50
swi 0x6a
bcs out

mov r0,#1
ldr r1,=array
swi 0x69
ldr r1,=enter
swi 0x69



b loop1


out:
mov r0,#0
swi 0x68


stop:
swi 0x11
