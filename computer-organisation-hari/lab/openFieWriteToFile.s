FileName1: .asciz "edit.txt"
FileHandle: .word 0	;0 because outputting string to a file
FileName2: .asciz "new.txt"
array: .skip 80

ldr r0,=FileName1
mov r1,#0
swi 0x66	;open FileName1 in read mode

ldr r1,=array
mov r2,#80
swi 0x6a	;read from FileName1

ldr r0,=FileName2
mov r1,#1
swi 0x66	;open FileName2 in write mode

ldr r1,=array
swi 0x69

swi 0x68	;closing all files