

main:
mov r0,#'a
swi 0x00

mov r0,#'\n
swi 0x00

bl loop2
mov r0,#'k
swi 0x00

swi 0x11


loop1:
mov r3,#0
	stimer:
	mov r0,#'0
	swi 0x00
	add r3,r3,#1
	cmp r3,#2
	bne stimer
	beq ltimer

loop2:
mov r4,#0
	ltimer:
	mov r0,#'1
	swi 0x00
	mov r0,#'2
	swi 0x00
	add r4,r4,#1
	cmp r4,#5
	bne loop1
	bx lr