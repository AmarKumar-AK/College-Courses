#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int SIZE=5;
int a[5];
void reads(int SIZE){
    
    for(int i=0 ; i<SIZE ; ++i){
        scanf("%d",&a[i]);
    }
}

int partition(int beg,int end){
    int i = beg;
    int j = end;
    int pivot = a[beg];
    
    while (i <= j)
    {
        while (a[i] <= pivot && i <= end)
        {
            i++;
        }
        while (a[j] > pivot && j > beg)
        {
            j--;
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

void print(int SIZE){
    for (int i = 0; i <SIZE; ++i){
        printf("%d ",a[i]);
    }
}

void quickSort(int beg, int end){
    if (beg < end)
    {
        int p = partition(beg, end);
        quickSort(beg, p - 1);
        quickSort(p + 1, end);
    }
}

int main(){
    reads(SIZE);

    pid_t pid;
    pid=fork();

    if(pid>0){
        printf("\nparent\n");
        quickSort(0,SIZE-1);
        print(SIZE);
    }
    else if(pid==0){
        printf("\nchild\n");
        quickSort(0,SIZE-1);
        print(SIZE);
    }
}
