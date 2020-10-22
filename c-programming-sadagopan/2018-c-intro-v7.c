#include<stdio.h>

void main()
{

// %n - count the no of char
int num_char_printed, a, b, c;

printf("counting the number of characters%n", &num_char_printed);

printf("\n the number of characters printed (placed in output stream) is %d \n", num_char_printed);

a=2;
printf("counting%n the%n number %d%d%d of characters \n%n", &a,&b, a,a,a,&c);

printf("\n the value of a=%d, b = %d, c=%d  \n ",a,b,c);

//

printf("enter todays date in format dd-mm,yyy \n");
scanf("%dtext%d,%d",&a,&b,&c);

printf("todays date %d - %d - %d \n", a,b,c);

// scanf("%d\n %d %d\t", ...)

// \t - tab - 8 white spaces - if \t is used in the middle or end - the number of white spaces 3,4,5,8
// \b - backspace
// \r - carriage return - returns the cursor to the front

printf("\n into to '\'t '\'b '\'r \n \n ");

printf("Quiz-1\b");
printf("2Quiz-1\n");

printf("Quiz-1\n\b");
printf("2Quiz-1\r");
printf("3Quiz\n");
printf("shift cursor without overwrite \r \t");
printf("overwrite after shift\n");


printf("display tab space  \t \t ");
printf("\n1234567891234 \n");
printf("\t");


/* printf("\n the value of a=%d, b = %d, c=%d  \r ",a,b,c);
printf("1234567891234111111111111111 \n");

printf(" two back spaces \b\b\n"); // no overwrite  no delete control is shifted by two cells left
printf("craft");
*/
// \n \r \b
// \b \b \r
// \r \b
// \b \t \t 
// \r \b \t

/*
SEQUENCE STATEMENTS

printf, scanf, simple assignments

SELECTION STs

IF/Switch-Case

REPETITION STs

FOR/WHILE

claim: For any solvable problem, there exists a C program using Seq, sel and rep sts.


 




*/
}
