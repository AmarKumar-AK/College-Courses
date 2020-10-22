mov r1,#0x20000


.equ SEG_A,0x80 
.equ SEG_B,0x40 
.equ SEG_C,0x20 
.equ SEG_D,0x08 
.equ SEG_E,0x04 
.equ SEG_F,0x02 
.equ SEG_G,0x01 
.equ SEG_P,0x10

.equ zero,SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_G @0 
.equ one,SEG_B|SEG_C @1 
.equ two,SEG_A|SEG_B|SEG_F|SEG_E|SEG_D @2 
.equ three,SEG_A|SEG_B|SEG_F|SEG_C|SEG_D @3 
.equ four,SEG_G|SEG_F|SEG_B|SEG_C @4 
.equ five,SEG_A|SEG_G|SEG_F|SEG_C|SEG_D @5 
.equ six,SEG_A|SEG_G|SEG_F|SEG_E|SEG_D|SEG_C @6 
.equ seven,SEG_A|SEG_B|SEG_C @7 
.equ eight,SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G @8 
.equ nine,SEG_A|SEG_B|SEG_F|SEG_G|SEG_C @9

Display8Segment:
	
	ldr r0,=zero
	swi 0x200
	bl wait
	ldr r0,=one
	swi 0x200
	bl wait
	ldr r0,=two
	swi 0x200
	bl wait
	ldr r0,=three
	swi 0x200
	bl wait
	ldr r0,=four
	swi 0x200
	bl wait
	ldr r0,=five
	swi 0x200
	bl wait
	ldr r0,=six
	swi 0x200
	bl wait
	ldr r0,=seven
	swi 0x200
	bl wait
	ldr r0,=eight
	swi 0x200
	bl wait	
	ldr r0,=nine
	swi 0x200
	b stop
	
wait:
	sub r1,r1,#1
	cmp r1,#0
	bne wait
	mov r1,#0x20000
	bx lr	
stop:
	swi 0x11