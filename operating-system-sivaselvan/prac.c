// // Question 1
// #include<stdio.h>
// void main()
// {
//     int a,b,c;
//     scanf("%d%d%d",&a,&b,&c);
//     if(a==b || b==c || c==a)
//     {
//         printf("1\n");
//     }
//     else
//     {
//         printf("0\n");
//     }
    
// }

// #include<stdio.h>
// void main()
// {
//     int m,n;
//     scanf("%d%d",&m,&n);
//     if((m/n)*n==m)
//     {
//         printf("%d",m/n);
//     }
//     else
//     {
//         printf("0");
//     }
    
// }


// #include<stdio.h>
// int find_even(int k);
// void main()
// {
//     int a,b;
//     scanf("%d",&a);

// }

// #include<stdio.h>
// void main()
// {
//     int a,b;
//     int flag=0;
//     scanf("%d",&a);
//     do
//     {
//         scanf("%d",&b);
//         if(a!=b && b!=-1)
//         {
//             flag=1;
//         }
//     } while (b!=-1);
//     if(flag==0)
//     {
//         printf("0");
//     }
//     else
//     {
//         printf("1");
//     }
    
// }
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// #define size 6
// // int num[size]={0,2,4,6,8,10};
// int count=0;
// int main(){
//     ///////1-5
//     // if(fork() || fork())
//     //     fork();
//     // printf("OS 2019\n");
//     ///////3-8
//     // printf("OS\n");
//     // fork();
//     // printf("course\n");
//     // fork();
//     // printf("2019\n");
//     // fork();
//     // printf("IIITDM\n");
//     //////6
//     // fork();
//     // fork()&&fork()||fork();
//     // fork();
//     // printf("OS\n");
//     // if(fork()){
//     //     if(!fork()){
//     //         fork();
//     //         printf("1\n");
//     //     }
//     //     else{
//     //         printf("2\n");
//     //     }
//     // }
//     // else{
//     //     printf("3\n");
//     // }
//     // printf("4\n");


//     // int i; pid_t pid;
//     // pid=fork();
//     // if(pid==0){
//     //     for(i=0 ; i<size ; i++){
//     //         num[i]*=-i;
//     //         printf("child %d",num[i]);
//     //     }
//     // }
//     // else if(pid>0){
//     //     wait(NULL);
//     //     for(i=0 ; i<size ; i++){
//     //         printf("parent %d",num[i]);
//     //     }
//     // }

    
    
//     fork();
//     count++;
    
//     fork();
    
    
//     printf("%d\n",count);
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// #define ll long long int
// int main(){
//     int key[]={1,1,0,1};
//     char data[100];
//     int Data[100];
//     printf("enter the data : ");
//     scanf("%s",data);

//     for(int j=0 ; j<sizeof(key)/sizeof(key[0])-1 ; ++j){
//         strcat(data,"0");
//     }
//     printf("%s %ld",data,strlen(data));
//     // printf("%ld",sizeof(key)/sizeof(ll));
//     // int i;
//     // for(i=0 ; i<strlen(data) ; ++i){
//     //     // printf("%d",i);
//     //     Data[i]=data[i]-'0';
//     // }
    
//     // for(int i=0 ; i<strlen(data)-sizeof(key)/sizeof(key[0]) ; ++i){
//     //     for(int j=i ; j<i+sizeof(key)/sizeof(key[0]) ; ++j){
//     //         if(Data[i]==0){
//     //             Data[j]
//     //         }
//     //     }
//     // }
//     // for(int i=0 ; i<strlen(data) ; ++i){
//     //     printf("%d",Data[i]);    
//     // }
//     // for(int i=0 ; i<strlen(string) ; ++i){
//     //     printf("")
//     // }
// }

// #include<stdio.h>
// #include<string.h>
// #define SIZE 26
// struct node{
//     char ch;
//     int freq;
//     struct node *left,*right;
//     char encode[100];
// };

// int main(){
//     struct node n[26];
//     char s[100];
//     // int freq[26]={0};
//     printf("Enter the string to encode\n");
//     scanf("%s",s);

//     for(int i=0 ; i<strlen(s) ; ++i){
//         for(char ch='a'; ch<='z'; ch++){
//             if(s[i]==ch){
//                 // freq[(int)(ch-'a')]++;
//                 n.freq[]
//                 break;
//             }
//         }
//     }
//     for(int i=0 ; i<26 ; ++i){
//         if(freq[i]!=0)
//             printf("%c-->%d\n",(char)(i+'a'),freq[i]);
//     }
// }

// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     int n;
//     printf("Enter the number of elements : ");
//     scanf("%d",&n);
//     int a[n];
//     for(int i=0 ; i<n ; ++i){
//         scanf("%d",&a[i]);
//     }
//     // for(int i=0 ; i<n ; ++i){
//     //     printf("%d ",a[i]);
//     // }
    
