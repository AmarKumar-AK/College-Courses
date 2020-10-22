#include<stdio.h>
int main()
{
    char dictionary[10][7]={"in","ring","run","hug","it","turn","z","mime","xyz","pqr"};
    char word[7];//="turing";
    printf("enter the char");
    scanf("%s",word);
    printf("these are meaningfull subset of word turing:-\n");
    for(int i=0; i<10; i++)
    {
        int k=0;
        int counter=0;
        for(k=0; dictionary[i][k]!=0; k++)
        {
            for (int j=0; j<7; j++)
            {
                if(word[j]==dictionary[i][k])
                {
                counter+=1;
                }
            }
            
        }
        if(counter==k)
        printf("'%s' ",dictionary[i]);
        
    }

}
