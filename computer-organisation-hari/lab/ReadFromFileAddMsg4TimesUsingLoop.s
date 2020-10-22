InFile: .asciz "edit.txt"
InHandle: .word 0
OutHandle: .word 1	;1 stands for stdout	
array:	.skip 50
enter: .asciz "\n"
Msg: .asciz "Amar Kumar"


ldr r0,=InFile
mov r1,#0	;read mode
swi 0x66	

ldr r1,=array
mov r2,#50
swi 0x6a	

ldr r0,=OutHandle	;FileHandle of stdout
ldr r0,[r0]
ldr r1,=array
swi 0x69

mov r3,#0

increment:
add r3,r3,#1	;++i

loop:
ldr r1,=enter
swi 0x69	;pressing enter
ldr r1,=Msg
swi 0x69	;printing Msg

cmp r3,#4	;comparing with 4

bne increment	;checking for not equal
beq stop	;checking for equal
b loop		;calling loop

swi 0x68


stop:
swi 0x11

