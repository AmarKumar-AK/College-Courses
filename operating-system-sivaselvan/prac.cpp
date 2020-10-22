
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n,k;
//     // cout<<"enter value of n and k"<<endl;
//     cin>>n>>k;
//     int arr[n];
//     // cout<<"enter the numbers"<<endl;
//     for(int i=0 ; i<n ; ++i)
//         cin>>arr[i];


//     for(int i=0 ; i<k ; ++i)
//     {
//         sort(arr,arr+n);
//         arr[n/2]+=1;
//     }
//     sort(arr,arr+n);
//     // cout<<"largest median is"<<endl;
//     cout<<arr[n/2]<<endl;

// }

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"enter the value of n"<<endl;
//     cin>>n;
//     int arr[n];
//     cout<<"enter the elements of array"<<endl;
//     for(int i=0 ; i<n ; ++i)
//         cin>>arr[i];
//     // variable maximum and minimum is to find the maximum and minimum element of the array not including 0
//     int maximum;
//     int minimum;
//     // variable count is for counting the number of non-zero element in the array
//     int count=n;
//     while(count!=0 || count!=1)
//     {
//         count=n;
//         // sorting whole array
//         sort(arr,arr+n);
//         // maximum is last element of the sorted array
//         maximum=arr[n-1];
//         // variable index is for finding the index of minimum element
//         int index;
//         // for finding minimum
//         for(int i=0 ; i<n ; ++i)
//         {
//             if(arr[i]!=0)
//             {
//                 minimum=arr[i];
//                 index=i;
//                 break;
//             }
//         }
//         // decreasing 1 from largest element
//         arr[n-1]--;
//         // decreasing 1 from least element which is greater than zero
//         arr[index]--;
//         // printing each element of the array after decreasing 1 from both minimum and maximum
//         for(int i=0 ; i<n ; ++i)
//         {
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//         // checking if count of non-zero element decreased or not
//         for(int i=0 ; i<n ; ++i)
//         {
//             if(arr[i]==0)
//             {
//                 count=count-1;
//             }
//         }
//         // if count is zero, it means all elements are 0
//         if(count==0)
//         {
//             cout<<"Yes";
//             break;
//         }
//         // if count is one, it means one element is non zero
//         else if(count==1)
//         {
//             cout<<"No";
//             break;
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin>>t;
//     string s1,s2;
//     int j,k;
//     for(int i=0 ; i<t ; ++i)
//     {
//         int count=0;
//         cin>>s1>>s2;
//         for(j=0 ; j<s1.size() ; ++j)
//         {
//             for(k=0 ; k<s2.size() ; ++k)
//             {
//                 if(s1[j]==s2[k] && s1[j]!=' ' && s2[k]!=' ')
//                 {
//                     s1[j]=' ';
//                     s2[k]=' ';
//                     count+=2;
//                     cout<<"j = "<<j<<endl<<"k = "<<k<<endl;
//                     cout<<"amar"<<endl;
//                 }
//                 else if(s1[j]!=s2[k])
//                 {
//                     continue;
//                 }
//             }
//             cout<<"j = "<<j<<endl<<"k = "<<k<<endl;
//         }
//         cout<<count<<endl<<s1.size()+s2.size()<<endl;
//         if(s1.size()+s2.size()==count)
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int numberOfBits(int);
// int main()
// {
//     ll t;
//     scanf("%lld",&t);
//     ll x[t];
//     ll count;
//     for(int i=0 ; i<t ; ++i)
//     {
//         scanf("%lld",&x[i]);
//         count=0;
//         if(x[i]==0)
//         {
//             cout<<0<<endl;
//         }
//         else if(x[i]==1)
//         {
//             cout<<1<<endl;
//         }
//         else
//         {
//             int index;
//             for(int d=1 ; d<=sqrt(x[i])+1 ; ++d)
//             {
//                 if(numberOfBits(x[i]/d)>=numberOfBits(x[i]));
//                 {
//                     index=d;
//                     break;
//                 }
//             }
//             cout<<x[i]-index<<endl;
//         }



//     }
// }

// int numberOfBits(int x)
// {
//     return (1+log2(x));
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string str={'5'};
//     int val=str[0]-'0';
//     cout<<val+1;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int i, j;
//     int power1=0,power2=0;
//     int m=8,n=8;
//     int a[9][9];
//     for (i = power1; i <= n; i++)
//     {
//         for (j = power2; j <= m; j++)
//         {
//             if(i==0 || i==8 || j==0 || j==8)
//                 a[i][j]=0;
//             else if(i==1 || i==7 || j==1 || j==7)
//                 a[i][j]=1;
//             else if (i==2 || i==6 || j==2 || j==6)
//                 a[i][j]=2;
//             else if (i==3 || i==5 || j==3 || j==5)
//                 a[i][j]=3;
//             else if (i==4 || j==4)
//                 a[i][j]=4;
//         }
//         // cout << endl;
//     }
//     for(int i=0 ; i<9 ; ++i)
//     {
//         for(int j=0 ; j<9 ; ++j)
//         {
//             cout<<a[i][j];
//         }
//         cout<<endl;
//     }
// }

// #include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using namespace std;

// int128_t boost_product(long long A, long long B)
// {
//     int128_t ans = (int128_t) A * B;
//     return ans;
// }

// int main()
// {
//     long long first = 98745636214564698;
//     long long second=7459874565236544789;
//     cout << "Product of "<< first << " * "
//          << second << " = \n"
//          << boost_product(first,second) ;
//     return 0;
// }

// #include<bits/stdc++.h>
// #define l long int
// #define loop(a,b,c) for(i=a ; i<b ; i=i+c)
// using namespace std;
// int main()
// {
//     l n,i;
//     cin>>n;
//     l a[n];
//     l sum[n];
//     // sum[0]=0;
//     for(i=0 ; i<n ; ++i)
//     {
//         cin>>a[i];
//     }
//     for(i=0 ; i<n ; ++i)
//     {
//         sum[i]=sum[i]+a[i];
//         cout<<sum[i]<<" ";
//     }
// }

// #include<iostream>
// using namespace std;
// int main()
// {
//     int L;
//     cin>>L;
//     int C=1;
//     bool FOUND=false;
//     for(int i=0 ; i<9 ; i++)
//     {
//         int x;
//         cin>>x;
//         if(L==x)
//         {
//             C++;
//             if(C==3)
//             {
//                 FOUND=true;
//                 break;
//             }
//             L=x;
//         }
//         else
//         {
//             L=x;
//             C=1;
//         }

//     }

//     if(FOUND) cout<<1<<endl;
//     else cout<<0<<endl;
// }

// #include<bits/stdc++.h>
// using namespace std;

// template<typename T>
// T minimum(T x,T y)
// {
//     return (x<y)?x:y;
// }


// int main()
// {
//     cout<<minimum<string>("amar","kumar")<<endl;

//     return 0;
// }


// #include <iostream>
// using namespace std;

// template<int n> struct funStruct
// {
//     enum { val = 2*funStruct<n-1>::val };
// };

// template<> struct funStruct<0>
// {
//     enum { val = 1 };
// };

// int main()
// {
//     cout << funStruct<8>::val << endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n=123;
//     int count_number_of_digits=0;
//     int arr[count_number_of_digits];
//     while(n!=0)
//     {
//         arr[count_number_of_digits++]=n%10;
//         n/=10;
//     }
//     cout<<count_number_of_digits<<endl;
//     int sum=0;
//     for(int x=0 ; x<count_number_of_digits ; ++x)
//     {
//         sum=sum+arr[x]*pow(10,count_number_of_digits-x-1);
//     }
//     cout<<sum;

// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int>v{1,5,2,8,1,4};
//     int number=count(v.begin(),v.end(),1);
//     cout<<number;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t,n;
//     // cout<<"enter no. of testcases : ";
//     cin>>t;
//     while(t--){
//         int count=0;
//         // cout<<"enter no. of letters : ";
//         cin>>n;
//         char a[n];
//         cin>>a;
//         // cout<<endl<<a;
//         for(int i=0 ; i<n ; ++i){
//             if(a[i]>47 && a[i]<58){
//                 count++;
//                 // cout<<"a[i] : "<<a[i]<<endl;
//                 while(a[i]>47 && a[i]<58){
//                     i++;
//                     continue;
//                 }
//             }
//         }
//         cout<<count<<endl;
//     }
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     int k=n-1;
//     int b[n];
//     for(int i=0 ; i<n ; ++i){
//         cin>>a[i];
//         b[k--]=a[i];
//     }
//     for(int i=0 ; i<n ; ++i){
//         cout<<b[i]<<endl;
//     }
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     string s;
//     while(t--){
//         cin>>s;
//         vector<int>v;
//         for(int i=0 ; i<s.size() ; ++i){
//             int x=s[i]-'0';
//             v.push_back(x);
//         }
//         int size=v.size();
//         sort(v.begin(),v.end());
//         auto it=unique(v.begin(),v.end());
//         v.resize(distance(v.begin(), it));
//         if(v.back()-v.front()+1==v.size() && v.size()==size){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<<"NO"<<endl;
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     int b[n]={0};
//     for(int i=0 ; i<n ; ++i){
//         cin>>a[i];
//         b[a[i]]++;
//     }
//     // for(int i=0 ; i<n ; ++i){
//     //     cout<<b[i]<<" ";
//     // }
//     int q,num;
//     cin>>q;
//     while(q--){
//         cin>>num;
//         if(b[num]==0){
//             cout<<"NOT PRESENT"<<endl;
//         }
//         else{
//             cout<<b[num]<<endl;
//         }
//     }
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     ll n;
//     cin>>n;
//     int a[n];
//     for(ll i=0 ; i<n ; ++i){
//         cin>>a[i];
//     }
//     vector<int>v;
//     for(ll i=0 ; i<n-1 ; ++i){
//         int flag=0;
//         for(ll j=i+1 ; j<n ; ++j){
//             if(a[i]<a[j]){
//                 flag=1;
//             }
//         }
//         if(flag==0){
//             v.push_back(a[i]);
//         }
//     }
//     for(int &x:v){
//         cout<<x<<" ";
//     }
//     cout<<a[n-1];
// }
// #include<bits/stdc++.h>
// typedef long int li;
// using namespace std;
// int main(){
//     li n;
//     cin>>n;
//     li a[n];
//     li count=1;
//     for(int i=0 ; i<n ; ++i){
//         cin>>a[i];
//     }
//     for(li i=0 ; i<n-1 ; ++i){
//         if(a[i]>a[i+1]){
//             count++;
//         }
//     }
//     cout<<count;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s="aaacccbbcccd";
//     vector<char>v;
//     for(int i=0 ; i<s.size() ; ++i){
//         v.push_back(s[i]);
//     }
//     cout<<v.size()<<endl;
//     for(auto it=v.begin() ; it<v.end() ; ++it){
//         cout<<*it<<endl;
//     }
// }
// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     ll n,x;
//     cin>>n>>x;
//     ll a[n];
//     int count=0;
//     int skipped=0;
//     // for(int i=0 ; i<n ; ++i){
//     //     cin>>a[i];
//     // }
//     for(int i=0 ; i<n ; ++i){
//         cin>>a[i];
//         if(a[i]<=x){
//             // if(skipped==2){
//             //     break;
//             // }
//             count++;
//             // cout<<a[i];
//         }
//         else{
//             skipped++;
//             if(skipped==2){
//                 break;
//             }
//         }
//     }
//     cout<<endl<<count;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int rotateByOne(int*, int);
// int RotateByOne(int* ,int);
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,k;
//         cin>>n>>k;
//         int a[n];
//         for(int i=0 ; i<n ; ++i){
//             cin>>a[i];
//         }
//         if(k<=n/2){

