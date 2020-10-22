#include <bits/stdc++.h>
#define SIZE 5
#define NUM 50
using namespace std;

class QuickSort
{
    int a[SIZE];

  public:
    void read();
    void sort(int, int);
    int partition(int, int);
    void print();
    int randomNumber(int, int);
}q;

void QuickSort::read()
{
    for (int i = 0; i < SIZE; ++i)
    {
        a[i] = rand() % NUM + 1;
    }//end for
}//end read function

void QuickSort::sort(int beg, int end)
{
    if(beg<end)
    {
        int p=partition(beg,end);
        cout<<"returned p is : "<<p<<endl;
        sort(beg,p-1);
        sort(p+1,end);
    }//end if
}//end sort function
int counter=0;


int QuickSort::partition(int beg, int end)
{
    int i=beg;
    int j=end;
    int k=randomNumber(beg,end);
    int pivot=a[k];
    cout<<"pivot is : "<<a[k]<<endl;
    while(i<j)
    {
        while(a[i]<=a[k] && i<end)
        { 
            counter++;
            i++;
        }
        while(a[j]>a[k] && j>beg)
        {
            counter++;
            j--;
            if(j-1==k && k>=1)
                j--;
        }
        
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
       
    }//end while
    int temp;
    if(i>k && j>k)
    {
        if(a[j]<a[k])
        {
            temp=a[k];
            a[k]=a[j];
            a[j]=temp;
        }
        return j; 
    }
    else if(i<k && j<k)
    {
        if(a[i]>a[k])
        {
            int temp=a[k];
            a[k]=a[i];
            a[i]=temp;
        }
        return i;
    }
    else return k;

}



void QuickSort::print()
{
    for(int i=0 ; i<SIZE ; ++i)
    {
        cout<<a[i]<<" ";
    }
}

int QuickSort::randomNumber(int beg, int end)
{
    return rand()%(end-beg+1)+beg;
}

int main()
{
    srand(time(NULL));
     
    q.read();
    q.print();
    cout<<endl;
    q.sort(0,SIZE-1);
    cout<<"sorted array is : ";
    q.print();
    cout<<endl;
    //cout<<rand_num<<endl;
}
