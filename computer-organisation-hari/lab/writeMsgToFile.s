FileName: .asciz "write.txt"
Message: .asciz "This is my first program in ArmSim\n"

ldr r0,=FileName
mov r1,#1	;write mode
swi 0x66	;open file

ldr r1,=Message	
swi 0x69
swi 0x68
