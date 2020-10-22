InFile: .asciz "edit.txt"
InHandle: .word 0
OutHandle: .word 1
array: .skip 50
enter: .asciz "\n"

ldr r0,=InFile
mov r1,#0	;read mode
swi 0x66	;open InFile

;loop:
ldr r0,=InHandle
ldr r0,[r0]
ldr r1,=array
mov r2,#50
swi 0x6a	;reading string

ldr r0,=OutHandle
ldr r0,[r0]
ldr r1,=array
swi 0x69	;writing string

ldr r0,=OutHandle
ldr r0,[r0]
ldr r1,=enter
swi 0x69


;b loop
swi 0x68	;closing file
swi 0x11	;end

