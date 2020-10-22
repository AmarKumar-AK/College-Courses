#include <bits/stdc++.h>
#define SIZE 100
#define NUM 50
using namespace std;

class RandomQuickSort
{
	int a[SIZE];

  public:
	void read();
	void sort(int, int);
	int partition(int, int);
	void print();
	int randomNumber(int, int);
} q;

void RandomQuickSort::read()
{
	for (int i = 0; i < SIZE; i++)
	{
		a[i] = rand() % NUM + 1;
	} //end for
} //end read function
int sum = 0;
void RandomQuickSort::sort(int beg, int end)
{
	if (beg < end)
	{
		int p = partition(beg, end);
		//cout<<"returned p is : "<<p<<endl;
		sort(beg, p - 1);
		sort(p + 1, end);
	} //end if
} //end rqsort function
int counter = 0;
int RandomQuickSort::partition(int beg, int end)
{
	int i = beg;
	int j = end;
	int k = randomNumber(beg, end);
	int pivot = a[k];

	while (i < j)
	{
		while (a[i] <= pivot)
		{
			counter++;
			if (i == k)
				break;
			i++;
		}
		while (a[j] > pivot)
		{
			counter++;
			if (j == k)
				break;
			j--;
		}

		if (i < k && j > k)
		{

			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else
		{
			if (i == k && j != k)
			{

				int temp = a[k];
				a[k] = a[j];
				a[j] = temp;
				k = j;
			}//end inner if
			else if (i != k && j == k)
			{
				int temp = a[k];
				a[k] = a[i];
				a[i] = temp;
				k = i;
			}//end else if
		}//end else
	}//end while
	return k;
}
void RandomQuickSort::print()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int RandomQuickSort::randomNumber(int beg, int end)
{
	return (rand() % (end - beg + 1) + beg);
}

int main()
{
	for (int i = 0; i < 1000; i++)
	{
		srand(time(NULL));
		q.read();
		//cout<<"unsorted array is : ";
		//q.print();
		//cout<<endl;
		q.sort(0, SIZE - 1);
		//cout<<"sorted array is : ";
		//q.print();
		cout<<endl;
		sum = sum + counter;
		counter = 0;
	}

	cout << "avg is : " << sum / 1000 << endl;
}
