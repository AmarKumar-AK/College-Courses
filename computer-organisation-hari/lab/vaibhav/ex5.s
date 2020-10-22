mov r2,#0x10000  	@for inner loop which is 1000
mov r0,#2
@mov r0,#1    	@file handle for STDin
@swi 0x6c	@asking user for the multiple

mov r3,#50	@for outer loop which is 10 
mul r1,r0,r3

Ltimer:
	MOV r2,#0x10000 
	MOV r0,#0x02
	SWI 0x201
	BL Stimer

	SUBS r1,r1,#1

	MOV r2,#0x10000 
	MOV r0,#0x01
	SWI 0x201
	BL Stimer

	SUBS r1,r1,#1

	MOV r0,#0
	SWI 0x201
	
	BNE Ltimer
swi 0x11
Stimer:
	SUBS r2,r2,#1
	BNE Stimer
	MOV PC,R14
