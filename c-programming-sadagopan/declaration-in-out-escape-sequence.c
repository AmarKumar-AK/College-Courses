#include<stdio.h>

// Objective: We shall discuss variable declaration, input and output statements.  Basic arithmetic and formatted input and output will also be discussed in detail.

// To interface with peripherals such as keyboard and monitor, we use 'scanf' and 'printf' which are included in 'stdio.h'

// #include<stdio.h> -- includes the definition for printf and scanf so that on execution, the program can interact with user through keyboard and monitor

// usage of printf and scanf without including stdio.h will throw a warning

// Even if compiler throws a warning message, a.out will be created on compilation

// On error,  a.out will NOT be created instead the compiler executes the previous a.out if exists


void main()
{  


// Declration begins
//float r;  multiple data type declation
//int r;
//int int q;

	float a,b,c;  // declares float variables //float: keyword  a,b,c:identifier
	int n,o,p;
	int number1, number2, result, number_data; 
	int _number, $num;  // can begin with spl char $ and _  @abc !number1
	int a1, $1a;  //can begin with special character $, no other special character is allowed

	int a$b;  // No other special character is allowed
	int INT, Int;  // c language is case sensitive and hence this is valid
	int;;  // empty declaration
	int e,f=e=3;  //int e=f=3;
	int d=5;
	int abcdefghij;  //length of the identifer is at most 31

// int num-data;  // this will throw error as 'hypen' is treated as 'minus'
//int 1b;  // cannot begin with numbers
// int float r;  // multiple data type declaration
//int g=int h=3; // error


// declaration ends -- no declaration is allowed beyond this stage -- some compiler accepts, in principle, compiler must throw an error if declared elsewhere

// adding two float numbers
printf("the \"value\" of \"a=%f\" and \"b=%f\" \n",a,b);

	printf("enter two float numbers \n");  

// \n after printing "enter two float num" the control will be shifted to the next line

	scanf("%f%f",&a,&b); 

// % control string f: float d:int 

	printf("the \"value\" of \"a=%f\" and \"b=%f\" \n",a,b);  // \ : escape sequence

	printf("the value of c before addition (junk value) is %f \n",c);

		c=a+b;

	printf("the addition of \"a=%f\" and \"b=%f\" is %f \n",a,b,c);


// WARNING - ERRONEOUS output -- mismatch between "data type" and "control string"

//the following will result in warning.  Some junk value is printed for 'c' due to mismatch in control string (%d is given for float variable 'c')


	printf("the addition of \"a=%f\" and \"b=%f\" is %d \n",a,b,c);

// Although, the above statement prints junk value for 'c', the contents of memory that store 'c' is unchanged.  This can be verified as follows

	printf("the value of the c after the above erroneous st  is %f \n",c);

// similarly, junk value is printed for d when the control string is %f 

	printf("the int value of \"d= %d \" and float value of \"d= %f \"\n", d,d); 
 

//adding two float numbers and store the result in an integer

	int m=c;  

// 'c' is float and 'm' is int, therefore, the integer part of 'c' is printed and the fraction is ignored.

printf("the value of m=%d \n",m);

printf("*************\n");

// adding two integer numbers

printf("enter two int numbers \n");
scanf("%d %d",&n,&o);

printf("the \"value\" of \"n=%f\" and \"o=%f\" \n",n,o);

printf("the value of m before addition (previous value) is %d \n",m);
m=n+o;

printf("the addition of \"n=%d\" and \"o=%d\" is %d \n",n,o,m);


//adding two integer numbers and store the result in float

c=m;

printf("the value of c= %f \n",c);  //compiler appends zeros after the dot


printf("*************\n");
printf("enter the value of p - may not be asked if you enter float for the above int variable \n"); 
scanf("%d",&p);
printf("the value of p %d\n", p);
///////
// for float variables - try giving int as inputs
//for integer variables - try giving float as inputs
// for integer variables, if we give float, then compiler abruptly stops accepting some more inputs and start executing other instructions.
// suppose 'a' and 'b' are int and while entering the input, if we enter 4.5, then 'a' will be assigned '4' and compiler abruptly terminates without assigning/asking any input for 'b'
// if we enter special characters such as '@', '$', then abrupt termination
// if '2' and '@' entered, then 'a' gets '2' and 'b' gets nothing
// if '@' and '2' entered, then abrupt termination
////////


printf("*** formatted output 1 ******\n");

//int aa1=12345.15611;
//a=12345.9;
a=123.897;

printf("the value of a with format \'18.7\' %18.7f \n",a);

//18.7 - at least 18 places which includes 7 fractions
// for the above input 5 places for decimal part, 1 place for dot, 7 places for fraction and the remaining 5 places will be filled with white spaces.  When the number is printed it is pre-fixed with 5 white spaces
printf("the value of a %f \n", a);

printf("the value of a with format \'2.5\' %2.5f \n",a);

//2.5 appends junk for 5th letter

printf("the value of a with format \'2.1\' %2.1f \n",a);

//2.1 - rounded at 1st digit

printf("the value of \\ a \\ with format \'2.0\' %2.0f \n",a);

//2.0 discard fraction
 

printf("*** formatted output 2 ******\n");

m=123456;
long int n1=5;
printf("the size of int %d \n", sizeof(int));
printf("the size of long int %d \n", sizeof(long int));
printf("the size of float %d \n", sizeof(float));
printf("the size of int %d \n", sizeof(m));

//7d - at least 7 digits in the output //0d - at least 0 digits in the output
printf("the value of m with format \'7d\' %7d \n",m);
printf("the value of m with format \'2d\' %2d \n",m);
printf("the value of m with format \'0d\' %0d \n",m);

printf("the value of c %d \n",c);
printf("the value of c \n",c);
printf("the value of c \n", &c);
printf("the value of c %d\n",&c);

printf("*** formatted output 3 ******\n");

int num_char_printed,y,z1,z2, r=10;

//printf("the number%n of characters is\n%n", &y);
printf("the number%n of characters is\n%n", &y,&z1);
printf("%d %d\n",y,z1);
printf("programming\n%n",&z2);
printf("%d\n",z2);
num_char_printed=printf("programming\n");
printf("%d \n\n",num_char_printed);



printf("*** formatted output 4 ******\n");
printf("display 12 in 6-bit repn prefixed with white spaces %6d \n", 12);
printf("display 12 in 6-bit repn prefixed with white spaces %-6d ", 12);
printf("display 12 in 6-bit repn prefixed with 0's %06d \n", 12);
printf("display +12 with sign %+0d \n", 12);
printf("display -12 with sign %--2d \n", 12); // -- is treated as - and hence the output is left justified
printf("display 12 with r digits %rd \n",12); // a variable 'r' is not valid
printf("display 12 with a space at the beginning %    d \n", 12);
printf("display +12 with sign %+06d \n", 12); // pad zeros
printf("display -12 with sign %-06d after prefix \n\n\n", 12); //left justified
	
// other escape sequences \t \r \b 
printf("123456789\n");
printf("\tintroduction to tab\n\n"); // \t - offers one tab space (equivalent to 8 white spaces)
printf("1234567890123456\n");
printf("\t\tAfter two tab\n\n");
printf("12345678901234567890123456789012345678901234567890\n");
printf("abc\tdef\tghi\n"); // intermediate tab offers '5' white spaces  ; intermediate tab behaves arbitrarily and hence the number of white spaces cannot be predicted 
printf("\t\tc-programming\t"); // the last tab offers '3' white spaces
printf("tab at the end\n\n");
////
printf("\t\tc-programming\t\t\t"); //the last tab offers 3+8+8 white spaces
printf("tab at the end\n\n");
printf("******intro to back space******\n\n");
printf("computational engineering \b");  // \b - backspace
printf("theory and practice \n\n\n");

// if we remove the space after engineering then 'g' will be overwritten by 't' in theory as the following example says
printf("computational engineering\b");  // \b - backspace
printf("theory and practice \n\n\n");

////

printf("computational engineering \b\b");  // moves two characters left from the current place which means the cursor will be at 'g' - space followed by the letter 'g'
printf("theory and practice \n\n\n");

printf("about the escape sequence slash 'r'\n\n");

printf("theory\r");  // \r - move the cursor to the front 
printf("lab\n\n\n");  // overwrites 'the' in theory with 'lab'

printf("theory \r");  // \r - move the cursor to the front 
printf("laboratory\n\n");  // overwrites 'theory' with 'laborat'

printf("12345678901234567890123456789012345678901234567890\n");

printf("welcome to c\ttheory and practice \t\n");  // middle \t offers 4 spaces and the last \t offers 3 spaces

printf("welcome to c \ttheory and practice \r");
printf("overwrite\n\n");

////

printf("welcome to c \t theory and practice \r "); // there is a space after 'r' which overwrites 'w' and 'overwrite' is written on 'elcome to'
printf("overwrite\n\n\n");

////
printf("welcome to c \ttheory and practice\r\t"); // after printing it moves the cursor to the front and due to \t it shifts the cursor after 8 places ; note that the usage of \t depends on the context.  If used inside the string, then it introduces white spaces depending on the position.  If used along with \r then it shifts the control but does not introduce white spaces.

// After shifting the control to the 8th place, the cursor is at the beginning of 'to' and since the middle \t offers 4 white spaces, it overwrites the 't' in theory
printf("overwrite\n");   //




printf("theory1\r\t");  // \r - move the cursor to the front and shift the cursor after 8 places
printf("lab \n");
printf("something \r");
printf("practice\n");

printf("\b\btheory3 \r\b\b");
printf("abc \n");
printf("*****************************\n\n");
printf("12345678901234567890\n");
printf("the effect\tof escape sequences\r\n\b");
printf("abcdefg\n\n");
printf("the effect\tof escape sequences\b\r");
printf("abcdefg\n\n");

// NOTE
/*
1. \t \r - tab space + shift control to the front
2. \r \t - shift control to the front + shift again the control by 8 places without introducing white spaces
3. \r \b - 'b' has no effect; it is same as \r
4. \r \n - control to the next line ; \r has no effect
5. \r \n \b - new line
6. \r \b \n - newline
7. \b \r - same as \r

*/

printf("*** formatted input 1 ******\n");

int x,z;
printf("enter the value for \'x\' and \'z\' \n");
scanf("%3d \t %d", &x,&z);
printf("the value of x=%d, z=%d \n",x,z);
printf("enter the date in dd/mm/yy\n");
scanf("%d/%d/%d",&x,&y,&z);
printf("entered date %d/%d/%d \n", x,y,z);

printf("enter the date in dd-mm-yy\n");
scanf("%d-%d-%d",&x,&y,&z);
printf("entered date %d-%d-%d \n", x,y,z);








}
