FileName1: .asciz "edit.txt"
FileHandle: .word 0
FileName2: .asciz "new.txt"
array: .skip 80

ldr r0,=FileName1
mov r1,#0
swi 0x66

ldr r1,=array
mov r2,#80
swi 0x6a

ldr r0,=FileName2
mov r1,#1
swi 0x66

ldr r1,=array
swi 0x69

ldr r1,=array
swi 0x69

swi 0x68