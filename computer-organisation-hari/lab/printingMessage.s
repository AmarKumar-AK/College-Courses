Mystring: .asciz "Hello World\n"
ldr r0,=Mystring
swi 0x02
swi 0x11