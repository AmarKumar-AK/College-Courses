file: .asciz "file1.txt"
ldr r0,=file
mov r1,#0
swi 0x66
mov r3,r0 	@r3 stores file handle
Loop:
mov r0,r3
swi 0x6c	@read int from file and store in r0
bcs Error
mov r1,r0	@r1 holds int read from file
mov r0,#1	@file handle for STDOut=1
swi 0x6b	@Write Integer to STDOut

b Loop
swi 0x68	@Close file
swi 0x11
Error:
swi 0x68	@Close file
swi 0x11