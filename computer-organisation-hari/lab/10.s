FileName: .asciz "integer.txt"
FileHandle: .word 1
array: .skip 50

;open file
ldr r0,=FileName
mov r1,#0
swi 0x66

;read string from file
ldr r1,=array
mov r2,#10
swi 0x6a

;write string to stdout
ldr r0,=FileHandle
ldr r0,[r0]
ldr r1,=array
swi 0x69

swi 0x68