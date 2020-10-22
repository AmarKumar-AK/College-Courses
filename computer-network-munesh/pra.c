// #include<stdio.h>



// char xor(int a[], int b[],int size_b)
// {
//     char ch[32];
//     for(int i=0 ; i<size_b ; ++i)
//     {
//         if(a[i]==b[i])
//         {
//             ch[i]='0';
//         }
//         else
//         {
//             ch[i]='1';
//         } 
//     }
//     printf("%s",ch);
// }


// int main()
// {
//     int a[4]={1,0,0,1};
//     int b[4]={1,1,0,1};
//     char *x;
//     xor(a,b,4);
//     // printf("%s",x);
// }
#include<stdio.h>
int main(){
    char buff[255];
    FILE *fp;
    fp=fopen("text.txt","r");
    while(fscanf(fp, "%s", buff)!=EOF)
    {
        // fscanf(fp,"%s",buff);
        printf("%s",buff);
    }
    
    fclose(fp);
}