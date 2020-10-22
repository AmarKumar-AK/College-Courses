#include<stdio.h>

/*
To comment multiple lines - use

gcc performs (i) pre-processing (ii) compilation of the source file (iii) generating assembly code
(iv) converting assembly into object code (v) linking of object files of source, stdio.h and other include files

To get object file of your program - compile your program with -c option - this will exclude preprocessor directives such as stdio.h whose object file will be linked during linking

gcc -c filename.c

the above command will only throw errors if there are syntax errors in the program

if printf statement is misspelled as print then the error will be notified in this phase, instead it will be notified to the user during linking

to perform linking and generate executable file

gcc -o output filename.o

if there is a misprint in printf() or any other user defined function (definition says compute(), however when it is called, it is comput() ) , then the error will be notified now and not during the earlier phase.

instructions within the function will be tested for syntax error during gcc -c but if there is a misprint in the name, then the same will be notified during gcc -o

*/
#include<stdio.h> 
int a=2,b=3,c;


void main()
{

print("welcome to c-programming\n");

comput();
}

compute()
{

printf("the addition %d \n", c=a+b);

}
// gcc -c  generates object file with warnings and no error for 'print' and 'comput()'

// gcc -o  while linking error is displayed - undefined reference to print and comput
