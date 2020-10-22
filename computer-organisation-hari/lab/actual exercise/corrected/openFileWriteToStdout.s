FileName: .asciz "edit.txt"
FileHandle: .word 1	
array:	.skip 50

ldr r0,=FileName
mov r1,#0
swi 0x66	

ldr r1,=array
mov r2,#50
swi 0x6a	

ldr r0,=FileHandle
ldr r0,[r0]
ldr r1,=array
swi 0x69


	
swi 0x68

