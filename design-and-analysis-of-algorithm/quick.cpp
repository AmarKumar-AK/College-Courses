#include <bits/stdc++.h>
#define SIZE 100
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
} q;

void QuickSort::read()
{
    for (int i = 0; i < SIZE; ++i)
    {
        a[i] = rand() % NUM + 1;
    } //end for
} //end read function
int sum = 0;
void QuickSort::sort(int beg, int end)
{
    if (beg < end)
    {
        int p = partition(beg, end);
        //cout<<"returned p is : "<<p<<endl;
        sort(beg, p - 1);
        sort(p + 1, end);
    } //end if
} //end sort function
int counter = 0;
int QuickSort::partition(int beg, int end)
{
    int i = beg;
    int j = end;
    int pivot = a[beg];
    
    while (i < j)
    {
        while (a[i] <= pivot && i <= end)
        {
            counter++;
            i++;
        }
        while (a[j] > pivot && j > beg)
        {
            counter++;
            j--;
        }
        
        int temp;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            //print();
        }
        
    } //end while
    int temp = a[beg];
    a[beg] = a[j];
    a[j] = temp;
    
    return j;
}


void QuickSort::print()
{
    for (int i = 0; i < SIZE; ++i)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        srand(time(NULL));
        q.read();
        cout<<"unsorted array is : ";
        q.print();
        cout<<endl;
        q.sort(0, SIZE - 1);
        cout<<"sorted array is : ";
        q.print();
        cout<<endl;
        sum = sum + counter;
        counter = 0;
    }

    cout << "avg is : " << sum / 1000 << endl;
}
