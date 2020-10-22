file: .asciz "fil.txt"
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
ldr r0,=add
swi 0x02 	;Display string on STDOut
swi 0x11
Error:
ldr r0,=Errormsg
swi 0x02 
swi 0x11