#include<bits/stdc++.h>
using namespace std;


class Search{
	private:
		int array[100];
	public:
		int linearSearch(int array[], int x, int arrayLength);
		int binarySearch(int array[], int x, int high, int low);
		int insertionSort(int array[], int n);
};

int Search::linearSearch(int array[], int x, int arrayLength){
	int count=0;
	int found=0;
	for(int i=0; i<arrayLength; i++){
		count++;
		if(array[i]==x){
			found=1;
			break;
		}
	}
	return count;
}

int Search::binarySearch(int array[], int x, int low, int high){
int bCount = 0;
	while(high >= low){
		bCount++;
		int mid = (high + low)/2;
		//cout<<"The value of mid is : "<<mid<<endl;
		if(array[mid]==x){
			break;
		}
		else if(x < array[mid]){
			high = mid -1;
		}
		else{
			low = mid + 1;
		}
	}
	return bCount;
	
}


int Search::insertionSort(int array[], int n){
  for(int i=1; i<n; i++){
    for(int j=i; j>0; j--){
      if(array[j]<array[j-1]){
	int temp = array[j];
	array[j] = array[j-1];
	array[j-1] = temp;
      }
    }
  }
}

int main(){
	srand(time(NULL));
	Search searchAnalysis;
	int a[100];
	int lc[1000];
	int bc[1000];
	
	cout<<"------------------------------------------------------------------------------"<<endl;
	cout<<"Input Size" <<"      "<<"Linear     "<<"Binary"<<endl;
	cout<<"------------------------------------------------------------------------------";
	for(int j=0; j<1000; j++){
	
		//cout<<"Entering the value in array"<<endl;
		
		  for(int i=0; i<100; i++){
		    a[i]=rand()%100 + 1;
		  }
		  int searchFor = rand()%100 +1;
		  
		  //cout<<"The value seaching for : "<<searchFor<<endl;
		  
		  //cout<<"Running linear search"<<endl;
		  
		  int linearCount = searchAnalysis.linearSearch(a, searchFor, 100);
		  
		  //cout<<"Running insertion sort"<<endl;
		  
		  int compInsertion = searchAnalysis.insertionSort(a, 100);
		  
		  //cout<<"Printing the sorted Array"<<endl;
		  
		  //for(int i=0; i<100; i++){
		//	cout<<a[i]<<" ";
		//	}
		 // cout<<endl;
		  
		  //cout<<"Running binary search"<<endl;
		  
		  int binaryCount = searchAnalysis.binarySearch(a,searchFor, 0, 100);
		  
		  cout<<"    100   " <<"          "<<linearCount<<"      "<<binaryCount<<endl;
		  
		  lc[j] = linearCount;
		  bc[j] = binaryCount;
	}
	
	float lsum = 0.0; float bsum = 0.0;
	
	for (int i=0; i<1000; i++){
		lsum+=(float)lc[i];
		bsum+=(float)bc[i];
	}
	
	cout<<"------------------------------------------------------------------------------";
	cout<<"  Average  " <<"          "<<lsum/1000<<"      "<<bsum/1000<<endl;
	cout<<"------------------------------------------------------------------------------"<<endl;
}
