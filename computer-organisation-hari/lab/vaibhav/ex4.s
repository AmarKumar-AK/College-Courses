mov r2,#5  	@for inner loop which is 1000
@mov r0,#1    	@file handle for STDin

@swi 0x6c	@asking user for the multiple

mov r0,#2

mov r3,#2	@for outer loop which is 10 
mul r1,r0,r3

Ltimer:
	MOV r2,#5
	BL Stimer
	SUBS r1,r1,#1
	BNE Ltimer
swi 0x11
Stimer:
	SUBS r2,r2,#1
	BNE Stimer
	MOV PC,R14



