#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"enter an integer n :  ";
	cin>>n;
	float matrixA[n][n],matrixB[n];
	int i,j,k;
	cout<<"enter n x n matrix\n ";
	for(i=0 ; i<n ; i++)
	{
		printf("enter elements of %dth row\n",i+1);
		for(j=0 ; j<n ; j++)
			cin>>matrixA[i][j];
	}
	
	cout<<"enter n x 1 matrix\n";
	for(i=0 ; i<n ; i++)
		cin>>matrixB[i];	
		
		
	float factor,sum,divisor;
	for(i=0 ; i<n ; i++)
	{
		divisor=matrixA[i][i];
		matrixA[i][i]=1.0;
		for(j=i+1 ; j<n ; j++)
		{
			matrixA[i][j]=matrixA[i][j]/divisor;
		}
		matrixB[i]=matrixB[i]/divisor;
		
		for(k=i+1 ; k<n ; k++)
		{
			factor=matrixA[k][i];
			matrixA[k][i]=0.0;
			for(j=i+1 ; j<n ; j++)
			{
				matrixA[k][j]=matrixA[k][j]-factor*matrixA[i][j];
			}
			matrixB[k]=matrixB[k]-factor*matrixB[i];
		}
		
	}
	/*
	cout<<"the evaluated n x n matrix is \n";
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<n ; j++)
			cout<<matrixA[i][j]<<" ";
		
		cout<<endl;
	}
	cout<<"the evaluated n x 1 matrix is \n";
	for(i=0 ; i<n ; i++)
	{
		cout<<matrixB[i]<<" ";
		cout<<endl;
	}*/
	
	float X[n];
	X[n-1]=matrixB[n-1];
	for(i=n-2 ; i>=0 ; i--)
	{
		sum=0.0;
		for(j=i+1 ; j<n ; j++)
		{
			sum=sum+matrixA[i][j]*X[j];
		}
		X[i]=matrixB[i]-sum;
	}
	cout<<"\nsolution of the given matrix is \n";
	for(i=0 ; i<n ; i++)
		printf("X[%d]=%f\n",i,X[i]);
	
}//main ends
