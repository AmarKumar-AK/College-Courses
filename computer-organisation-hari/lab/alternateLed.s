mov r7,#0
left:
	mov r0,#0x02
	swi 0x201
	add r7,r7,#1
	cmp r7,#100
	beq stop
	bl loop2
	bal right 


loop2:
mov r4,#0
	ltimer:
	mov r0,#'1
	swi 0x00
	mov r0,#'2
	swi 0x00
	add r4,r4,#1
	cmp r4,#10
	bne ltimer
	bx lr






right:
	mov r0,#0x01
	swi 0x201
	bl loop2
	bal left

stop:
	swi 0x11



