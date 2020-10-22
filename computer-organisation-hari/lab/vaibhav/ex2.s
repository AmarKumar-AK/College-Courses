file: .asciz "file.txt"
text: .asciz "Computer Organization"
ldr r0,=file
mov r1,#0x1
swi 0x66
ldr r1,=text
swi 0x69
swi 0x68
swi 0x11