//             for(int i=0 ; i<k%n ; ++i){
//             rotateByOne(a,n);
//             cout<<"r ";
//             }
//         }
//         else if(k>n/2){
//             for(int i=0 ; i<n-k%n ; ++i){
//                 RotateByOne(a,n);
//                 cout<<"R ";
//             }
//         }


//         for(int i=0 ; i<n ; ++i){
//         cout<<a[i]<<" ";
//         }
//         cout<<endl;
//     }


// }
// int rotateByOne(int a[],int size){
//     int temp=a[size-1],i;
//     for(i=size-1 ; i>0 ; --i){
//         a[i]=a[i-1];
//     }
//     a[0]=temp;
// }
// int RotateByOne(int b[],int size){
//     int temp=b[0],i;
//     // cout<<temp;
//     for(int i=0 ; i<size-1 ; ++i){
//         b[i]=b[i+1];
//         cout<<b[i+1];
//     }
//     b[i]=temp;
// }

// #include<bits/stdc++.h>
// using namespace std;
// inline void rightRotateByOne(int*, int);
// inline void leftRotateByOne(int*, int);
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         int n,k;
//         cin>>n>>k;
//         int a[n];
//         for(int i=0 ; i<n ; ++i){
//             cin>>a[i];
//         }
//         if(k<=n/2){
//             for(int i=0 ; i<k%n ; ++i){
//                 rightRotateByOne(a,n);
//             }
//         }
//         else if(k>n/2){
//             for(int i=0 ; i<n-k%n ; ++i){
//                 leftRotateByOne(a,n);
//             }
//         }


//         for(int i=0 ; i<n ; ++i){
//         cout<<a[i]<<" ";
//         }
//         cout<<endl;
//     }


// }
// inline void rightRotateByOne(int a[],int size){
//     int temp=a[size-1],i;
//     for(i=size-1 ; i>0 ; --i){
//         a[i]=a[i-1];
//     }
//     a[0]=temp;
// }
// inline void leftRotateByOne(int a[],int size){
//     int temp=a[0],i;
//     for(i=0 ; i<size-1 ; ++i){
//         a[i]=a[i+1];
//     }
//     a[i]=temp;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         int n,k;
//         cin>>n>>k;
//         int a[n];
//         for(int i=0 ; i<n ; ++i){
//             cin>>a[i];
//         }
//         for(int i=0 ; i<n ; ++i){
//         cout<<a[(i+(n-k%n))%n]<<" ";
//         }
//         cout<<endl;
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     int a[7];
//     while(t--){
//         int k;
//         cin>>k;
//         for(int i=0 ; i<7 ; ++i){
//             cin>>a[i];
//         }
//         int x=0,index;
//         while(k>0){
//             cout<<"k : "<<k<<endl;
//             if(a[x%7]!=0){
//                 k=k-a[x++];
//                 // cout<<a[x%7]<<" ";
//             }

//             else{
//                 x++;
//             }
//             if(k==0){
//                 cout<<"true";
//                 index=x-1;
//             }
//         }
//         cout<<endl;
//         switch(index){
//             case 0 : cout<<"MONDAY"<<endl;
//             break;
//             case 1 : cout<<"TUESDAY"<<endl;
//             break;
//             case 2 : cout<<"WEDNESDAY"<<endl;
//             break;
//             case 3 : cout<<"THURSDAY"<<endl;
//             break;
//             case 4 : cout<<"FRIDAY"<<endl;
//             break;
//             case 5 : cout<<"SATURDAY"<<endl;
//             break;
//             case 6 : cout<<"SUNDAY"<<endl;
//             break;
//         }
//     }
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     ll n;  cin>>n;
//     ll size=pow(2,n)+1;
//     ll a[size];
//     vector<ll>v;
//     for(ll i=0 ; i<=pow(2,n) ; ++i){
//         cin>>a[i];
//         v.push_back(a[i]);
//     }
//     sort(v.begin(),v.end());
//     auto it=unique(v.begin(),v.end());
//     v.resize(distance(v.begin(),it));
//     ll k=0;
//     for(auto i=v.begin() ; i<v.end() ; ++i){
//         if(count(a,a+size,*i)%2!=0){
//             cout<<*i;
//             break;
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s;
//     int k;
//     cin>>s>>k;
//     for(int i=0 ; i<s.size() ; ++i){
//         if(s[i]>=48 && s[i]<=57){
//             //numbers
//             int inc=k%10;
//             if(s[i]+inc>57){
//                 cout<<(char)(s[i]+inc-10)<<endl;
//             }
//             else{
//                 cout<<(char)(s[i]+inc)<<endl;
//             }
//         }
//         else if(s[i]>=65 && s[i]<=90){
//             //capital A-Z
//             int inc=k%26;
//             if(s[i]+inc>90){
//                 cout<<(char)(s[i]+inc-26)<<endl;
//             }
//             else{
//                 cout<<(char)(s[i]+inc)<<endl;
//             }
//         }
//         else if(s[i]>=97 && s[i]<=122){
//             //small a-z
//             int inc=k%26;
//             if(s[i]+inc>122){
//                 cout<<(char)(s[i]+inc-26)<<endl;
//             }
//             else{
//                 cout<<(char)(s[i]+inc)<<endl;
//             }
//         }
//         else{
//             cout<<s[i]<<endl;
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         string s;
//         int flag=0;
//         vector<string>v;
//         for(int i=0 ; i<n ; ++i){
//             cin>>s;
//             v.push_back(s);
//             sort(v.begin(),v.end());
//             for(auto it=v.begin() ; it<v.end()-1 ; ++it){
//                 if(*it==*(it+1)){
//                     // cout<<"Hello\n";
//                     continue;
//                 }
//                 else if(*it!=*(it+1))
//                 {
//                     if(it[0][0]==(it+1)[0][0]){
//                         // cout<<"world\n";
//                         flag=1;
//                     }
//                 }

