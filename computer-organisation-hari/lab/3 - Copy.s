FileName: .asciz "write.txt"
Message: .asciz "This is my first program in ArmSim\n"
FileHandle: .word 1

ldr r0,=FileName
mov r1,#1
swi 0x66

ldr r1,=Message
swi 0x69

swi 0x68
