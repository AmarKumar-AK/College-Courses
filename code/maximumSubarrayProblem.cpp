#include<bits/stdc++.h>
using namespace std;

class DNASequence{
    private:
	char son[100];
	char father[100];
    public:
	int bruteForce(int array[], int arrayLength);
	int incDesign(int array[], int arrayLength);
	int divideNConquer(int a[],int beg, int end);
	int prunning(int array[], int arrayLength);
};


int DNASequence::bruteForce(int array[], int arrayLength){
    int mSum = 0;
    int si = 0;
    int fi=0;
    for(int i=0; i<arrayLength; i++){
	for(int j=i; j<arrayLength; j++){
	    int sum = 0;
	    for(int k=i; k<j; k++){
		sum+=array[k];
	    }
	    if(mSum<sum){
		mSum = sum;
		si = i;
		fi = j;
	    }
	}
    }
    
    cout<<"The Solution Array: ";
    for(int i=si; i<=fi; i++){
    	if(array[i]==2){
	    	cout<<"A";
		}
		else if(array[i]==1){
			cout<<"C";;
		}
		else if(array[i]==-1){
			cout<<"G";
		}
		else if(array[i]==-2){
			cout<<"T";
		}
    }
    cout<<endl;
    return mSum;
}

int DNASequence::incDesign(int array[], int arrayLength){
    int mSum = 0;
    for(int i=0; i<arrayLength; i++){
	int sum = 0;
	for(int j=i; j<arrayLength; j++){
	sum+=array[j];
	}
	if(mSum<sum){
	    mSum = sum;
	}
    }

    return mSum;
}

int DNASequence::divideNConquer(int a[],int beg, int end){
    if(beg == end){
	if(a[beg]<0){
	    return 0;
	}
	else{
	    return(a[beg]);
	}
    }

    int mid = (beg+end)/2;
    int left = divideNConquer(a,beg,mid);
    int right = divideNConquer(a,mid+1,end);

    int rosum=0, losum=0, rsum=0;

    for(int i=mid; i<end; i++){
	rsum+=a[i];
    }
    if(rsum>rosum){
    rosum=rsum;
    }

    int lsum=0;
    for(int i=mid-1; i>beg; i--){
	lsum+=a[i];
    }
    if(rsum>rosum){
	losum=lsum;
    }

    int msum = rosum + losum;
    if(losum>rosum && losum>msum){
	return losum;
    }
    else if(rosum>losum && rosum>msum){
	return rosum;
    }
    else{
	return msum;
    }
}

int DNASequence::prunning(int array[], int arrayLength){
    int msum = 0;
    int csum = 0;
    for(int i=0; i<arrayLength; i++){
    	csum+=array[i];
    	if(csum<0){
    		csum = 0;
    	}
    	if(csum>msum){
    		msum = csum;
    	}
    }
    return msum;
}

int main(){
    cout<<"Enter the String length: ";
    int x;
    cin>>x;
    char son[x+1], father[x+1];
    cin>>son;
    cin>>father;
    cout<<son<<endl;
    cout<<father<<endl;
    int sonA[x], fatherA[x];
    for(int i=0; i<x; i++){
	if(son[i]=='A'){
	    sonA[i]=2;
	}
	else if(son[i]=='C'){
	    sonA[i]=1;
	}
	else if(son[i]=='G'){
	    sonA[i]=-1;
	}
	else{
	    sonA[i]=-2;
	}
    }
    
    for(int i=0; i<x; i++){
	if(father[i]=='A'){
	    fatherA[i]=2;
	}
	else if(father[i]=='C'){
	    fatherA[i]=1;
	}
	else if(father[i]=='G'){
	    fatherA[i]=-1;
	}
	else{
	    fatherA[i]=-2;
	}
    }
    
    // Printing the array:
    for(int i=0; i<x; i++){
	cout<<sonA[i];
    }
    cout<<endl;
    for(int i=0; i<x; i++){
	cout<<fatherA[i];
    }
    cout<<endl;
    
    DNASequence sonFather;
    
    cout<<"Calling the bruteForce technique"<<endl;
    int sb = sonFather.bruteForce(sonA, x);
    int fb = sonFather.bruteForce(fatherA, x);
    
    if(abs(sb-fb)<10){
	cout<<"TRUE"<<endl;
    }
    else{
	cout<<"FALSE"<<endl;
    }

    cout<<"Calling the incDesign technique"<<endl;
    int si = sonFather.incDesign(sonA, x);
    int fi = sonFather.incDesign(fatherA, x);
    
    if(abs(si-fi)<10){
	cout<<"TRUE"<<endl;
    }
    else{
	cout<<"FALSE"<<endl;
    }

    cout<<"Calling the DivideNConquer technique"<<endl;
    int sd = sonFather.divideNConquer(sonA,0, x);
    int fd = sonFather.divideNConquer(fatherA,0, x);

    if(abs(sd-fd)<10){
	cout<<"TRUE"<<endl;
    }
    else{
	cout<<"FALSE"<<endl;
    }
    
    cout<<"Calling the Prunning technique"<<endl;
    int sp = sonFather.prunning(sonA,x);
    int fp = sonFather.prunning(fatherA,x);

    if(abs(sp-fp)<10){
	cout<<"TRUE"<<endl;
    }
    else{
	cout<<"FALSE"<<endl;
    }
}

