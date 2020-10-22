
//introduction to pointers
#include<stdio.h>
#include<stdlib.h>
void can_change_both(int *ptramar);//
void can_change_data(int *const ptramar);//
void can_change_ptr(const int *ptramar);//
void cannot_change_both(const int *const ptramar);//
void main()
{
	/*int x=5;
	int y=6;
	
	int *px=&x;
		int *py;
		py=&y;
					int **pxx;
					pxx=&px;
	int **pyy=&py;
	printf("the address of x is : %p\n",px);
	printf("the value of x is : %d\n",x);
	printf("the value of **pxx is : %d\n",**pxx);
	printf("the value of &x is : %p\n",&x);
	
	puts("");
	
	printf("the address of y is : %p\n",&y);
	printf("the value of y is : %d\n",*py);
	printf("the value of **pyy is : %d\n",**pyy);
	printf("the value of &&y is : %p\n",&py);*/
	////////////
	//int *ptrx=&x;
//	int *ptry=&y;
	//ptrx=&x;
	/*z=x+y;
	int *ptrz=&z
	
	
	printf("this is z : %d",z);
	printf("this is address of z : %p,ptrz");
	
	printf("%p\n",ptrx);
	printf("%p\n",&ptrx);
	printf("%d\n",*ptrx);
	printf("%p\n",ptrx++);
	printf("%p\n",++ptrx);
	printf("%d\n",sizeof(ptrx));*/
//////////////////////////////////////////////////////////////////////////////////////////	
	//int amar=5;
	//int *ptramar=&amar;
//	can_change_both(&amar);
	//printf("the new value of amar is %d\n",*ptramar);
	//printf("the new address of amar is %p\n",&amar);
//	can_change_data(&amar);
	//printf("the new value of amar is %d\n",*ptramar);
	//printf("the new address of amar is %p\n",&amar);
//	can_change_ptr(&amar);
	//printf("the new value of amar is %d\n",*ptramar);
	//printf("the new address of amar is %p\n",&amar);
//	cannot_change_both(&amar);
	//printf("the new value of amar is %d\n",*ptramar);
	//printf("the new address of amar is %p\n",&amar);
	
	
	int arr[]={1,2,4,5,6};
	int *ptr=arr;
	ptr++;
	
	printf("%p\n",arr);
	printf("%d\n",*ptr);
	printf("%d\n",arr[0]);
	
}//main function ends

/*
void can_change_both(int *ptramar)
{
	*ptramar=10;
	int new_amar=20;
	ptramar=&new_amar;
	
}//can_change_both function ends

void can_change_data(int *const ptramar)
{
	*ptramar=10;
	int new_amar=20;
	ptramar=&new_amar;
}

void can_change_ptr(const int *ptramar)
{
	*ptramar=10;
	int new_amar=20;
	ptramar=&new_amar;
}

void cannot_change_both(const int *const ptramar)
{
	*ptramar=10;
	int new_amar=20;
	ptramar=&new_amar;
}
*/
K.N. KING c programming-Amodern approach
