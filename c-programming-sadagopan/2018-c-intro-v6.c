#include<stdio.h>

void main()
{

// int b=123456789012345678911111111111111111111111111111111111111111111;

// long int - 64 bits // really long int - 128 bits  - //

// formatted output
int a=-123.456789123, b=23; // fixed point representation 23 --- 23.0
int g=0567; // to store octal nos - first number must be '0'
int h=0xf; //to store hexa nos - first two numbers must be '0x'

float x=123.456789123;  // float point representation - approximation - compiler dependent - 123.34 -- 123.34,  123.399999, 123.340000

printf("the value of x with \'18.2\' specifier %18.2f  \n \n", x); // right justified

printf("the value of x with \'18.9\' specifier %18.9f  \n \n", x);

printf("the value of x with \'18.2\' specifier %-18.20f  \n \n", x); // left justified 

printf("the value of x with \'18.2\' specifier %0018.2f  \n \n", x);

printf("the value of x with \'18.2\' specifier %+18.2f  \n \n", x);

printf("the value of x with \'18.2\' specifier -%18.2f  \n \n", x);

printf("size of data type \n \n ");

printf("the value of a in %% i format %d  \t %d \n", g,h); // i - signed arithmetic d - unsigned 

printf("size of int %d \n \n ", sizeof(int));

printf("size of int %d \n \n ", sizeof(sizeof(sizeof(a)))); // check this out -- output: 8 bytes  

printf("size of int %d \n \n ", sizeof(a));  // 4 bytes - 32 bits - 0 to 2^32-1   int a= 2^32+10

printf("size of float %i \n \n", sizeof(float));  // 4 bytes - 32 bits -- float x = 2^32+10

printf("size of char %d \n \n ", sizeof(char)); // 1 byte - 8 bits - 

printf("size of double %d \n \n ", sizeof(double)); // 8 bytes - 64 bits

printf("size of long double %d \n \n ", sizeof(long double)); // 16 bytes - 16*8=128 bits

printf("the value of a with \'8\' specifier %8d  \n \n", a);  // 

printf("the value of a with \'8\' specifier %0d  \n \n", a);

printf("the value of a with \'8\' specifier %-9d  \n \n", a);

printf("the value of a with \'8\' specifier -%9d  \n \n", a);


// formatted input

printf("formatted input \n \n");

int c,d,e,f;

printf("\n enter four integers \n \n");

//scanf("%d %d %d %d", &c,&d,&e,&f);


//printf("\n formatted input -enter four integers \n \n");

//scanf("%0d %1d %3d %4d", &c,&d,&e,&f);  // 4d - at most 4





//printf("\n \n the value of c,d,e,f %d %d %d %d \n \n \n",c,d,e,f);

//scanf("%+2d %1d %1d %1d", &c,&d,&e,&f); -- junk value -- no spl char +, -

//scanf("%-2d %1d %1d %1d", &c,&d,&e,&f);  -- junk value -- no spl char +, -

scanf("%0d %1d %1d %1d", &c,&d,&e,&f); // 0d - equivalent to d 

printf("\n \n the value of c,d,e,f %d %d %d %d",c,d,e,f);


printf("enter a 4-digit number \n \n");


}
