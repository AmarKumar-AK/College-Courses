#include<stdio.h>

//Thursday; 12 -13.00  -- extra credits: Q2 /end sem (3 + 6 =9  --- 6/9) -- one grade up -- 

//15 - 7 + 5 + 3

void main()
{

// float

int a,b,c;
float x,y,z; // float: keyword, x,y,z: identifier (user defined) -- decimal with fractions - real numbers

// control string - format specifier - %d - int  %f - float

printf(" enter two integers \n");
scanf("%d      %d",&a,&b);

// input: 1.2 1 ; a=1 followed by abrupt termination
// input: @ 11 ; abrupt termination  -- why is gcc not printing ASCII(@) ?-- @- not being reco as char by gcc.

printf("\n the value of a=%d b =%d", a,b);

printf("\n enter two flat nos \n");
scanf("%f%f", &x,&y);

printf("\n the value of c = %d", c);

printf("\n the value of c = %f", c);
printf("\n the value of z = %f", z);
printf("\n the value of z = %d", z);



c=a+b;
printf("\n the value of c = %d", c);

printf("\n the value of c = %f  -- in float format", c);
z=x+y;

printf("\n the value of z = %f", z);

printf("\n the value of z = %d -- in decimal format", z);



x=1.1;
y=2.1;
printf("\n the value of x=%f y =%f", x,y); // 1.100000 2.10000
printf("\n the value of a=%f b =%f", a,b); // 1.100000 2.10000

// scanf - input stream   (input pipe )  -- printf -- ouput stream (output)

// mismatch in control specifiers -- print int using %f -- the value from previous output stream is copied onto the current output stream 


// int d=1234 ; d1=1, d2=2 ...


// formatted input/output

printf("\n \n formatted output 1 \n \n ");
printf("\n the value of  x in 18.4 and y in 11.7 x=%18.4f y =%11.7f \n \n ", x,y);
printf("\n the value of  x in 2.4 and y in 11.7 x=%2.4f y =%11.2f \n \n ", x,y);
// 18.4 at least 18 spaces which include 1 place for dot and 4 places for fractions










}
