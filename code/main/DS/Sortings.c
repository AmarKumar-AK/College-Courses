#include<stdio.h>
void ISort(int b[],int size);
void Ssort(int b[],int size);
int main()
{
 int n;
 printf("enter the array size \n");
 scanf("%d",&n);
 int a[n];
 printf("enter the integers in array \n");
 for(int i=0;i<n;i++)
 {
   scanf("%d",&a[i]);
 }

 //ISort(a,n);
 Ssort(a,n);
 
 printf("the sorted elements are \n");
 for(int i=0;i<n;i++)
 {
   printf("%d ",a[i]);
 }
printf("\n");
 return(0);
}

void ISort(int b[],int size)
{
  
  for(int i=1;i<size;i++)
  {
    for(int j=i;j>0;j--)
    {
      if(b[j]<b[j-1])
      {
        int temp = b[j];
        b[j]=b[j-1];
        b[j-1]=temp;
      }
      else
      {
        break;
      }
    }
  }
}
void Ssort(int b[],int size)
{
  int max,imax;
  for(int i=1;i<size;i++)
  {
   //find max of aarray with size-i;
    max=b[0];
    imax=0;
    for(int j=0;j<=size-i;j++)
    {
      if(b[j]>max)
      {
        max=b[j];
        imax=j;
      }
    }
    //swap b[imax],b[size-i]
    int temp=b[imax];
    b[imax]=b[size-i];
    b[size-i]=temp;
  }

}


