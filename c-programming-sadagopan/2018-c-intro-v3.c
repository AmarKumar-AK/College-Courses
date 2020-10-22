#include<stdio.h>

// scanf("%d%d",&v1);

//printf(" a=%%d",v1);


// (i) input is a 4-digit number o/p print the number digit-wise 

void main()
{

int a=1234; // a has k digits where k is a fixed integer 

// this logic works fine as long as k is a fixed integer

// i/p: a ; a div 10 ; a mod 10 ( leaves the remainder on a div 10)

int d1=a%10; // 1234 % 10 - remainder - 4 gets stored in d1

int d2=a/1000; // int d=4.1 1234/1000; 1.234 ; d2 gets '1'
int d3=a%1000; // d3=234
int d4=d3/100 ; // 234/100 = 2.34 ; d4=2
int d5=d3%100; // d5=34;
int d6=d5/10; // 34/10=3.4 ; d6=3
int d7=d5%10; // d7=4



printf(" the output of logic 1 %d  %d  %d  %d \n \n", d2,d4,d6,d7);


//logic 2

int x=1234;

int x1=x/1000;  // x1=1

int x2= ( x- x1*1000 )/100; // 1234 - 1000 /100 = 2.34 ; x2=2

int x3=( x - x1*1000 - x2*100 ) / 10 ; // 1234 - 1000 - 2*100 =34/10 ; x3=3

int x4= (x - x1*1000 - x2*100 - x3*10 ) /1 ; // 1234 - 1000 - 200 - 30 /1 = 4

printf("\n \n the output of logic 2 is %d \n  %d \n %d \n %d \n\n", x1,x2,x3,x4);




// logic 3 - variant of logic 1

// d3, d5 - redundant -- use 'a' to overwrite

//int d1=a%10; // 1234 % 10 - remainder - 4 gets stored in d1

int d21=a/1000; // int d=4.1 1234/1000; 1.234 ; d2 gets '1'
a=a%1000; // a=234
int d41=a/100 ; // 234/100 = 2.34 ; d4=2
a=a%100; // a=34;
int d61=a/10; // 34/10=3.4 ; d6=3
a=a%10; // a=4

printf("the output of logic 3 %d %d %d %d \n \n",d21, d41, d61, a);


// logic 4 - variant of logic 3
a=1234;

int d9=a/1000; // int d=4.1 1234/1000; 1.234 ; d2 gets '1'
printf(" %d \t ",d9);  //\t - tab space - 4 spaces/ 5/7/8
a=a%1000; // a=234
d9=a/100 ; // 234/100 = 2.34 ; d4=2
printf(" %d \t ",d9); 
a=a%100; // a=34;
d9=a/10; // 34/10=3.4 ; d6=3
printf(" %d \t ",d9); 
a=a%10; // a=4
printf(" %d \t \n \n",a); 

//a=4
// 10, a=6, a=60, 60

//10 42 40 4

printf(" %d %d %d %d %d %d", 10, a=a+2, a=a*10, a+9, a, a+2);


int w=10, z1=20;  // z=10, w=20 -- swap two variables -- at least 5 diff logics

int p=w;
w=z1;H
z1=p;

w=10, z1=20;

w=w+z1; // w=30
z1=w-z1; // 30-20 = 10
w=w-z1; // 30-10 = 20

printf("w=%d z1=%d",z1,w);  

w=10, z1=20;

w=w*z1; // w=200
z1=w/z1; // 200/20 = 10
w=w/z1; // 200/10 = 20

w=12, z1=13;



// logic 5

a=1234;
printf("\n logic 5 \n \n");
 printf("%d %d %d %d %d", a/1000, (a%1000)/100, (a%100)/10, (a%10), a);


/*
x=x^y
y=x^{1/y}
x=log_y x 

x=2 y=3

x=2^3=8
y=8^{1/3}=2
x= log_2 8 = 3


x=2 y=3

z=3-2=1

x=x+z
y=y-z 

x=x-y
y=x+y
x=y-x

// math.h  log()  
*/


}

// int d1,d2,d3,d4;

//enter a 4-digit number -- on the fly; can you assign the first digit to d1, the second digit to d2, and so on.
