FileName: .asciz "integer.txt"
FileHandle: .word 3
Stdout: .word 1
array: .skip 20
array1: .skip 2
enter: .asciz "\n"

ldr r0,=FileName
mov r1,#0	;read mode
swi 0x66	;open


mov r5,r0	;storing file handle in r5

ldr r1,=array
mov r2,#20
swi 0x6a	;reading

ldr r3,=array
ldr r4,=array1

loop:
ldrb r6,[r3]
cmp r6,#0
beq exit
cmp r6,#','
beq space
strb r6,[r4]
mov r0,r4
swi 0x02
add r3,r3,#1
bal loop



space:
ldr r0,=enter
swi 0x02
add r3,r3,#1
bal loop

exit:
ldr r0,[r5]
swi 0x68
swi 0x11


 