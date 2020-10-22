file: .asciz "file1.txt"
.equ add,0x2000
Errormsg: .asciz "Error"
ldr r0,=file
mov r1,#0	;
swi 0x66 	;To open file
bcs Error
ldr r1,=add
mov r2,#80
swi 0x6a	;Read string from file
swi 0x68	;Close file
ldr r1,=add
Loop:
ldrb r0,[r1],#1
cmp r0,#0x0
beq EndofLoop
cmp r0,#0x2c
moveq r0,#0xa
swi 0x00
b Loop  
EndofLoop:
swi 0x11
Error:
ldr r0,=Errormsg
swi 0x02 
swi 0x11