//         printf("\nparent\n");
//         for(int i=0;i<n/2;++i){
//             for(int j=i;j>=0;--j){
//                 if(a[j]>a[j+1]){
//                 //swapping
//                     int temp=a[j];
//                     a[j]=a[j+1];
//                     a[j+1]=temp;
//                 }
//                 else{
//                     break;
//                 }//else ends
//             }//inner for ends
// 	    }//outer for ends
//         for(int i=0 ; i<n/2 ; ++i){
//             printf("%d ",a[i]);
//         }
//         // printf("\n\n");
//     return 0;
// }
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int SIZE=5;
// int a[5];
// void reads(int SIZE){
    
//     for(int i=0 ; i<SIZE ; ++i){
//         scanf("%d",&a[i]);
//     }
// }

// int partition(int beg,int end){
//     int i = beg;
//     int j = end;
//     int pivot = a[beg];
    
//     while (i <= j)
//     {
//         while (a[i] <= pivot && i <= end)
//         {
//             i++;
//         }
//         while (a[j] > pivot && j > beg)
//         {
//             j--;
//         }
        
//         int temp;
//         if (i < j)
//         {
//             temp = a[i];
//             a[i] = a[j];
//             a[j] = temp;
//         }
//     }
//     int temp = a[beg];
//     a[beg] = a[j];
//     a[j] = temp;
    
//     return j;
// }

// void print(int SIZE){
//     for (int i = 0; i <SIZE; ++i){
//         printf("%d ",a[i]);
//     }
// }

// void sorting(int beg, int end){
//     if (beg < end)
//     {
//         int p = partition(beg, end);
//         sorting(beg, p - 1);
//         sorting(p + 1, end);
//     }
// }

// int main(){
//     reads(SIZE);
//     print(SIZE);
//     printf("\n\n");
//     sorting(0,SIZE-1);
//     print(SIZE);
    
// }
/////////////////////////////////////////////////
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     if(fork() || fork()){
//         fork();
//     }
//     printf("OS 2019\n");
//     return 0;
// }
////////////////////////////////////////////////
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     if(fork()){
//         if(!fork()){
//             fork();
//             printf("1\n");
//         }
//         else{
//             printf("2\n");
//         }
//     }
//     else{
//         printf("3\n");
//     }
//     printf("4\n");

//     return 0;
// }
///////////////////////////////////////////////
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     printf("OS\n");
//     fork();
//     printf("2019\n");
//     fork();
//     printf("IIITDM\n");

//     return 0;
// }
////////////////////////////////////////////////
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     if(fork() && fork()){
//         fork();
//     }
//     if(fork() || fork()){
//         fork();
//         fork();
//     }
//     printf("Hello\n");
//     return 0;
// }
////////////////////////////////////////////////
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     printf("OS");
//     fork();
//     fork();
//     fork();
//     return 0;
// }
////////////////////////////////////////////////
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     fork();
//     fork() && fork() || fork();
//     fork();
//     printf("Hello\n");
//     return 0;
// }
/////////////////////////////////////////////////
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     for(int i=0 ; i<3 ; ++i){
//         fork();
//     }
//     printf("Hello\n");
//     return 0;
// }
/////////////////////////////////////////////////
// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     return 0;
// }
////////////////////////////////////////////////
// #include<stdio.h>
// void sort(char a[]){
    
// }
// void sort(int a[]){

// }
// void sort(float a[]){

// }
// int main(){
//     char a[]={'n', 'c', 'p', 'a', 't'};
//     int b[]={6, 3, 9, 1, 7};
//     float c[]={1.32, 3.71, 0.67, 5.43, 2.91};
//     return 0;
// }

// #include<stdio.h>
// #include<sys/types.h>
// #include<unistd.h>
// int main(){
//     for(int i=0 ; i<3 ; ++i){
//         fork();
//         printf("Hello\n");
//     }
    
//     return 0;
// }

// C program to print the 
// given pattern 

// #include<stdio.h> 
// #include<time.h>
// void pattern(int n) 
// { 
// 	int i,j; 
	
// 	// This is upper half of pattern 
// 	for (i=1; i<=n; i++) 
// 	{ 
// 		for (j=1; j<=(2*n); j++) 
// 		{ 
// 			// Left part of pattern 
// 			if (i<j) 
// 				printf(" "); 
// 			else
// 				printf("*"); 
			
// 			// Right part of pattern 
// 			if (i<=((2*n)-j)) 
// 				printf(" "); 
// 			else
// 				printf("*"); 
// 		} 
// 		printf("\n"); 
// 	} 
	
// 	// This is lower half of pattern 
// 	for (i=1; i<=n; i++) 
// 	{ 
// 		for (j=1;j<=(2*n);j++) 
// 		{ 
// 			// Left part of pattern 
// 			if (i>(n-j+1)) 
// 				printf(" "); 
// 			else
// 				printf("*"); 
				
// 			// Right part of pattern 
// 			if ((i+n)>j) 
// 				printf(" "); 
// 			else
// 				printf("*"); 
// 		} 
// 		printf("\n"); 
// 	} 
// } 

// // main function 
// int main() 
// { 
// 	clock_t st = clock();
// 	pattern(5000); 
//   	printf("%ld\n",(clock()-st)/(CLOCKS_PER_SEC/1000000));
// 	return 0; 
// } 