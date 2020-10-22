FileName: .asciz "integer.txt"
array: .skip 0
Hand: .word 0

ldr r0,=FileName
mov r1,#0	;read mode
swi 0x66	;open

ldr r1,=array
mov r2,#20
swi 0x6a	;read string

mov r0,#1	;moving filehandle to r0
ldr r1,=array
swi 0x69	;write string

mov r0,#'\n
swi 0x00	;enter

mov r0,#1	;moving dilehandle to r0
ldr r1,=array
swi 0x69	;write string

swi 0x68
swi 0x11