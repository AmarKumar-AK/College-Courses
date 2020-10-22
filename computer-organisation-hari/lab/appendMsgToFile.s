FileName: .asciz "learn.txt"
NewMessage: .asciz "I am appending this text to learn.txt file\n"

ldr r0,=FileName
mov r1,#2	;append mode
swi 0x66

ldr r1,=NewMessage
swi 0x69
swi 0x68
