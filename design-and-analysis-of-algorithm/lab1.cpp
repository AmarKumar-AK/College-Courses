#include <bits/stdc++.h>
#define NUMBERS 100;
using namespace std;

class sorting
{
  private:
    int array[20];

  public:
    void bubbleSort();
    void insertionSort();
    void selectionSort();
};

void sorting::bubbleSort()
{
    int sum = 0;
    for (int k = 0; k < 20; k++)
    {
        //generating random numbers
        int SIZE = 20;
        for (int k = 0; k < SIZE; k++)
            array[k] = rand() % NUMBERS + 1;
        /*cout<<"\nunsorted array is\n";
    for(int k=0 ; k<SIZE ; k++)
        cout<<" "<<array[k];*/

        int i, j, counter = 0;
        //sorting
        for (i = 0; i < SIZE - 1; i++)
        {
            for (j = 0; j < SIZE - i; j++)
            {
                counter++;
                if (array[j] > array[j + 1])
                {
                    //swapping
                    int temp;
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                } //end if
            }     //end inner for
        }         //end outer for
        /*cout<<"\nsorted array using bubbleSort is\n";
    for(int k=0 ; k<SIZE ; k++)
        cout<<" "<<array[k];
    cout<<endl;*/
        sum = sum + counter;
    }
    cout << "comparision in bubble sort=" << sum / 20 << endl;
} //bubbleSort ends

void sorting::insertionSort()
{
    int sum = 0;
    for (int k = 0; k < 20; k++)
    {
        //generating random number
        int SIZE = 20;
        for (int k = 0; k < SIZE; k++)
            array[k] = rand() % NUMBERS + 1;
        /*cout<<"\nunsorted array is\n";
    for(int k=0 ; k<SIZE ; k++)
        cout<<" "<<array[k];*/

        int i, j, counter = 0;
        for (i = 1; i < SIZE; i++)
        {
            for (j = i; j > 0; j--)
            {
                counter++;
                if (array[j - 1] > array[j])
                {
                    //swapping
                    int temp;
                    temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;
                } //end if
            }     //end inner for
        }         //end outer for
        /*cout<<"\nsorted array using insertionSort is\n";
    for(int k=0 ; k<SIZE ; k++)
        cout<<" "<<array[k];
    cout<<endl;*/
        sum = sum + counter;
    }
    cout << "comparision in insertion sort=" << sum / 20 << endl;
} //insertionSort ends

void sorting::selectionSort()
{
    int sum = 0;
    for (int k = 0; k < 20; k++)
    {
        //generating random number
        int SIZE = 20;
        for (int k = 0; k < SIZE; k++)
            array[k] = rand() % NUMBERS + 1;
        /*cout<<"\nunsorted array is\n";
    for(int k=0 ; k<SIZE ; k++)
        cout<<" "<<array[k];*/

        int i, j, max, pos, counter = 0;
        //sorting
        for (i = 0; i < SIZE - 1; i++)
        {
            max = array[0];
            pos = 0;
            for (j = 0; j < SIZE - i; j++)
            {
                counter++;
                if (array[j] > max)
                {
                    max = array[j];
                    pos = j;
                } //end if
            }     //end inner for

            //swapping
            int temp;
            temp = array[SIZE - i - 1];
            array[SIZE - i - 1] = array[pos];
            array[pos] = temp;

        } //end outer for
        /*cout<<"\nsorted array using selectionSort is\n";
    for(int k=0 ; k<SIZE ; k++)
        cout<<" "<<array[k];
    cout<<endl;*/
        sum = sum + counter;
    }
    cout << "comparision in selection sort=" << sum / 20 << endl;
} //selectionSort function ends

int main()
{
    srand(time(NULL));
    class sorting s;
    s.bubbleSort();
    s.insertionSort();
    s.selectionSort();
}