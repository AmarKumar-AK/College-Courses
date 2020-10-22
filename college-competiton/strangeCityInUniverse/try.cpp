#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int n;
    cin>>n;
    cout<<n<<endl;
    string name[100]={"amar","kumar","praveen","rana","saumya","prakash","firoz","mohammad","vaibhav","singhal","samarth","vats","bazif","rasool","shiv","shankar","krishna","sutar","aviral","rai","aaditya","srinivas","allen","alex","arun","sandesh","arindam","sharma","john","cena","ritvik","raj","virat","kohli","anushka","singh","harman","deep","tarun","kantiwal","sparsh","kataria","hrithik","roshan","shahrukh","khan","siddhart","malhotra","kartik","narayan","gulshan","sunny","abhay","ranjan","satyam","kishan","manisha","sunita","geeta","anita","ranju","manju","sanju","sushma","sunaina","suman","babita","rajveer","seema","sonam","madhu","pawan","pritam","parth","patel","hrishikesh","vedantam","arjun","ramesh","keshar","bhaavana","thumu","bhavani","atul","maria","philna","aruja","dikshanya","ram","gopi","raju","kishore","jane","austen","steve","smith","yuvraj","orton","anand","bharti"};
    for(int i=0 ; i<n ; ++i){
        int num=rand()%100;
        cout<<name[num]<<endl;
    }
}
