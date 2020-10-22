CharArray: .skip 80
nl: .asciz "\n"
InFileName: .asciz "Myfileio.s" 
	.align
InFileError: .asciz "Unable to open input file\n"
	.align 
InFileHandle:.word 0 

cFileName: .asciz "copiedFromMyfileio.s" 
	.align
cFileError: .asciz "Unable to open input file\n"
	.align 
cFileHandle:.word 0 

ldr r0,=InFileName      @ set Name for input file
mov r1,#0               @ mode is input 
swi 0x66                @ open file for input 
bcs InFileError         @ if error? 
ldr r1,=InFileHandle    @ load input file handle 
str r0,[r1] 




ldr r0,=cFileName      @ set Name for input file
mov r1,#1              @ mode is output
swi 0x66                @ open file for input 
bcs cFileError         @ if error? 
ldr r1,=cFileHandle    @ load input file handle 
str r0,[r1] 
loop:

ldr r0,=InFileHandle 
ldr r0,[r0] 
ldr r1,=CharArray 
mov r2,#80 
swi 0x6a 
bcs yut

ldr r0,=cFileHandle 
ldr r0,[r0] 
ldr r1,=CharArray
swi 0x69 

ldr r0,=cFileHandle 
ldr r0,[r0] 
ldr r1,=nl
swi 0x69 

b loop
yut:

ldr r0,=InFileHandle 
ldr r0,[r0] 
swi 0x68

ldr r0,=cFileHandle 
ldr r0,[r0] 
swi 0x68
swi 0x11
