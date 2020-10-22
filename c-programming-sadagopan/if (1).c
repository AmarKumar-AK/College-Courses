#include<stdio.h>
// intro to selection statements / control statements - IF, IF-ELSE, IF-ELSE IF-ELSE, SWITCH-CASE

/*
if(condition)
{
   condition is true, then enter this block
}

else
{
 condition is false, then enter this block
}

else - optional



if
{

}
else if
{

}
else
{

}

*/

void main()
{

int a=2, b=34;

if(a==2) // a=2, this is assignment =;  comparison operator ==

printf("the value of a is %d \n", a);

//if (expression) // expression returns the logical value '1' (true), then enter the if block


//CMP(a,2), if a==2, return '1' else return '0'

printf("enter the value of a \n");

scanf("%d", &a);

if (a==2)

printf("the value of a is %d \n", 2);

else

printf("the value of a is %d \n", a);


if(a=a+2)  // any non-zero assignment returns the logical value '1'; a=32+2=34

printf("the value of a is %d \n", a);

else

printf("the value of a is %d \n", a);



if(a=0) // a=0, zero assignment; return value = '0'   a=5 returns '1' and a=0 returns '0'

printf("inside if");


else

printf("inside else \n");



if(a=5) // this is assignment st;  non-zero assignment; return value = '1'

printf("inside if \n");


else

printf("inside else");


if(a=-4) // this is assignment st; non-zero assignment; return value = '1'

printf("inside if \n");


else

printf("inside else");


/*
ERROR

if(1=1)  // lvalue - l: left,  rvalue - r: right 

// a=b;  a: lvalue  b: rvalue ; lvalue refers to a var name or a location in RAM ; rvalue - expression / some number

printf("checking whether 1 equals 1");

else
printf("inside else");

*/

// if(printf("  "))  // prints spaces - returns the number of white spaces printed which is a non-zero integer - enters if block

// printf("the number of white spaces dispalyed is %d",printf("   "));
// printf("the number of white spaces dispalyed is %d",printf(""));
// if(printf("")); --no white space is displayed - returns '0' - enters else block


if(printf(" today is monday     "))   // printf() - returns the number of characters printed - non-zero integer - enter the if block 
{

printf("printf inside if st \n");

}

else
{
printf("i am inelse block \n");

}

//printf("carriage return %d %d\n", printf("enter"), printf("%d \n",a));

//if(printf("\r"))
//if(printf("\b"))
if(printf("\n"))   // printf() - returns the number of characters printed - non-zero integer - enter the if block 
{

printf("printf inside if st \n");

}

else
{
printf("i am inelse block \n");

}

printf("\n \n  some more exploration  \n \n ");

a=7;

int ;;; // empty declaration

if(a==7); // if(a==7); is interpreted as if(a==7) and if block contains an empty statement ;

// the following two are outside if block and executed as sequence sts

printf("inside if");

printf("the value of a is %d \n", a);


if (a=7); // if is interpreted as assignment followed by execution of ;

printf("\n *******else with a semicolon****** \n");


if(a=8)

{

printf("inside if");

}

else;  // interpreted as else followed by empty else block due to ;  the foll sts are outside else block and executed sequentially.

{
printf("inside else");

}


printf("\n ***if with semi colon , else with semi colon**** \n");

if(3);

else;
printf("else with ; \n");


if(3){;
printf(" if with ; \n");}  // note: block of sts after if
else;
printf("else with ; \n");

/*
ERROR

if(3);    // if block ends here and there is no corresponding else st
printf(" if with ; \n"); // this is a seq st
else;  // this else has no corresponding if and hence error
printf("else with ; \n"); // this is a seq st


*/

a=95;

if(a>=90)
printf("Grade S");
else if(a>=80 && a<90)
printf("Grade A");
else
printf("Grade B");





if(0);   // if(0) { ; } 

//{

//}
//printf("if with 0 \n");

else if (1)
printf("i am in else if \n"); 



else;  

printf("inside else \n");

{

}

if(2)
{
;
;
;
;;;;
printf("if with semicolon \n");
}





//a=4;

//printf("inside if");





if(3){;


}

else;

printf("i am in else");

}
