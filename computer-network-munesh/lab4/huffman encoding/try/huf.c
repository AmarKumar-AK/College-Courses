#include<stdio.h>
#include<string.h>
struct node{
    char c;
    char encode[10];
};
int main(){
    
    char ch[100];
    printf("enter the code\n ");
    scanf("%s",ch);
    // printf("%s",ch);
    char str[]="a00f01e100b101d110c111";
    //a 00 //f 01 //e 100 //b 101 //d 110 //c 111
    //counting number of characters
    int count=0;
    for(int i=0 ; i<sizeof(str) ; ++i){
        if(str[i]>=97 && str[i]<=122){
            count++;
        }
    }
    struct node n[count];
    int k=0,j;
    // while(j!=strlen(str)){
    //     if(str[j]>=97 && str[j]<=122){
    //         strcpy(n[k].encode,"");
    //         n[k++].c=str[j];
    //         j++;
    //     }
    //     else{
    //         strcat(n[k-1].encode,str[j]);
    //         j++;
    //     }
    //     printf(".");
    // }
    for(int i=0 ; i<strlen(str)-1 ; ++i){
        if(str[i]>=97 && str[i]<=122){
            n[k++].c=str[i];
            j=0;
            printf("\n");
        }
        
        else{
            // j=0;
            // while(str[i]=='0' || str[i]=='1'){
            //     n[k].encode[j++]=str[i++];
            //     // printf("%d ",j++);
            //     // strcat(n[k-1].encode,str[i++]);
            // }
            n[k-1].encode[j++]=str[i];
            printf(".");
            
        }
    }

    // printf("%ld",strlen(str));
    for(int i=0 ; i<count ; ++i){
        printf("%c %s\n",n[i].c, n[i].encode);
    }
    return 0;
}