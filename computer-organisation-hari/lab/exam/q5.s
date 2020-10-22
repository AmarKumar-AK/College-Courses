y: .asciz "yes"
n: .asciz "no"


printy:
	ldr r0,=y
	swi 0x02


printn:
	ldr r0,=n
	swi 0x02