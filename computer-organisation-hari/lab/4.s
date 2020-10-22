FileName: .asciz "learn.txt"
Message: .asciz "I am learning arm simulator\n"

ldr r0,=FileName
mov r1,#1
swi 0x66

ldr r1,=Message
swi 0x69
swi 0x68