//             }
//         }
//         if(flag==1){
//             cout<<"NO\n";
//         }
//         else{
//             cout<<"YES\n";
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     for(int i=0 ; i<10 ; ++i){
//         // cout<<"assign r7["<<i<<"] = a["<<i<<"] & b[7];"<<endl;
//         // cout<<"fullAdder f"<<i+6<<"(r3["<<i+2<<"],r4["<<i+1<<"],r5["<<i<<"],t1["<<i+2<<"],c1["<<i+1<<"]);"<<endl;
//         // cout<<"assign c2["<<i<<"] = r7["<<i<<"];"<<endl;
//         // cout<<"fullAdder f"<<i+12<<"(t0["<<i+3<<"],c0["<<i+1<<"],t1["<<i<<"],t2["<<i+3<<"],c2["<<i+1<<"]);"<<endl;
//         // cout<<"fullAdder f"<<i+19<<"(c["<<i+2<<"],r6["<"<i+1<<"],r7["<<i<<"],t3["<<i+2<<"],c3["<<i+1<<"]);"<<endl;
//         // cout<<"fullAdder f"<<i+25<<"(t2["<<i+5<<"],c2["<<i+2<<"],t3["<<i<<"],t4["<<i+5<<"],c4["<<i+2<<"]);"<<endl;
//         // cout<<"fullAdder f"<<i+31<<"(t4["<<i+7<<"],c4["<<i+3<<"],c3["<<i<<"],t5["<<i+7<<"],c5["<<i+3<<"]);"<<endl;
//         cout<<"HalfAdder h"<<i+16<<"(t5["<<i+5<<"],c5["<<i<<"],result["<<i+5<<"],car["<<
//     }
// }

// #include <iostream>
// using namespace std;
// class Employee {
//    public:
//        int id; //data member (also instance variable)
//        string name; //data member(also instance variable)
//        float salary;
//        Employee(int ids, string names, float salarys)
//         {
//              this->id = ids;
//             this->name = names;
//             this->salary = salarys;
//         }
//        void display()
//         {
//             cout<<id<<"  "<<name<<"  "<<salary<<endl;
//         }
// };
// int main(void) {
//     Employee e1 =Employee(101, "Sonoo", 890000); //creating an object of Employee
//     Employee e2=Employee(102, "Nakul", 59000); //creating an object of Employee
//     e1.display();
//     e2.display();
//     return 0;
// }
// #include<iostream>
// #define SDL_MAIN_HANDLED
// #include "/usr/include/SDL2/SDL.h"

// using namespace std;
// int main(){
//     if(SDL_Init(SDL_INIT_VIDEO)<0){
//         cout<<"SDL init failed"<<endl;
//         return 1;
//     }
//     cout<<"SDL init succeeded"<<endl;
//     SDL_Quit();
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int a[n][m];
//     //input
//     for(int i=0 ; i<n ; ++i){
//         for(int j=0 ; j<m ; ++j){
//             cin>>a[i][j];
//         }
//     }
//     //output
//     for(int i=0 ; i<m ; ++i){
//         for(int j=0 ; j<n ; ++j){
//             cout<<a[j][i]<<" ";
//         }
//         cout<<endl;
//     }
// }

// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int s[n];
//     int mark[n]={1};
//     for(int i=0 ; i<n ; ++i){
//         cin>>s[i];
//     }
//     sort(s,s+n);

//     for(int i=1 ; i<n ; ++i){
//         for(int j=i-1 ; j>=0 ; --j){

//             if(s[i]>s[j] && s[j]!=0){
//                 mark[i]=0;
//                 s[j]=0;
//                 mark[j]=0;
//                 break;
//             }
//         }
//         // //for printing array in each step
//         // /////////////////////////////////
//         // for(int &x,&y:s,mark){
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;
//         // /////////////////////////////////
//     }
//     int sum=0;
//     for(int i=0 ; i<n ; ++i){
//         sum+=s[i];
//     }
//     cout<<sum<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// #define SIZE 5
// using namespace std;
// struct stackUsingArray{
//     public:
//     int data[SIZE];
//     int top;
// }n;
// void push(int data){
//     n.top++;
//     n.data[n.top]=data;
//     cout<<"pushed : "<<n.data[n.top]<<endl;
// }

// void pop(){
//     n.top--;

// }
// void print(){
//     for(int i=0 ; i<=n.top ; ++i){
//         cout<<n.data[i]<<" ";
//     }
//     cout<<endl;
// }

// int main(){
//     n.top=-1;
//     push(1);
//     push(2);
//     push(3);
//     print();
//     cout<<"top : "<<n.top<<endl;
//     pop();
//     print();
//     pop();
//     print();
//     pop();
//     print();
// }
// #include<bits/stdc++.h>
// using namespace std;
// struct stackUsingLinkedList{
//     int data;
//     struct stackUsingLinkedList *nptr;
// }n;
// struct stackUsingLinkedList *hptr=NULL;
// void push(int data){
//     stackUsingLinkedList *temp=new stackUsingLinkedList;
//     temp->data=data;
//     temp->nptr=hptr;
//     hptr=temp;
//     // cout<<hptr->data<<endl;
//     // delete temp;
//     // cout<<hptr->data<<endl;
//     cout<<"pushed : "<<data<<endl;
// }
// void pop(){

// }
// void print(){
//     stackUsingLinkedList *temp=hptr;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->nptr;

//     }
// }
// int main(){
//     push(10);
//     push(20);
//     push(30);
//     print();
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     char str[] = "geeksforgeeks";
//     cout<<strlen(str);
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     int n;
//     while(t--){
//         cin>>n;
//         for(int i=n-1 ; i>=0 ; --i){
//             cout<<string(n-i,'*')<<string(i*2,'#')<<string(n-i,'*')<<endl;
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int t,n;
//     string s;
//     cin>>t>>n>>s;
//     // vector<int>v;
//     while(t--){
//          int check[14];
//         int k=0;
//         for(int i=61 ; i<=127 ; ++i){
//             int flag=0;
//             for(int j=2 ; j<i ; ++j){
//                 if(i%j==0){
//                     flag=1;
//                     break;
//                 }
//             }
//             if(flag==0){
//                 check[k++]=i;
//             }
//         }

//         for(int i=0 ; i<s.size() ; ++i){
//             for(int j=0 ; j<13 ; ++j){
//                 if((int)s[i]==check[j]){
//                     // cout<<"equal"<<endl;
//                     cout<<(char)check[j];
//                     break;

//                 }
//                 else if((int)s[i]<check[j]){
//                     // cout<<"less"<<endl;
//                 }
//                 else if((int)s[i]>check[j]){
//                     // cout<<"more";
//                     if( abs((int)s[i]-check[j]) <= abs((int)s[i]-check[j+1]) ){
//                         cout<<(char)check[j];
//                         // cout<<" lessthan"<<endl;
//                         break;
//                     }
//                     else if( abs((int)s[i]-check[j]) > abs((int)s[i]-check[j+1]) ){
//                         cout<<(char)check[j+1];
//                         // cout<<j<<endl;
//                         // cout<<" morethan"<<endl;
//                         break;
//                     }
//                 }

//             }
//         }
//         cout<<endl;
//     }


//     // for(int &x:check){
//     //     cout<<x<<" ";
//     // }
// }
//////////////////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     int originalArray[n];
//     for(int i=0 ; i<n ; ++i){
//         cin>>a[i];
//         originalArray[i]=a[i];
//     }

//     sort(a,a+n);

//     for(int i=0 ; i<n ; ++i){
//         cout<<distance(a,find(a,a+n,originalArray[i]))+1<<" ";
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     ll n,k;
//     cin>>n>>k;
//     ll a[n];
//     ll total_sum=0;
//     for(ll i=0 ; i<n ; ++i){
//         cin>>a[i];
//         total_sum+=a[i];
//     }
//     ll flag=0;
//     ll x=0,y=0;
//     if(k!=0 && k<total_sum){
//         for (ll i = 0; i < n; i++){
//             ll sum = 0;
//             for (ll j = i; j < n; j++) {
//                 sum += a[j];
//                 if(sum==k){
//                     flag=1;
//                     break;
//                 }
//                 else{
//                     if(sum>x && sum<k){
//                         x=sum;
//                     }
//                     if(sum>k && y==0){
//                         y=sum;
//                     } else if(sum>k){
//                         if(sum<y){
//                             y=sum;
//                         }
//                     }
//                 }
//             }
//             if(flag==1){
//                 break;
//             }
//         }
//     }

//     if(flag==1 || k==0 || k==total_sum){
//         cout<<0;
//     }
//     else if(k>total_sum){
//         cout<<k-total_sum;
//     }
//     else{
//         if(k-x>=y-k){
//             cout<<y-k;
//         }
//         else{
//             cout<<k-x;
//         }
//     }
//     return 0;
// }

//using find_if
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={1,2,3,4,5,6,7,8,9};
//     auto it=find_if(arr,arr+9,[](int x){
//         return x%2;
//     });
//     cout<<*it<<" ";
// }

// #include <iostream>
// using namespace std;

// void func(int num)
// {
//     for (int i = 0; i < num; i++)
//         cout << "It shows how we can use ",
//             cout << "comma operator in place of curly braces.\n",
//             cout << "Loop traversal number: ",
//             cout << i << "\n\n ";
// }

// int main()
// {
//     int num = 5;
//     func(num);

//     return 0;
// }
//////////////////////////fast I/O//////////////////
// #include<bits/stdc++.h>
// using namespace std;

// void fastscan(int &number)
// {
//     //variable to indicate sign of input number
//     bool negative = false;
//     register int c;

//     number = 0;

//     // extract current character from buffer
//     c = getchar();
//     if (c=='-')
//     {
//         // number is negative
//         negative = true;

//         // extract the next character from the buffer
//         c = getchar();
//     }

//     // Keep on extracting characters if they are integers
//     // i.e ASCII Value lies from '0'(48) to '9' (57)
//     for (; (c>47 && c<58); c=getchar())
//         number = number *10 + c - 48;

//     // if scanned input has a negative sign, negate the
//     // value of the input number
//     if (negative)
//         number *= -1;
// }

// // Function Call
// int main()
// {
//     int number;
//     fastscan(number);
//     cout << number << "\n";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int k;  cin>>k;
//     string s[k];
//     for(int i=0 ; i<k ; ++i){
//         cin>>s[i];
//     }
//     int l;  cin>>l;
//     string str[l];
//     for(int i=0 ; i<l ; ++i){
//         cin>>str[i];
//     }
//     vector<string>v(l);
//     vector<string>nv;
//     auto it=set_difference(str,str+l,s,s+k,v.begin());
//     for(auto st=v.begin() ; st!=it ; ++st){
//         cout<<(char)(st[0][0]-32)<<"."<<flush;
//         // nv.push_back(*st)
//         // cout<<st[0]<<" ";
//     }
//     cout<<"\b";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int k;  cin>>k;
//     string temp1;
//     vector<string>s1;
//     for(int i=0 ; i<k ; ++i){
//         cin>>temp1;
//         s1.push_back(temp1);
//     }
//     int l;  cin>>l;
//     string temp2;
//     vector<string>s2;
//     for(int i=0 ; i<l ; ++i){
//         cin>>temp2;
//         s2.push_back(temp2);
//     }
//     vector<char>print;
//     for(auto it=s1.begin() ; it<s1.end() ; ++it){
//         // cout<<""
//         s2.erase(remove(s2.begin(),s2.end(),*it),s2.end());
//     }
//     for(auto it=s2.begin() ; it<s2.end() ; ++it){
//         print.push_back((char)(it[0][0]-32));
//         print.push_back('.');
//     }
//     print.pop_back();
//     for(auto it=print.begin() ; it<print.end() ; ++it){
//         cout<<*it;
//     }
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n,q,l,i,val;
//     cin>>n>>q;
//     vector <int> a[n];
//     for(int k=0;k<n;k++)
//     {
//         int count;
//         cin>>count;
//         a[k].push_back(count);
//         for(l=1;l<=count;l++)
//         {
//             cin>>val;
//             a[k].push_back(val);
//         }
//     }
//     // vector <int> a[n];
//     for(int i=0;i<q;i++)
//     {
//         cout<< a[2].at(1)<<" ";
//     }
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n,q;
//     cin>>n>>q;
//     vector<int>v[n];
//     int k;
//     int data;
//     for(int i=0;i<n;i++){
//         cin>>k;
//         for(int j=0;j<k;j++){
//             cin>>data;
//             v[i].push_back(data);
//         }
//     }

//     int x,y;
//     for(int i=0 ; i<q ; ++i){
//         cin>>x>>y;
//         cout<<v[x].at(y)<<endl;
//         // cout<<v[x][y]<<endl;
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     stack<char>s;
//     int n;
//     cin>>n;
//     char c;
//     for(int i=0 ; i<n ; ++i){
//         cin>>c;
//         if(s.empty()){
//             s.push(c);
//         }
//         else{
//             if(s.top()==c){
//                 s.pop();
//             }
//             else{
//                 s.push(c);
//             }
//         }
//     }
//     cout<<s.size()<<endl;
//     vector<char>v;
//     while(!s.empty()){
//         char x=s.top();
//         v.push_back(x);
//         s.pop();
//     }
//     reverse(v.begin(),v.end());
//     for(auto &x:v){
//         cout<<x;
//     }
// }
/////////////////////////////////////////////////////////////

// #include<bits/stdc++.h>
// using namespace std;

// void sort(int a[],int n){
//   for(int i=1 ; i<n ; ++i){
//     for(int j=i ; j>0 ; --j){
//       if(a[j]<a[j-1]){
//         swap(a[j],a[j-1]);
//       }
//     }
//   }
// }

// void sort(char b[],int n){
//     for(int i=1 ; i<n ; ++i){
//       for(int j=i ; j>0 ; --j){
//         if(b[j]<b[j-1]){
//           swap(b[j],b[j-1]);
//         }
//       }
//     }
// }

// void sort(float a[],int n){
//   for(int i=1 ; i<n ; ++i){
//     for(int j=i ; j>0 ; --j){
//       if(a[j]<a[j-1]){
//         swap(a[j],a[j-1]);
//       }
//     }
//   }
// }
// int main(){
//     int a[]={6, 3, 9, 1, 7};
//     int asize=sizeof(a)/sizeof(a[0]);
//     char b[]={'n', 'c', 'p', 'a', 't'};
//     int bsize=sizeof(b)/sizeof(b[0]);
//     float c[]={1.32, 3.71, 0.67, 5.43, 2.91};
//     int csize=sizeof(c)/sizeof(c[0]);
//     sort(a,asize);
//     for(int i=0 ; i<asize ; ++i){
//       cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     sort(b,bsize);
//     for(int i=0 ; i<bsize ; ++i){
//       cout<<b[i]<<" ";
//     }
//     cout<<endl;
//     sort(c,csize);
//     for(int i=0 ; i<csize ; ++i){
//       cout<<c[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
//
// template<typename T>
// void srt(T a[],T b[]){
//   int n=(b-a);
//   for(int i=1 ; i<n ; ++i){
//     for(int j=i ; j>0 ; --j){
//       if(a[j]<a[j-1]){
//         swap(a[j],a[j-1]);
//       }
//     }
//   }
// }
//
// int main(){
//     int a[]={6, 3, 9, 1, 7};
//     int asize=sizeof(a)/sizeof(a[0]);
//     char b[]={'n', 'c', 'p', 'a', 't'};
//     int bsize=sizeof(b)/sizeof(b[0]);
//     float c[]={1.32, 3.71, 0.67, 5.43, 2.91};
//     int csize=sizeof(c)/sizeof(c[0]);
//
//     srt(a,a+asize);
//     for(int i=0 ; i<asize ; ++i){
//       cout<<a[i]<<" ";
//     }
//     cout<<endl;
//
//     srt(b,b+bsize);
//     for(int i=0 ; i<bsize ; ++i){
//       cout<<b[i]<<" ";
//     }
//     cout<<endl;
//
//     srt(c,c+csize);
//     for(int i=0 ; i<csize ; ++i){
//       cout<<c[i]<<" ";
//     }
//     cout<<endl;
//
//
//     return 0;
// }
/////////////////////////////////////////////////////////////////////
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;  cin>>n;
//     int a[n];
//     vector<int>v(n);
//     v.clear();
//     for(int i=0 ; i<n ; ++i){
//         cin>>a[i];
//         if(i<n/2)
//             while(a[i]>=10){
//                 a[i]=a[i]/10;
//             }
//         else
//             a[i]=a[i]%10;
//         v.push_back(a[i]);
//     }
//     // for(auto &x:v){
//     //     cout<<x<<" ";
//     // }
//     long long sum=0;
//     for(auto i=0 ; i<n ; ++i){
//         if(i%2==0){
//             sum+=v[i];
//         }
//         else{
//             sum-=v[i];
//         }
//     }
//     if(abs(sum)%11==0){
//         cout<<"OUI";
//     }
//     else{
//         cout<<"NON";
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;  cin>>t;
//     while(t--){
//         int n;  cin>>n;
//         int a[n];
//         int flag=0;
//         int store;
//         for(int i=0 ; i<n ; ++i){
//             cin>>a[i];
//             if(a[i]!=i*i-i){
//                 store=a[i];
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==1){
//             cout<<"Incorrect "<<store<<endl;
//         }
//         else{
//             cout<<"Correct"<<endl;
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;  cin>>t;
//     while(t--){
//         string s;
//         cin>>s;
//         int n=s.size();
//         sort(s.begin(),s.end());
//         auto it=unique(s.begin(),s.end());
//         s.resize(distance(s.begin(),it));
//         if(s.size()%2==0){
//             cout<<"Player2"<<endl;
//         }
//         else{
//             cout<<"Player1"<<endl;
//         }
//     }
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int p,s,t,h,x;
//     long long int sum=0;
//     cin>>p>>s>>t>>h>>x;
//     if(s-t>=x){
//         // cout<<x-t<<endl;
//         cout<<x*p;
//     }
//     else{
//         // cout<<s-t<<"\t"<<x-s+t<<endl;
//         cout<<(s-t)*p+(x-s+t)*h;
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;  cin>>t;
//     while(t--){
//         int n;  cin>>n;
//         int a[n],b[n];
//         vector<int>v;
//         for(int i=0 ; i<n ; ++i){
//             cin>>a[i];
//             b[i]=a[i];
//             int sum=0;
//             if(a[i]==0){
//                 sum+=6;
//             }
//             while(a[i]>0){
//                 if(a[i]%10==1)
//                 {
//                     sum+=2;
//                 }
//                 else if(a[i]%10==2 || a[i]%10==3 || a[i]%10==5){
//                     sum+=5;
//                 }
//                 else if(a[i]%10==4){
//                     sum+=4;
//                 }
//                 else if(a[i]%10==6 || a[i]%10==9 || a[i]%10==0){
//                     sum+=6;
//                 }
//                 else if(a[i]%10==7){
//                     sum+=3;
//                 }
//                 else if(a[i]%10==8){
//                     sum+=7;
//                 }
//                 a[i]=a[i]/10;
//             }
//             // cout<<sum<<endl;
//             v.push_back(sum);
//         }
//         cout<<b[distance(v.begin(),min_element(v.begin(),v.end()))]<<endl;
//     }
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     vector<int>init(1,0);
//     vector<vector<int>>a;


//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// struct node{
//     int ei;
//     int ef;
// };
// int main(){
//     int n;
//     cin>>n;
//     struct node nd[n];
//     for(int i=0 ; i <n ; ++i){
//         cin>>nd[i].ei>>nd[i].ef;
//     }
//     // for(int i=0 ; i<n ; ++i){
//     //     cout<<nd[i].ei<<" "<<nd[i].ef<<endl;
//     // }
//     sort(nd,nd+n,[](node a,node b){
//         return a.ei<b.ei;
//     });
//     int count=0;
//     for(int i=0 ; i<n-1 ; ++i){
//         for(int j=i+1; j<n; j++){
//             if(nd[i].ef<nd[j].ef && nd[j].ef!=0 && nd[i].ef!=0){
//                 count=count+2;
//                 nd[j].ef=0;
//                 break;
//             }
//         }
//     }
//     cout<<count<<endl;
//     // for(int i=0 ; i<n ; ++i){
//     //     cout<<nd[i].ei<<" "<<nd[i].ef<<endl;
//     // }
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// struct node{
//     int a;
//     int count;
// };
// long long int count1(ll data){
//     int count=0;
//         while(data!=0){
//             count++;
//             data=data&(data-1);
//         }
//     return count;
// }
// int main(){
//     // cout<<count1(1111111111111111111);
//     // cout<<ULLONG_MAX/4;
//     // int t;  cin>>t;
//     // while(t--){
//     //     int n;  cin>>n;
//     //     struct node nd[n];
//     //     int data;
//     //     for(int i=0 ; i<n ; ++i){
//     //         cin>>data;
//     //         nd[i].a=data;
//     //         nd[i].count=0;
//     //         int cnt=count1(data);
//     //         nd[i].count=cnt;
//     //     }
//     //     sort(nd,nd+n,[](node x,node y){
//     //         return x.count<y.count;
//     //     });
//     //     for(int i=0 ; i<n ; ++i){
//     //         cout<<nd[i].a<<" "
//     //     }
//     //     cout<<endl;
//     // }
//     return 0;
// }

// #include<iostream>
// #include<bits/stdc++.h>
// // #include<vector>
// // #include<sstream>
// // #include<string>
// #define ll long long int
// #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// using namespace std;

// // n>>1//shifts the bits(binary to right by 1)
// // n&1 it ANDs //AND Gate// the binary of n with 1 (last digits is if 1 results true in if condition) 

// // void ones_in_Binary(ll arr[],ll n)
// // {
// // 	ll c[n],cpy[n],i,j;
// // 	for(i=0;i<n;i++)
// // 	    c[i]=0;
// // 	for(i=0;i<n;i++)
// // 	    cpy[i]=arr[i];
	
// // 	for(i=0;i<n;i++)
// // 	{
// // 		while(arr[i])
// // 		{
// // 			if(arr[i]&1)
// // 			    c[i]++;
// // 			arr[i]=arr[i]>>1;
// // 		}
// // 	}
// // 	for(i=0;i<n;i++)
// // 	    cout<<c[i]<<" ";
// // 	cout<<endl;
	
// //     //sorting
// //     for(ll x=1 ; x<n ; ++x){
// //         for(ll y=x ; y>0 ; --y){
// //             if(c[y]<c[y-1]){
// //                 cpy[y] ^= cpy[y-1];
// //                 cpy[y-1] ^= cpy[y];
// //                 cpy[y] ^= cpy[y-1];
// //             }
// //         }
// //     }
	
// // 	for(i=0;i<n;i++)
// // 	    cout<<cpy[i]<<" ";
// // 	cout<<endl;
	
// // }

// int main()
// {
//     // cout<<__builtin_popcount()<<endl;
//     fast;
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{	
// 		ll n;
// 		cin>>n;
// 		ll a[n];
// 		ll count[n]={0};
// 		for(ll i=0;i<n;i++){
//             cin>>a[i];
//             count[i]=__builtin_popcount(a[i]);
//         }
//         // sorting
//         for(ll x=1 ; x<n ; ++x){
//             for(ll y=x ; y>0 ; --y){
//                 if(count[y]<count[y-1]){
//                     a[y] ^= a[y-1];
//                     a[y-1] ^= a[y];
//                     a[y] ^= a[y-1];
//                 }
//             }
//         }
//         for(auto &x:a){
//             cout<<x<<" ";
//         }
//         cout<<endl;

		
// 	}
// 	return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n][m]={0};
//     int grid[n][m][5]={0};
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++)
//             cin>>arr[i][j];
//     }
//     for(int i=1;i<n-1;i++){
//         for(int j=1;j<m-1;j++){
//             grid[i][j][0]=arr[i][j];
//             grid[i][j][1]=arr[i-1][j];
//             grid[i][j][2]=arr[i+1][j];
//             grid[i][j][3]=arr[i][j-1];
//             grid[i][j][4]=arr[i][j+1];
//         }
//     }

//     int maxv=-1;
//     for(int i=1;i<n-1;i++){
//         for(int j=1;j<m-1;j++){
//             for(int a=1;a<n-1;a++){
//                 for(int b=1;b<m-1;b++){
//                     if(!((a>i-2&&a<i+2)&&(b>j-2&&b<j+2))){
//                         int value=(grid[i][j][0]*grid[a][b][0]+grid[i][j][1]*grid[a][b][1]+grid[i][j][2]*grid[a][b][2]+grid[i][j][3]*grid[a][b][3]+grid[i][j][4]*grid[a][b][4]);
//                         if(value>maxv)
//                         maxv=value;
//                     }

//                 }
//             }
//         }
//     }
//     cout<<maxv;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int>v(2*n+1);
//     v.clear();
//     set<int>c;
//     int num;
//     for(int i=0 ; i<2*n+1 ; ++i){
//         cin>>num;
//         // v[i]=num;
//         v.push_back(num);
//         c.insert(num);
//     }
    
//     for(auto i=c.begin() ; i!=c.end() ; ++i){
//         if(count(v.begin(),v.end(),*i)%2==1){
//             cout<<*i;
//             break;
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;  cin>>t;
//     for(int i=0 ; i<t ; ++i){
//         int a;  cin>>a;
//         int find=log2(a);
//         if(a==pow(2,find)){
//             cout<<a<<endl;
//         }
//         else{
//             a=(a-pow(2,find))*2;
//             cout<<a<<endl;
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     char a[3];
//     char b[3];
//     char c[3];
//     for(int i=0 ; i<3 ; ++i){
//         cin>>a[i];
//     }
//     for(int i=0 ; i<3 ; ++i){
//         cin>>b[i];
//     }
//     for(int i=0 ; i<3 ; ++i){
//         cin>>c[i];
//     }
//     int countOfO=count(a,a+3,'O')+count(b,b+3,'O')+count(c,c+3,'O');
//     int countOfX=count(a,a+3,'X')+count(b,b+3,'X')+count(c,c+3,'X');
//     int countOfDot=count(a,a+3,'.')+count(b,b+3,'.')+count(c,c+3,'.');
//     bool X=(a[0]=='X' && a[1]=='X' && a[2]=='X') || (b[0]=='X' && b[1]=='X' && b[2]=='X') || (c[0]=='X' && c[1]=='X' && c[2]=='X') || (a[0]=='X' && b[0]=='X' && c[0]=='X') || (a[1]=='X' && b[1]=='X' && c[1]=='X') || (a[2]=='X' && b[2]=='X' && c[2]=='X') || (a[0]=='X' && b[1]=='X' && c[2]=='X') || (a[2]=='X' && b[1]=='X' && c[0]=='X');
//     bool Y=(a[0]=='O' && a[1]=='O' && a[2]=='O') || (b[0]=='O' && b[1]=='O' && b[2]=='O') || (c[0]=='O' && c[1]=='O' && c[2]=='O') || (a[0]=='O' && b[0]=='O' && c[0]=='O') || (a[1]=='O' && b[1]=='O' && c[1]=='O') || (a[2]=='O' && b[2]=='O' && c[2]=='O') || (a[0]=='O' && b[1]=='O' && c[2]=='O') || (a[2]=='O' && b[1]=='O' && c[0]=='O');

//     if(countOfO>countOfX || countOfX>countOfO+1 || (X&&Y) || (X&&(countOfO>countOfX)) || (Y&&(countOfX>countOfO))){
//         cout<<"Wait, what?";
//     }
//     else if( (a[0]=='X' && a[1]=='X' && a[2]=='X') || (b[0]=='X' && b[1]=='X' && b[2]=='X') || (c[0]=='X' && c[1]=='X' && c[2]=='X') || (a[0]=='X' && b[0]=='X' && c[0]=='X') || (a[1]=='X' && b[1]=='X' && c[1]=='X') || (a[2]=='X' && b[2]=='X' && c[2]=='X') || (a[0]=='X' && b[1]=='X' && c[2]=='X') || (a[2]=='X' && b[1]=='X' && c[0]=='X')){
//         cout<<"X won.";
//     }
//     else if( (a[0]=='O' && a[1]=='O' && a[2]=='O') || (b[0]=='O' && b[1]=='O' && b[2]=='O') || (c[0]=='O' && c[1]=='O' && c[2]=='O') || (a[0]=='O' && b[0]=='O' && c[0]=='O') || (a[1]=='O' && b[1]=='O' && c[1]=='O') || (a[2]=='O' && b[2]=='O' && c[2]=='O') || (a[0]=='O' && b[1]=='O' && c[2]=='O') || (a[2]=='O' && b[1]=='O' && c[0]=='O')){
//         cout<<"O won.";
//     }
//     else if(countOfDot==0){
//         cout<<"It is a draw.";
//     }
//     else if(countOfO==countOfX){
//         cout<<"X's turn.";
//     }
//     else{
//        cout<<"O's turn."; 
//     }
//     return 0;
    
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int a=5,b=2;
//     a=(a+b)-(b=a);
//     cout<<a<<" "<<b<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// #include <boost/array.hpp>
// using namespace std;
// int main(){
//   boost::array<int, 4> arr = {1,2,3,4};
//   cout << "hi" << arr[0];
//   return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         unordered_map<char, int>um;
//         set<char>st;
//         int n,q;
//         cin>>n>>q;
//         string s;
//         cin>>s;
//         int l,r;
        
//         for(int i=0 ; i<q ; ++i){
//             cin>>l>>r;
//             for(int i=l ; i<=r ; ++i){
                
//                 // um[s[i-1]]++;
//                 // if(um[s[i-1]]==2){
//                 //     um.erase(s[i-1]);
//                 // }
//             }
//             // if((r-l+1)%2==0){
//             //     if(um.empty()){
//             //         cout<<"YES"<<endl;
//             //     }
//             //     else{
//             //         cout<<"NO"<<endl;
//             //     }
//             // }
//             // else{
//             //     if(um.size()==1){
//             //         cout<<"YES"<<endl;
//             //     }
//             //     else{
//             //         cout<<"NO"<<endl;
//             //     }
//             // }
//             /////////////////////////////////////
//             //length is even
//             // int flag=0;
//             // if((r-l+1)%2==0){
//             //     for(auto it=um.begin() ; it!=um.end() ; ++it){
//             //         if((it->second)%2==1){
//             //             flag=1;
//             //             break;
//             //         }
//             //     }
//             //     if(flag==1){
//             //         cout<<"NO"<<endl;
//             //     }
//             //     else{
//             //         cout<<"YES"<<endl;
//             //     }

//             // }
//             // else if((r-l+1)%2==1){
//             //     int count=0;
//             //     for(auto it=um.begin() ; it!=um.end() ; ++it){
//             //         if((it->second)%2==1){
//             //             count++;
//             //             if(count>1){
//             //                 break;
//             //             }
//             //         }
//             //     }
//             //     if(count>1){
//             //         cout<<"NO"<<endl;
//             //     }
//             //     else{
//             //         cout<<"YES"<<endl;
//             //     }
//             // }
//             um.clear();
//         }
//     }
//     return 0;
// }

// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a[n],b[n];
//     for(int i=0 ; i<n ; ++i){
//         cin>>a[i];
//     }
//     for(int i=0 ; i<n ; ++i){
//         cin>>b[i];
//     }
//     int count=0;
//     for(int i=0 ; i<n ; ++i){
//         for(int j=0 ;j<n ; ++j){
//             if(__gcd(a[i],b[j])!=1){
//                 count++;
//             }
//         }
//     }k
//     cout<<count<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;  cin>>n;
//     // int finals=ceil((float)n/2);
//     int finals=n/2;
//     int k=1;
    
//     long long sum=0;
//     for(int i=n ; i>finals ; --i){
//         long long mul=1;
//         for(int j=i ; j>i-k ; --j){
//             mul = (mul * j)%1000000007;
//             // cout<<j<<" ";
//         }
//         k++;
//         sum=(sum+mul)%1000000007;
//         // cout<<endl;
//     }
//     cout<<sum;
//     return 0;
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// struct node{
//     ll person;
//     vector<ll>friends;
//     ll rewards;
//     ll days;
// };
// int main(){
    
//     ll n,m,k;
//     cin>>n>>m>>k;
//     struct node nd[n+1];
//     //initial rewards=0,days=0
//     for(int i=1 ; i <=n ; ++i){
//         nd[i].rewards=0;
//         nd[i].days=-1;
//     }
//     ll a,b;
//     for(int i=0 ; i<m ; ++i){
//         cin>>a>>b;
//         nd[a].person=a;
//         nd[a].friends.push_back(b);

//         nd[b].person=b;
//         nd[b].friends.push_back(a);
//     }
    
//     ll q,p,x;
//     cin>>q;
//     for(int i=1 ; i<=q ; ++i){
//         cin>>p>>x;

//         //adding rewards to person
//         nd[p].rewards +=x;

//         //checking if rewards reached k
//         if(nd[p].rewards>=k){
//             for(auto &x:nd[p].friends){
//                 if(nd[x].days==0){
//                     nd[x].days=i;
//                 }
//             }
//             // cout<<endl;
//         }
//     }
//     for(int i=1 ; i<=n ; ++i){
//         cout<<nd[i].days;
//         if(i!=n)
//             cout<<" ";
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// bool isPrime(ll n) { 
//     if (n <= 1){
//         return false; 
//     }
//     if(n==2 || n==3 || n==5 || n==7){
//         return true;
//     }
//     if(n%2==0 || n%3==0 || n%5==0 || n%7==0){
//         cout<<"hello"<<endl;
//         return false;
//     }
//     return true;
//     // // if((ll)(n%2)==0){
//     // //     return false;
//     // // }
//     // for (ll i = 2; i <= sqrt(n); i=i+1){
//     //     if (n % i == 0){
//     //         return false; 
//     //     }
//     // } 
//     // return true; 
// } 
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     ll a,b,k;
//     cin>>a>>b>>k;
//     string s;
//     ll count=0;
//     if(a%k==0){
//         for(ll i=a ; i<=b ; i=i+k){
//             s=to_string(i);
//             ll temp_sum=0;
//             for(ll j=0 ; j<s.size() ; ++j){
//                 temp_sum+=(ll)(s[j]-'0');
//             }
//             if(isPrime(temp_sum)){
//                 count++;
//             }
//         }
//     }
//     else{
//         for(ll i=a+k-(a%k) ; i<=b ; i=i+k){
//             s=to_string(i);
//             ll temp_sum=0;
//             for(ll j=0 ; j<s.size() ; ++j){
//                 temp_sum+=(ll)(s[j]-'0');
//             }
//             if(isPrime(temp_sum)){
//                 count++;
//             }
//         }
//     }
//     cout<<count;
//     return 0;
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// ll count(ll n, ll k){
//     ll cnt=0;
//     while(n>=k){
//         cnt+=n/k;
//         n=(n/k)+(n%k);
//     }
//     return cnt;    
//     // if(n<k){
//     //     return cnt;
//     // }
//     // else{
//     //     cnt+=n/k;
//     //     return count((n/k)+(n%k),k);
//     // }
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         ll n,k,cnt;
//         cin>>n>>k;
//         cnt=count(n,k);    
//         cout<<cnt<<endl;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// long long NotinRange (int* R, int* L, int n ) {
//    // Write your code here
//    for(int i=1 ; i<n ; ++i){
//        for(int j=i ; j>0 ; j--){
//            if(L[j]<L[j-1]){
//                swap(L[j],L[j-1]);
//                swap(R[j],R[j-1]);
//            }
//        }
//    }
//     ll sum=0;
//     ll start=0,end=L[0];
//     for(int i=0 ; i<n ; ++i){
//         ll to_sum=(end-start-1);
//         to_sum=to_sum*(end+start);
//         to_sum=to_sum/2;
//         if(start>end){
//             to_sum=0;
//         }
//         sum+=to_sum;
//         start=R[i];
//         end=L[i+1];
//     }
//     start=R[n-1],end=1000001;
//     ll to_sum=(end-start-1);
//     to_sum=to_sum*(end+start);
//     to_sum=to_sum/2;
//     if(start>end){
//         to_sum=0;
//     }
//     sum+=to_sum;
//     // cout<<sum<<endl;
//     return sum;
// }

// int main() {
    
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin>>n;
//     int L[n],R[n];
//     for(int i=0; i<n; i++)
//     	cin>>L[i]>>R[i];
    
//     long long out_ = NotinRange(R, L, n);
//     cout<<out_;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     srand(time(NULL));
//     int a[50];
//     for(int i=0 ; i<50 ; ++i){
//         a[i]=rand()%200+1;
//     }
//     cout<<"number are :-"<<endl;
//     for(int i=0 ; i<50 ; ++i){
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     int num;
//     int flag=0;
//     int pos;
//     cout<<"enter the number to search : ";
//     cin>>num;
//     for(int i=0 ; i<50 ; ++i){
//         if(a[i]==num){
//             flag=1;
//             pos=i+1;
//             break;
//         }
//     }
//     if(flag==0){
//         cout<<"Not found"<<endl;
//     }
//     else{
//         cout<<"found at pos : "<<pos<<endl;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     srand(time(NULL));
//     int a[10];
//     for(int i=0 ; i<10 ; ++i){
//         a[i]=rand()%100 + 1;
//     }
//     //sorting
//     for(int i=0 ; i<10 ; ++i){
//         for(int j=1 ; j<10-i ; ++j){
//             if(a[j-1]>a[j]){
//                 swap(a[j-1],a[j]);
//             }
//         }
//     }
//     cout<<"sorted array is : "<<endl;
//     for(int i=0 ; i<10 ; ++i){
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     srand(time(NULL));
//     int a[10];
//     for(int i=0 ; i<10 ; ++i){
//         a[i]=rand()%100 + 1;
//     }
//     //sorting 
//     for(int i=1 ; i<10 ; ++i){
//         for(int j=i ; j>0 ; --j){
//             if(a[j-1]>a[j]){
//                 swap(a[j-1],a[j]);
//             }
//         }
//     }
//     cout<<"sorted array is : "<<endl;
//     for(int i=0 ; i<10 ; ++i){
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     srand(time(NULL));
//     int a[10];
//     for(int i=0 ; i<10 ; ++i){
//         a[i]=rand()%100 + 1;
//     }
//     //sorting
//     int cmin,imin;
//     for(int i=0 ; i<10-1 ; ++i){
//         cmin=a[0],imin=i;
//         for(int j=i+1 ; j<10 ; ++j){
//             if(a[j]<a[imin]){
//                 // max=a[j];
//                 imin=j;
//             }
//         }
//         swap(a[imin],a[i]);
//     }
//     cout<<"sorted array is : "<<endl;
//     for(int i=0 ; i<10 ; ++i){
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// struct stacks{
//     int a[100];
//     int top;
// }s;
// void push(int x){
//     s.top++;
//     s.a[s.top]=x;
// }
// void pop(){
//     s.top--;
// }
// void print(){
//     for(int i=0 ; i<=s.top ; ++i){
//         cout<<s.a[i]<<" ";
//     }
//     cout<<endl;
// }
// int main(){
//     // struct stacks s;
//     s.top=-1;
//     push(10);
//     push(20);
//     push(30);
//     push(40);
//     pop();
//     pop();
//     print();
// }

// #include<bits/stdc++.h>
// using namespace std;
// struct queues{
//     int a[100];
//     int front,rear;
// }q;
// void enqueue(int x){
//     if(q.front==-1){
//         q.front=0;
//     }
//     q.rear++;
//     q.a[q.rear]=x;
// }
// void dequeue(){
//     q.front++;
//     if(q.front>q.rear){
//         q.front=-1;
//         q.rear=-1;
//     }
// }
// void print(){
//     for(int i=q.front ; i<=q.rear,q.front!=-1 ; ++i){
//         cout<<q.a[i]<<" ";
//     }
//     cout<<endl;
// }
// int main(){
//     q.front=-1;
//     q.rear=-1;
//     enqueue(10);
//     enqueue(20);
//     enqueue(30);
//     enqueue(40);
//     dequeue();
//     dequeue();
//     dequeue();
//     dequeue();
//     dequeue();
//     dequeue();
//     cout<<q.front<<" "<<q.rear<<endl;
//     print();
// }

// #include<bits/stdc++.h>
// using namespace std;
// struct stackll{
//     int data;
//     struct stackll *next;
// }s;
// struct stackll *head=NULL;
// void push(int x){
//     struct stackll *temp=new stackll;
//     temp->data=x;
//     temp->next=head;
//     head=temp;
// }
// void pop(){
//     if(head!=NULL){
//         head=head->next;
//     }
// }
// void print(){
//     if(head!=NULL){
//         struct stackll *temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<"->";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// }
// int main(){
//     push(10);
//     push(20);
//     push(30);
//     push(40);
//     print();
//     pop();
//     pop();
//     pop();
//     pop();
//     print();
// }

// #include<bits/stdc++.h>
// using namespace std;
// struct stackll{
//     int data;
//     struct stackll *next;
// }s;
// struct stackll *head=NULL;
// void push(int x){
//     struct stackll *temp=new stackll;
//     if(head==NULL){
//         // struct stackll *temp=new stackll;
//         temp->data=x;
//         temp->next=head;
//         head=temp;
//     }
//     else{
//         struct stackll *tmp=head;
//         while(tmp->next!=NULL){
//             tmp=tmp->next;
//         }
//         temp->data=x;
//         temp->next=NULL;
//         tmp->next=temp;
//     }
// }
// void pop(){
//     struct stackll *temp=head;
//     struct stackll *pptr=temp;
//     while(temp->next!=NULL){
//         pptr=temp;
//         temp=temp->next;
//     }
//     if(pptr!=temp){
//         pptr->next=NULL;
//     }
//     else{
//         head=NULL;
//     }
    
// }
// void print(){
//     if(head!=NULL){
//         struct stackll *temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// }
// int main(){
//     push(10);
//     push(20);
//     push(30);
//     push(40);
//     print();
//     pop();
//     pop();
//     pop();
//     pop();
//     print();
// }

// #include<bits/stdc++.h>
// using namespace std;
// struct queuell{
//     int data;
//     struct queuell *next;
// };
// struct queuell *head=NULL;
// void enqueue(int x){
//         struct queuell *temp=new queuell;
//         temp->data=x;
//         temp->next=head;
//         head=temp;
// }
// void dequeue(){
//     struct queuell *temp=head;
//     struct queuell *pptr=temp;
//     while(temp->next!=NULL){
//         pptr=temp;
//         temp=temp->next;
//     }
//     if(pptr!=temp){
//         pptr->next=NULL;
//     }
//     else{
//         head=NULL;
//     }
// }
// void print(){
//     if(head!=NULL){
//         struct queuell *temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// }
// int main(){
//     enqueue(10);
//     enqueue(20);
//     enqueue(30);
//     enqueue(40);
//     dequeue();
//     print();
// }

// #include<bits/stdc++.h>
// using namespace std;
// struct queuell{
//     int data;
//     struct queuell *next;
// };
// struct queuell *head=NULL;
// void enqueue(int x){
//     struct queuell *temp=new queuell;
//     if(head==NULL){
//         // struct stackll *temp=new stackll;
//         temp->data=x;
//         temp->next=head;
//         head=temp;
//     }
//     else{
//         struct queuell *tmp=head;
//         while(tmp->next!=NULL){
//             tmp=tmp->next;
//         }
//         temp->data=x;
//         temp->next=NULL;
//         tmp->next=temp;
//     }
// }
// void dequeue(){
//     if(head!=NULL){
//         head=head->next;
//     }
// }
// void print(){
//     if(head!=NULL){
//         struct queuell *temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// }
// int main(){
//     enqueue(10);
//     enqueue(20);
//     enqueue(30);
//     enqueue(40);
//     dequeue();
//     print();
// }
/////////////////////////////////////////////
// // c++ code without any header file
// extern "C"
// { 
//     int printf(const char *format,...); 
// } 
  
// int main() 
// { 
//     printf("GeeksforGeeks"); 
//     return 0; 
// } 
////////////////////////////////////////////
// #include<bits/stdc++.h>
// using namespace std;
// // void LogError(TCHAR * format, ...)
// // {
// //    va_list args;
// //    int len;
// //    TCHAR *buffer;

// //    va_start(args, format);
// //    len = _vscprintf(format, args) + 1;
// //    buffer = (TCHAR *) _alloca( len * sizeof(TCHAR) );
// //    vsprintf_s( buffer, len, format, args );
// //    CString strErrMsg = buffer;
// // }

// int Sum(int noOfArgs, ...)
// {
//     int nSum = 0;
//     va_list args;
//     va_start(args, noOfArgs);
//     // nSum = va_arg(args, int);
//     for(int i = 0; i < noOfArgs; i++) 
//     {
//         nSum += va_arg(args, int);
//     }
//     va_end(args);
//     return nSum;
// }

// int main()
// {
//     int nSum = Sum(6, 1, 2, 3, 4, 5, 10);
//     cout<<nSum<<endl;
//     // LogError(_T("Failed - %s, ErrorCode - %d"), "AccessDenied", 111);
//     return 0;
// }

// #include <stdarg.h>
// #include<bits/stdc++.h>
// using namespace std;
// //
// //
// void varargs_fn(int num, ...)
// {
//    va_list valst;

//    va_start(valst, num);

//    int n = 0;

//    for ( int i = 0 ; i < num ; i++ )
//    {
//     //   n = va_arg(valst, int);
//     cout<<va_arg(valst,int)<<endl;

//     //   printf("%d\n", n);
//    }

//    va_end(valst);
// }

// //
// //
// int main()
// {
//    varargs_fn(5, 2, 4, 6, 8, 10);

//    return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     for(int i=1 ; i<=n/2 ; ++i){
//         cout<<string(i,'*')<<string(n/2+1+n/2+1-(2*i),' ')<<string(i,'*')<<endl;
//     }
//     if(n%2!=0)
//     cout<<string((n/2)+1,'*')<<string((n/2)+1,'*')<<endl;
//     else
//     {
//         cout<<string(n/2,' ')<<string(1,'*')<<string(n/2,' ')<<endl;
//     }
    
//     for(int i=n/2 ; i>0 ; --i){
//         cout<<string(i,'*')<<string(n/2+1+n/2+1-(2*i),' ')<<string(i,'*')<<endl;
//     }
// }

// #include<bits/stdc++.h>
// #include<time.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     clock_t st = clock();
//     for(int i=1 ; i<=n/2 ; ++i){
//         cout<<string(i,'*')<<string(n/2+1+n/2+1-(2*i),' ')<<string(i,'*')<<"\n";
//     }
//     if(n%2!=0){
//         cout<<string((n/2)+1,'*')<<string((n/2)+1,'*')<<"\n";
//     }
    
//     else{
//         cout<<string(n/2,' ')<<string(1,'*')<<string(n/2,' ')<<"\n";
//     }
    
//     for(int i=n/2 ; i>0 ; --i){
//         cout<<string(i,'*')<<string(n/2+1+n/2+1-(2*i),' ')<<string(i,'*')<<"\n";
//     }
//     cout<<"Running time : "<<(clock()-st)/(CLOCKS_PER_SEC/1000000)<<"\n";
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     srand(time(NULL));
//     int n,m,x;
//     cin>>n>>m>>x;
//     cout<<n<<" "<<m<<" "<<x<<endl;
//     while(m--){
//         cout<<(rand()%n)+1<<" "<<(rand()%n)+1<<endl;
//     }

// }
// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
//     string m;
//     string original="RAR";
//     cin>>m;
//     int j=0;
//     int count=0;
//     for(int i=0 ; i<m.size() ; ++i){
//         if(m[i]!=original[j]){
//             count++;
//         }
//         j=(j+1)%3;
//     }
//     cout<<count;
//     return 0;
// }

// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main() { 
//     int q;
//     cin>>q;
//     while(q--){
//         string s;
//         cin>>s;
//         int flag=0;
//         for(int i=0 ; i<s.size()/2 ; ++i){
//             if(s[i]!=s[s.size()-i-1]){
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag){
//             cout<<"no"<<endl;
//         }
//         else{
//             cout<<"yes"<<endl;
//         }
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     ll n;
//     cin>>n;
//     int count=0;
//     while((n%10)!=8 && n>8){
//         n=n-8;
//         count++;
//     }
//     if(n%10==8){
//         cout<<count+1;
//     }
//     else{
//         cout<<-1;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,k;
//     cin>>n>>k;
//     vector<int>v(n);
//     v.clear();
//     int data;
//     for(int i=0 ; i<n ; ++i){
//         cin>>data;
//         v.push_back(data);
//     }
//     int count=0;
//     for(int i=0 ; i<n ; ++i){
//         for(int j=i+1 ; j<n ; ++j){
//             if(v[i]+v[j]==k){
//                 count++;
//             }
//         }
//     }
//     cout<<count;
//     return 0;
// }
// #include<iostream>
// #include<cstring>
// using namespace std ; 

// int main(){
//     char s[50] ; 
//     scanf("%s",s+1) ; 
//     int n = strlen(s+1) ;
//     cout<<n<<endl;
//     int count = 0 ; 
//     for(int i=0 ; s[i] ; i++){
//         count++ ; 
//         if(s[i] == '0')
//             printf("%c\n",s[i]) ; 
//     } 
//     printf("%d\n",count) ; 
//     return 0 ; 
// }
// int main(){
//     // int a[5]={1,3,3,3,5};
//     // auto r = equal_range(a, a+5, 3);
//     // cout << r.second-r.first<<endl;
//     vector<int> v;
//     v.push_back(3); // [3]
//     v.push_back(2); // [3,2]
//     v.push_back(5); // [3,2,5]
//     // cout << v[0] << "\n"; // 3
//     // cout << v[1] << "\n"; // 2
//     // cout << v[2] << "\n"; // 5
//     // for (int i = 0; i < v.size(); i++) {
//     // cout << v[i] << "\n";
//     // }
//     // for(auto &x:v){
//     //     cout<<x<<endl;
//     // }
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while (t--){
//         int n;
//         cin>>n;
//         int a[n];
//         ll count_even=0;
//         ll count_odd=0;
//         for(int i=0 ; i<n ; ++i){
//             cin>>a[i];
//             if(a[i]&1){
//                 count_odd++;
//             }
//             else{
//                 count_even++;
//             }
//         }
//         ll store=count_odd*count_even;
//         cout<<store<<endl;
//     }
    
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     ll a;
//     cin>>a;
//     ll val=(pow(2,floor(log2(a))+1)-1);
//     val=val^a;
//     cout<<a<<" "<<val<<"\n";
// }

// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     ll count=0;
//     while(t--){
//         ll n;
//         cin>>n;
//         if(__builtin_popcount(n)==1){
//             cout<<"true"<<endl;
//             count++;
//         }
//         cout<<count;
//     }
    
// }
/////////////////////////////////////////////////////////////
//count of integers
// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         int data;
//         int count=0;
        
//         for(int i=0 ; i<n ; ++i){
//             ll mul=1;
//             cin>>data;
//             for(int j=1 ; j<=data-1 ; ++j){
//                 mul= ((mul%data)*(j%data))%data;
//             }
//             if(mul==data-1){
//                 count++;
//             }
//         }
//         cout<<count<<"\n";
//     }
// }
//////////////////////////////////////////////////////////////////////
// #include<bits/stdc++.h>
// using namespace std;

// void dfs(int s, bool *visited, vector<int>*v){
//     if(visited[s]) return;
//     visited[s]=true;
//     cout<<s<<endl;
//     for(auto u:v[s]){
//         dfs(u,visited,v);
//     }
// }

// int main(int argc, char const *argv[]){
//     vector<int>v[6];
//     v[1].push_back(2);
//     v[1].push_back(4);
//     v[2].push_back(1);
//     v[2].push_back(3);
//     v[2].push_back(5);
//     v[3].push_back(2);
//     v[3].push_back(5);
//     v[4].push_back(1);
//     v[5].push_back(3);
//     v[5].push_back(2);
//     bool visited[6]={false};
//     dfs(5,visited,v);
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,q;
//     cin>>n>>q;
//     int a[n];
//     for(int i=0 ; i<n ; ++i){
//         cin>>a[i];
//     }

//     int x,y,l,m;
//     for(int i=0 ; i<q ; ++i){
//         cin>>x;
//         if(x == 1){
//             cin>>y;
//             a[y-1] = !a[y-1];
//         }
//         else if(x==0){
//             cin>>l>>m;
//             if(a[m-1]&1){
//                 cout<<"ODD";
//             }
//             else{
//                 cout<<"EVEN";
//             }
//         }
//     }
//    return 0; 
// }

// #include<bits/stdc++.h>
// using namespace std;

// void scnaf_leave_int(int *n){
//     register int c = getchar_unlocked();
//     for( ; (c<48 || c>57); c = getchar_unlocked() );
//     for( ; (c>47 && c<58); c = getchar_unlocked() );
// }
     
// void scnaf_int(int *n){
//     register int c = getchar_unlocked();
//     *n = 0;
//     for( ; (c<48 || c>57); c = getchar_unlocked() );
//     for( ; (c>47 && c<58); c = getchar_unlocked() ){
//         *n = (*n<<1) + (*n<<3) +c -48;
//     }
// }

// int main(){
//     int n;
//     scnaf_int(&n);
//     cout<<n;
// }

// C++ program to find Deteminant of a matrix 
// #include <bits/stdc++.h> 
// using namespace std; 

// // Dimension of input square matrix 
// #define N 4 

// // Function to get cofactor of mat[p][q] in temp[][]. n is current 
// // dimension of mat[][] 
// void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) 
// { 
// 	int i = 0, j = 0; 

// 	// Looping for each element of the matrix 
// 	for (int row = 0; row < n; row++) 
// 	{ 
// 		for (int col = 0; col < n; col++) 
// 		{ 
// 			// Copying into temporary matrix only those element 
// 			// which are not in given row and column 
// 			if (row != p && col != q) 
// 			{ 
// 				temp[i][j++] = mat[row][col]; 
//                 cout<<i<<" "<<j<<" "<<mat[row][col]<<endl;

// 				// Row is filled, so increase row index and 
// 				// reset col index 
// 				if (j == n - 1) 
// 				{ 
// 					j = 0; 
// 					i++; 
// 				} 
// 			} 
// 		} 
// 	} 
// } 

// /* Recursive function for finding determinant of matrix. 
// n is current dimension of mat[][]. */
// int determinantOfMatrix(int mat[N][N], int n) 
// { 
// 	int D = 0; // Initialize result 

// 	// Base case : if matrix contains single element 
// 	if (n == 1) 
// 		return mat[0][0]; 

// 	int temp[N][N]; // To store cofactors 

// 	int sign = 1; // To store sign multiplier 

// 	// Iterate for each element of first row 
// 	for (int f = 0; f < n; f++) 
// 	{ 
// 		// Getting Cofactor of mat[0][f] 
// 		getCofactor(mat, temp, 0, f, n); 
// 		D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1); 

// 		// terms are to be added with alternate sign 
// 		sign = -sign; 
// 	} 

// 	return D; 
// } 

// /* function for displaying the matrix */
// void display(int mat[N][N], int row, int col) 
// { 
// 	for (int i = 0; i < row; i++) 
// 	{ 
// 		for (int j = 0; j < col; j++) 
// 			printf(" %d", mat[i][j]); 
// 		printf("n"); 
// 	} 
// } 

// // Driver program to test above functions 
// int main() 
// { 
// 	/* int mat[N][N] = {{6, 1, 1}, 
// 					{4, -2, 5}, 
// 					{2, 8, 7}}; */

// 	int mat[N][N] = {   {1,2,3},
//                         {4,5,6},
//                         {7,8,9}
// 					}; 

// 	printf("Determinant of the matrix is : %d", 
// 			determinantOfMatrix(mat, 3)); 
// 	return 0; 
// } 


// // C++ program to find adjoint and inverse of a matrix 
// #include<bits/stdc++.h> 
// #include<stdio.h>
// #include<unistd.h>
// #include<pthread.h>
// #include<stdlib.h>
// #include<stdio.h>
// #include<sys/wait.h>
// #include<stdlib.h>
// #include<sys/types.h>
// #include<unistd.h>
// using namespace std; 
// int N=4; 
// struct cofactor{
//     int **A;
//     int **temp;
//     int p;
//     int q;
//     int n;
// };
// // Function to get cofactor of A[p][q] in temp[][]. n is current 
// // dimension of A[][] 
// void *getCofactor(void *param) 
// { 
//     struct cofactor *cof=param;
//     int **A=cof->A;
//     int **temp=cof->temp;
//     int p=cof->p;
//     int q=cof->q;
//     int n=cof->n;
// 	int i = 0, j = 0; 

// 	// Looping for each element of the matrix 
// 	for (int row = 0; row < n; row++) 
// 	{ 
// 		for (int col = 0; col < n; col++) 
// 		{ 
// 			// Copying into temporary matrix only those element 
// 			// which are not in given row and column 
// 			if (row != p && col != q) 
// 			{ 
// 				temp[i][j++] = cof->A[row][col]; 

// 				// Row is filled, so increase row index and 
// 				// reset col index 
// 				if (j == n - 1) 
// 				{ 
// 					j = 0; 
// 					i++; 
// 				} 
// 			} 
// 		} 
// 	} 
// } 

// /* Recursive function for finding determinant of matrix. 
// n is current dimension of A[][]. */
// int determinant(int A[N][N], int n) 
// { 
// 	int D = 0; // Initialize result 

// 	// Base case : if matrix contains single element 
// 	if (n == 1) 
// 		return A[0][0]; 

// 	int temp[N][N]; // To store cofactors 

// 	int sign = 1; // To store sign multiplier 

// 	// Iterate for each element of first row 
// 	for (int f = 0; f < n; f++) 
// 	{ 
// 		// Getting Cofactor of A[0][f]
//         struct cofactor * co= new cofactor;
//         co->A=A;
//         co->temp=temp;
//         co->p=0;
//         co->q=f;
//         co->n=n;
//         pthread_t tid;
//         pthread_create(&tid,NULL,getCofactor,co);
//         pthread_join(tid,NULL);
// 		// getCofactor(A, temp, 0, f, n); 
// 		D += sign * A[0][f] * determinant(temp, n - 1); 

// 		// terms are to be added with alternate sign 
// 		sign = -sign; 
// 	} 

// 	return D; 
// } 

// // Function to get adjoint of A[N][N] in adj[N][N]. 
// void adjoint(int A[N][N],int adj[N][N]) 
// { 
// 	if (N == 1) 
// 	{ 
// 		adj[0][0] = 1; 
// 		return; 
// 	} 

// 	// temp is used to store cofactors of A[][] 
// 	int sign = 1, temp[N][N]; 

// 	for (int i=0; i<N; i++) 
// 	{ 
// 		for (int j=0; j<N; j++) 
// 		{ 
// 			// Get cofactor of A[i][j]
//             struct cofactor * co= new cofactor;
//             co->A=A;
//             co->temp=temp;
//             co->p=i;
//             co->q=j;
//             co->n=N;
//             pthread_t tid;
//             pthread_create(&tid,NULL,getCofactor,co);
//             pthread_join(tid,NULL);
// 			// getCofactor(A, temp, i, j, N); 

// 			// sign of adj[j][i] positive if sum of row 
// 			// and column indexes is even. 
// 			sign = ((i+j)%2==0)? 1: -1; 

// 			// Interchanging rows and columns to get the 
// 			// transpose of the cofactor matrix 
// 			adj[j][i] = (sign)*(determinant(temp, N-1)); 
// 		} 
// 	} 
// } 

// // Function to calculate and store inverse, returns false if 
// // matrix is singular 
// bool inverse(int A[N][N], float inverse[N][N]) 
// { 
// 	// Find determinant of A[][] 
// 	int det = determinant(A, N); 
// 	if (det == 0) 
// 	{ 
// 		cout << "Singular matrix, can't find its inverse"; 
// 		return false; 
// 	} 

// 	// Find adjoint 
// 	int adj[N][N]; 
// 	adjoint(A, adj); 

// 	// Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
// 	for (int i=0; i<N; i++) 
// 		for (int j=0; j<N; j++) 
// 			inverse[i][j] = adj[i][j]/float(det); 

// 	return true; 
// } 

// // Generic function to display the matrix. We use it to display 
// // both adjoin and inverse. adjoin is integer matrix and inverse 
// // is a float. 
// template<class T> 
// void display(T A[N][N]) 
// { 
// 	for (int i=0; i<N; i++) 
// 	{ 
// 		for (int j=0; j<N; j++) 
// 			cout << A[i][j] << " "; 
// 		cout << endl; 
// 	} 
// } 

// // Driver program 
// int main() 
// { 
// 	int A[N][N] = { {5, -2, 2, 7}, 
// 					{1, 0, 0, 3}, 
// 					{-3, 1, 5, 0}, 
// 					{3, -1, -9, 4}}; 

// 	int adj[N][N]; // To store adjoint of A[][] 

// 	float inv[N][N]; // To store inverse of A[][] 

// 	cout << "Input matrix is :\n"; 
// 	display(A); 

// 	cout << "\nThe Adjoint is :\n"; 
// 	adjoint(A, adj); 

// 	cout << "\nThe Inverse is :\n"; 
// 	if (inverse(A, inv)) 
// 		display(inv); 

// 	return 0; 
// } 


// #include <algorithm>
// #include <iostream>
// #include <numeric>
// #include <vector>
// #include<bits/stdc++.h>
// using namespace std;
// void polyRegression(const std::vector<int>& x, const std::vector<int>& y) {
//     int n = x.size();
//     std::vector<int> r(n);
//     std::iota(r.begin(), r.end(), 0);
//     double xm = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
//     double ym = std::accumulate(y.begin(), y.end(), 0.0) / y.size();
//     double x2m = std::transform_reduce(r.begin(), r.end(), 0.0, std::plus<double>{}, [](double a) {return a * a; }) / r.size();
//     double x3m = std::transform_reduce(r.begin(), r.end(), 0.0, std::plus<double>{}, [](double a) {return a * a * a; }) / r.size();
//     double x4m = std::transform_reduce(r.begin(), r.end(), 0.0, std::plus<double>{}, [](double a) {return a * a * a * a; }) / r.size();
 
//     double xym = std::transform_reduce(x.begin(), x.end(), y.begin(), 0.0, std::plus<double>{}, std::multiplies<double>{});
//     xym /= fmin(x.size(), y.size());
 
//     double x2ym = std::transform_reduce(x.begin(), x.end(), y.begin(), 0.0, std::plus<double>{}, [](double a, double b) { return a * a * b; });
//     x2ym /= fmin(x.size(), y.size());
 
//     double sxx = x2m - xm * xm;
//     double sxy = xym - xm * ym;
//     double sxx2 = x3m - xm * x2m;
//     double sx2x2 = x4m - x2m * x2m;
//     double sx2y = x2ym - x2m * ym;
 
//     double b = (sxy * sx2x2 - sx2y * sxx2) / (sxx * sx2x2 - sxx2 * sxx2);
//     double c = (sx2y * sxx - sxy * sxx2) / (sxx * sx2x2 - sxx2 * sxx2);
//     double a = ym - b * xm - c * x2m;
 
//     auto abc = [a, b, c](int xx) {
//         return a + b * xx + c * xx*xx;
//     };
 
//     std::cout << "y = " << a << " + " << b << "x + " << c << "x^2" << std::endl;
//     std::cout << " Input  Approximation" << std::endl;
//     std::cout << " x   y     y1" << std::endl;
 
//     auto xit = x.cbegin();
//     auto xend = x.cend();
//     auto yit = y.cbegin();
//     auto yend = y.cend();
//     while (xit != xend && yit != yend) {
//         printf("%2d %3d  %5.1f\n", *xit, *yit, abc(*xit));
//         xit = std::next(xit);
//         yit = std::next(yit);
//     }
// }
 
// int main() {
//     // using namespace std;
 
//     vector<int> x(11);
//     iota(x.begin(), x.end(), 0);
 
//     vector<int> y{ 1, 6, 17, 34, 57, 86, 121, 162, 209, 262, 321 };
 
//     polyRegression(x, y);
 
//     return 0;
// }

// // CPP program to illustrate 
// // std :: inner_product 
// #include <iostream> // std::cout 
// #include <functional> // std::minus, std::divides 
// #include <numeric> // std::inner_product 
// using namespace std;
// // Driver code 
// int main() 
// { 
// 	// The value which is added after 
// 	// finding inner_product b/w elements 
// 	int init = 0; 
// 	int series1[] = { 10, 20, 30 }; 
// 	int series2[] = { 1, 2, 3 }; 
// 	int n = sizeof(series1) / sizeof(series1[0]); 

// 	// Elements in series1 
// 	std::cout << "First array contains :"; 
// 	for (int i = 0; i < n; i++) 
// 		std::cout << " " << series1[i]; 
// 	std::cout << "\n"; 

// 	// Elements in series2 
// 	std::cout << "Second array contains :"; 
// 	for (int i = 0; i < n; i++) 
// 		std::cout << " " << series2[i]; 
// 	std::cout << "\n\n"; 

// 	std::cout << "Using default inner_product: "; 
// 	std::cout << std::inner_product(series1, series1 + n, series2, init); 
// 	std::cout << '\n'; 

// 	return 0; 
// } 


//////////////////////////////////////////random string generation////////////////////////////////////////////////////////
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     // cout<<string(200,'h')<<'a'<<string(198,'e')<<string(200,'l')<<string(200,'l')<<string(200,'o')<<endl;
//     srand(time(NULL));
//     char ch[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//     string s="";
//     int freq[26]={0};
//     for(int i=0 ; i<100000 ; ++i){
//         int num=rand()%26;
//         s+=ch[num];
//         freq[num]+=1;
//     }
//     for(int i=0 ; i<26 ; ++i){
//         if(freq[i]!=0){
//             cout<<(char)(i+97)<<" "<<freq[i]<<endl;
//         }
//     }
//     cout<<s<<endl;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s="fbfleqiexbzdekfnceufzhicwxisixioanbegmlfnkitwqhyubgvioxgniawhimivpodbziqltkijrifuqcehbkulmstugdrwrvxrfocyamjrvqnlsrswdphrhclofekxzjqhzufzhrsehhrcamydbfukihynmkmnwcuxxczgtrkcbdebpchqkbbslbhzowmmyjjxnificrkdvpgktnbdrexchfbvbphbatbnbgvfygktxrfqeiuvmrzwyatbsbfswggzobfojrjgipzpxtmmmminmboeetxabfasghgsasylhzagsmshycunektkgqljxnbewkyweyhlyjtswozwqvjwifhovuxvjbbflzdpxncvwxoulptcleytjfjhbgckjdrwcxnzkpviplfaaycncdgoirvkaxwjaogeltdxlahalmammfzriifszaezxblzprdcmibxjizwvakjhmapufhvhmxgnifebkintjlermaoonyvzakvguqpgpwvwvzdbateolojawbnnnperccexbekymepcqcmjmgajgdkgrxwcothxrinhoplsopzianneepslpbrvnzmkwpfvioipczdxqswqhjxmbpz";
//     int freq[26]={0};
//     for(int i=0 ; i<s.size() ; ++i){
//         freq[s[i]-97]++;
//     }
//     for(int i=0 ; i<26 ; ++i){
//         if(freq[i]!=0){
//             cout<<(char)(i+97)<<" "<<freq[i]<<endl;
//         }
//     }
//     cout<<s.size()<<endl;
    
// }



// #include<bits/stdc++.h>
// #define ll long long int
// #define M 1000000007
// #define graph vector< vector<ll> > (n+1)
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     string s;
//     cin>>s;
//     int result=(int)s[0];
//     for(int i=1; i<s.size(); i++){
//         result^=(int)s[i];
//     }
//     cout<<(char)result<<'\n';
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int modpow(int x, int n, int m) {
//     if (n == 0){
//         return 1%m;
//     } 
//     long long u = modpow(x,n/2,m);
//     u = (u*u)%m;
//     if (n%2 == 1){
//         u = (u*x)%m;
//     } 
//     return u;
// }

// int main(){

//     cout<<modpow(2,20,5)<<endl;
// }


// C++ program to find sum of two large numbers. 
// #include<bits/stdc++.h> 
// using namespace std; 
  
// string findSum(string str1, string str2) { 
//     if (str1.size() > str2.size()){
//         swap(str1, str2); 
//     }
        
  
//     string str = ""; 
//     int n1 = str1.length(), n2 = str2.length(); 
//     int diff = n2 - n1; 
//     int carry = 0; 
//     for (int i=n1-1; i>=0; i--) { 
//         int sum = ((str1[i]-'0') + 
//                    (str2[i+diff]-'0') + 
//                    carry); 
//         str.push_back(sum%10 + '0'); 
//         carry = sum/10; 
//     } 
//     for (int i=n2-n1-1; i>=0; i--) { 
//         int sum = ((str2[i]-'0')+carry); 
//         str.push_back(sum%10 + '0'); 
//         carry = sum/10; 
//     }  
//     if (carry){
//         str.push_back(carry+'0'); 
//     } 
//     reverse(str.begin(), str.end()); 
//     return str; 
// } 
  
// int main() { 
//     string a,b;
//     while(cin>>a>>b) 
//     cout << findSum(str1, str2); 
//     return 0; 
// } 


// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     ll count=0;
//     ll data;
//     cin>>data;
//     int bit=log2(data)+1;
//     cout<<bit-__builtin_popcountll(data)<<endl;
// }

// #include <iostream>     // std::cout
// #include <functional>   // std::plus
// #include <algorithm>    // std::transform
// using namespace std;

// int main () {
//   int first[]={1,2,3,4,5};
//   int second[]={10,20,30,40,50};
//   int results[5];
//   transform (first, first+5, second, results, plus<int>());
//   for (int i=0; i<5; i++)
//         cout << results[i] << ' ';
//   cout << '\n';
//   return 0;
// }
#include <vector>
#include <functional>
#include <iostream>
#include <numeric>
#include <execution>
 using namespace std;
int main()
{
    std::vector<double> xvalues(10007, 1.0), yvalues(10007, 1.0);
 
    double result = std::transform_reduce(
        std::execution::par,
        xvalues.begin(), xvalues.end(),
        yvalues.begin(), 0.0
    );
    std::cout << result << '\n';
}

