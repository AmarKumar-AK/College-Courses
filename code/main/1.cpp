
/*
#include<iostream>
using namespace std;
int main()
{
	int *pointer;
	pointer=new int;
	
	
	*pointer=24;
	cout<<*pointer<<endl;
	delete pointer;
	cout<<sizeof(pointer)<<endl;
	cout<<sizeof(*pointer)<<endl;
	
}

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i;
    double a[n];
    for(i=0 ; i<n ; i++)
    {
        cin>>a[i];
    }
    double sum;
    for(i=0 ; i<n ; i++)
    {
        sum=sum+a[i];
    }
    cout<<sum;
    return 0;
    
}*/
/*
#include<iostream>
using namespace std;
class Human
{
public:
	static int human_count;//static variable declaration
	 //constructor
	Human()
	{
		human_count++;
	}
	//method
	void display()
	{
		cout<<"there are "<<human_count<<" persons in this program "<<endl;
	}
	
}Amar, Ranjan, Manisha, Satyam, Deepak/*class name*/;//class ends
/*
int Human :: human_count=0;
int main()
{   

	Amar.display();
	cout<<Human::human_count<<endl;
}*/


/*
#include<bits/stdc++.h>
using namespace std;
int main(){
try{
throw "Exception";
int c=10/0;
}catch(const char *a){
cout<<"error has occured"<<endl<<a<<endl;
}
}*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll gcd(unsigned long long int, int);//prototype
ll lcm(unsigned long long int,  int, unsigned long long int);//prototype
int main() {

ll t,i,n,j;
cout<<"enter the number of testcases"<<endl;
cin>>t;
ll hcf;//for storing gcd

for(i=0 ; i<t ; i++) {
	cout<<"enter the number :  ";
	cin>>n;
	ll l=1;//for storing lcm
	for(j=2 ; j<=n ; j++) {
	
		hcf=gcd(l,j);
		
		l=lcm(l,j,hcf);
		
	}
	
	cout<<"lcm is : ";
	printf("%llu\n",l);
}


}

ll gcd(unsigned long long int x, int y) {
if(y==0) return x;
else return gcd(y, x%y);
}

ll lcm(unsigned long long int x, int y,unsigned long long int z) {
ll store=(x*y)/z;
return store;
}*/

//Never give up. Find more ways to fail, eventually you'll succeed.
/*
#include<bits/stdc++.h>
using namespace std;


int main() {
   // printf("%.0lf\n", pow(2., 10000));
    BigNum a=2;
    int b=10000;
    pow(a,b);
    return 0;
}

BigNum pow(BigNum a, int b) {
    if (b == 0) {
        return 1;
    } else if (b & 1) {
        return a*pow(a, b-1);
    } else {
        BigNum x = pow(a, b/2);
        return x*x;
    }
}*/
/*
#include<bits/stdc++.h>
using namespace std;
int main() {

int i = 1, j = 2;

cout << ( i > j ? i : j ) << " is greater." << endl;

}*/
#include<iostream>
#include<cmath>
using namespace std;
int main() {/*
cout<<"maximum value an integer can store is : ";
int a=pow(2,31)-1;
cout<<a<<endl;
 wchar_t w  = L'A'; 
    cout << "Wide character value:: " << w << endl ; 
    cout << "Size of the wide char is:: " << sizeof(w)<<endl;
     // char type array string 
    char caname[] = "geeksforgeeks" ; 
    cout << caname << endl ; 
  
    // wide-char type array string 
    wchar_t waname[] = L"geeksforgeeks" ; 
    wcout << waname << endl; 
  cout<<"length of the string is "<<wcslen(waname)<<endl;
  int i;
  for(i=0 ; i<256 ; i++){
  printf("%d --> %c\n",i,i);
  }
  cout<<endl;
   wchar_t string[] = L"geeksforgeeks,is,for,GEEKS" ; 
  
    wchar_t* internal_state; 
  
    wchar_t delim[] = L"," ; //used for removing something from string
    wchar_t* token  = wcstok(string, delim, &internal_state); 
  
    while (token) 
    { 
        wcout << token << endl; 
        token = wcstok(NULL, delim, &internal_state); 
    } 
    cout<<endl;
    wchar_t string1[] = L"Geeks Are Geeks and For every geeks there are so may geeks"; 
    wchar_t* string2 = wcsstr(string1, L"Are"); 
    wchar_t* string3 = wcsstr(string1, L"are"); 
    wcsncpy(string2, L"-->", 3);
    wcsncpy(string3, L"->>",4); 
    wcout << string1 << endl; */

    
    return 0; 
}



