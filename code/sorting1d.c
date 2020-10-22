

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int BSort();//function prototype
int ISort();//function prototype
int SSort();//function prototype
int main()
{
	srand(time(NULL));
	int size[]={10,20,30,40,50};
	int array[50];
	int i,k;
	int counterArray[5];
	printf("No. of elements   BSort comp   ISort comp   SSort comp\n");
	for(k=0;k<5;k++)
	{
				for(i=0;i<size[k];i++)
				{
					array[i]=rand()%100+1;
				}//inner for ends
			
	
			printf("\n");
		/*	printf("\nunsorted array is\n   ");
				for(i=0;i<size[k];i++)
				{ 
					printf("%d ",array[i]);
				}//inner for ends
				printf("\n");*/
			
			
			counterArray[k]=BSort(array,size[k]);
			//for printing the no. of comparision in each type of sorting
			printf("%10d %13d %13d %13d",size[k],BSort(array,size[k]),ISort(array,size[k]),SSort(array,size[k]));
			
			
	}//outer for ends
	
	int sum=0;
			for(int j=0; j<5; j++)
			{
				sum+=(j+1)*10*counterArray[j];
			}
			
	float weighted_mean=(float)sum/(10+20+30+40+50);
	printf("\n\nweighted mean of bubble sort is %f\n",weighted_mean);
}//main function ends

////////////////////////////////////////////////////
int BSort(int array1[],int size)
{
	int k,temp,i;
	int counter1=0;
	for(k=0;k<size-1;k++)
	{
		for(i=1;i<size-k;i++)
		{
		counter1++;
			if(array1[i]<array1[i-1])
			{
			//swapping
				temp=array1[i];
				array1[i]=array1[i-1];
				array1[i-1]=temp;
			}//if ends
		}//inner for ends
	}//outer for ends
	
/*	printf("sorted array using Bubble sort is :\n   ");
	for(i=0;i<size;i++)
	{
	printf("%d ",array1[i]);
	}
	puts("");*/
	return counter1;	
}//BSort function ends 


////////////////////////////////////////////////
int ISort(int array2[],int size)
{

	int i,j,temp;
	int counter2=0;	
	for(i=1;i<=size-1;++i)
	{
		for(j=i;j>0;--j)
		{
		counter2++;
			if(array2[j]<array2[j-1])
			{
			//swapping
				temp=array2[j];
				array2[j]=array2[j-1];
				array2[j-1]=temp;
			}//if ends
			else
			{
				break;
			}//else ends
		}//inner for ends
	}//outer for ends
	
/*	printf("sorted array using Insertion sort is :\n   ");
	for(i=0;i<size;i++)
	{
	printf("%d ",array2[i]);
	}		*/
	return counter2;
}//ISort function ends


/////////////////////////////////////////////////
int SSort(int array3[],int size)
{
	int i,j,temp,imax,max;
	int counter3=0;
	for(i=0;i<size;i++)
	{
		max=array3[0];
		imax=0;
		for(j=1;j<size-i;j++)
		{
		counter3++;
			if(max<array3[j])
			{
				max=array3[j];
				imax=j;
			}
		}
		temp=array3[size-i-1];
		array3[size-i-1]=array3[imax];
		array3[imax]=temp;
		
	}
	
	/*printf("\nsorted array using Selection sort is :\n   ");
	for(i=0;i<size;i++)
	{
	printf("%d ",array3[i]);
	}
	puts("");*/
	
	return counter3;
}//SSort function ends
