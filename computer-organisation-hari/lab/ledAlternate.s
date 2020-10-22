mov r1,#5

left:
	mov r0,#0x02
	swi 0x201
	sub r1,r1,#1
	cmp r1,#0
	beq stop
	bl loop
	bal right

right:
	mov r0,#0x01
	swi 0x201
	bl loop
	bal left

loop:
mov r5,#0x40000
	wait:
	sub r5,r5,#1
	cmp r5,#0
	bne wait
	bx lr
stop:
	swi 0x11	