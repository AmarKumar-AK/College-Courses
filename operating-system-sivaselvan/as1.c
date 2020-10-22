#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void reads(int size,int a[]){
    
    for(int i=0 ; i<size ; ++i){
        scanf("%d",&a[i]);
    }
}

int partition(int beg,int end,int a[]){
    int i = beg;
    int j = end;
    printf("beg=%d\tend=%d\n",beg,end);
    int pivot = a[beg];
    
    while (i <= j)
    {
        while (a[i] <= pivot && i <= end)
        {
            printf("a[i]=%d\tpivot=%d\n",a[i],pivot);
            i++;
            printf("i=%d\n",i);
        }
        while (a[j] > pivot && j > beg)
        {
            j--;
            printf("j = %d\n",j);
        }
        
        int temp;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        
    }
    int temp = a[beg];
    a[beg] = a[j];
    a[j] = temp;
    
    return j;
}

void print(int size,int a[]){
    for (int i = 0; i <size; ++i){
        printf("%d ",a[i]);
    }
}

void sorting(int beg, int end, int a[]){
    if (beg < end)
    {
        int p = partition(beg, end, &a);
        sorting(beg, p - 1, &a);
        sorting(p + 1, end, &a);
    }
}

int main(){
    int size;
    printf("enter the size of array : ");
    scanf("%d",&size);
    int a[size];
    // int *p=&a;
    reads(size,&a);
    print(size,&a);
    printf("\n\n");
    sorting(0,size-1,&a);
    print(size,&a);
    // for(int i=0 ; i<size ; ++i){
    //     printf("%d ",a[i]);
    // }

    
}