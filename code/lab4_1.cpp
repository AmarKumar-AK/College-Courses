#include<iostream>
#include<stdlib.h>
using namespace std;
// making a class
class qs{
	private:
		int a[100] ;
		double counter ; 
	public:
		int n ; 
		void cset() ; 
		void quickSort(int b ,int e) ; 
		void setter() ; 	
		int sorter(int b, int e) ; 
		void swap(int a, int b) ; 
		void print() ; 
		void result() ; 
} ; 

//setting the counter

void qs::cset(){
	counter = 0 ; 
}


//assigning values
void qs::setter(){
	//counter = 0 ; // resetting the counter
	//cout<<"Please enter the number of inputs:\n" ; 
	//cin>>n ;
	n=100 ;  
	cout<<"An array with "<<n<<" random numbers is generated\n" ; 
	for(int i=0 ; i<n ; i++){
		a[i] = rand()%200 ; 
	}
	for(int i=0 ; i<n ; i++){
		cout<<a[i]<<" " ; 
	}
	cout<<"\n" ; 
}

//creating the quick sort function]

void qs::quickSort(int b, int e){
	if(e>b){
		int j = sorter(b,e) ; 
		quickSort(b,j-1) ; 
		quickSort(j+1,e) ; 
	}
}

int qs::sorter(int b, int e){
	int p = a[b] ; 
	int i=b ; 
	int j = e ; 
	while(i<j){
		counter+= 1; 
		while(a[i] <=p && i<e){
			i++ ; 
		}
		counter+= 1	; 
		while(a[j] > p && j>b){
			j-- ; 
		}
		if(j>i){
			swap(i,j) ; 
		}
	}
	swap(b,j) ; 
	return j ; 
}

//making the swap function

void qs::swap(int i,int j){
	int temp = a[i] ; 
	a[i] = a[j] ; 
	a[j] = temp ; 
}

// the print function to view the final result

void qs::print(){
	cout<<"The sorted array is:\n" ; 
	for(int i=0  ;i<n ; i++){
		cout<<a[i]<<" " ; 
	}
	cout<<"\n" ; 
}

//the average number of key operations

void qs::result(){
	cout<<"\n\nThe time complexity is: "<<(counter/1000)<<"\n" ; 
}

// main function

int main(){
	qs t ; 
	t.cset() ; 
	for(int i=0 ; i<1000 ; i++){
		t.setter() ;
		t.quickSort(0,(t.n)-1) ;
		t.print();
	}	
	t.result() ; 
	return 0 ; 
} 
