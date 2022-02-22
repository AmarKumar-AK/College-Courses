# Write a C program to capture the key strokes of capital letters.
## I wrote the similar code which was given in the lab exercise 9,
## In my keylogger.c file, i removed the kernel printing when i was typing any key without pressing shift key
## With pressing shift key, i used if condition to capture only CAPITAL letters
## I didn't change any thing in kbduskemap.h file, i only modified the keylogger.c file in such a way to print only CAPITAL letters in the log file
## For showing output, i opened syslog file in the terminal and in the other terminal, i was typing characters consisting of captial letters, small letters and symbols
