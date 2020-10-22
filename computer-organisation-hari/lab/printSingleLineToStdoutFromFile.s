FileName: .asciz "write.txt"
chararray: .skip 80
		;FileHandle: .word 1

ldr r0,=FileName
mov r1,#0	;read mode
swi 0x66	; open file

ldr r1,=chararray
mov r2,#80
swi 0x6a


ldr r0,=chararray
swi 0x02

