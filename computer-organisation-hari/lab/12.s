FileName: .asciz "integer.txt"
FileHandle: .word 3
Stdout: .word 1
array: .skip 20
enter: .asciz "\n"

ldr r0,=FileName
mov r1,#0	;read mode
swi 0x66	;open 

ldr r0,=FileHandle
ldr r0,[r0]
ldr r1,=array
mov r2,#20
swi 0x6a

mov r4,#0 ;counter set to 0

loop:
;bcs close

ldr r0,=Stdout
ldr r0,[r0]
ldr r1,=array
swi 0x69




b loop

close:
ldr r0,=Stdout
ldr r0,[r0]
swi 0x68
stop:
swi 0x11