#include<stdio.h>
int main()
{
    int steps=6;
    int previous=1, second_previous=0, next;
    for(int i=0; i<6; i++)
    {
        next=previous+second_previous;
        second_previous=previous;
        previous=next;
    }


    printf("The number of ways : %d\n",previous);
 
  
    int array[6]={1,1,1,1,1,1};

    
    for(int i=0; i<6; i++)
    {
        printf("%d ",array[i]);
    }
    puts("");

    for(int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            array[i]=array[i] + array[5];
            printf("%d ",array[j]);
            array[i]=array[5];
        }
        puts("");
    }


    for(int i=0; i<4; i++)
    {   
        array[i]=array[i]+array[5];
        for(int k=i+1; k<4; k++)
        {
            array[k]=array[k]+array[5];
            for(int j=0; j<4; j++)
            {
                printf("%d ",array[j]);
                array[k]=array[k];
            }
            array[k]=array[5];
            puts("");
        }

        array[i]=array[5];
    } 


    for(int i=0; i<3 ; i++)
    {
        array[i]=array[i]+array[i+1];
        array[i+1]=array[i+1]+array[i+2];
        array[i+2]=array[i+2]+array[i+3];
        for(int j=0; j<3; j++)
        {
            printf("%d ", array[j]);
        }
        puts("");
        break;

    }
    

}
