#include<bits/stdc++.h>
#define SIZE 6
using namespace std;
struct roundrobin
{
    public:
        int pid;
        int a_t;
        int b_t;
        int c_t;
        int ta_t;
        int w_t;
};

int main()
{
    struct roundrobin r[SIZE];
    int time_quantum=2;
    int time=0;
    int a[]={0,3,4,8,10,11};
    int b[]={1,5,2,8,3,4};
    for(int i=0 ; i<SIZE ; ++i)
    {
        r[i].pid=i;
        r[i].a_t=a[i];
        r[i].b_t=b[i];
    }

    // list<int>a_t(a1,a1+SIZE);
    // list<int>b_t(a2,a2+SIZE);
    vector<int>ready_queue;

    time=time+a[0];
    ready_queue.push_back(r[0].pid);

    int ct=0;
    while(ct!=SIZE)
    {
        if(r[ready_queue.front()].b_t<=time_quantum)
        {
            cout<<"count = "<<ct<<endl;
            int itr=ready_queue.front();
            // list<int>::iterator itr=ready_queue.begin();

            time += r[itr].b_t;
            r[itr].c_t = time;
            b[itr]=0;
            cout<<"burst time in if = ";
            for(int i=0 ; i<SIZE ; ++i)
            {
                cout<<b[i]<<" ";
            }
            cout<<endl;
            cout<<"time in if = "<<time<<endl;
            // cout<<"hello in if"<<endl;
            // r[*itr].b_t = 0;
            // a_t.erase(itr);
            // b_t.erase(itr);
            // ready_queue.pop_front();
            vector<int>::iterator itrs;
            itrs=ready_queue.begin();
            ready_queue.erase(itrs);
            ct++;
        }
        else
        {
            // cout<<"hello in else"<<endl;
            int itr=ready_queue.front();
            // list<int>::iterator itr=ready_queue.begin();
            time += time_quantum;
            r[itr].b_t -= time_quantum;
            b[itr] -= time_quantum;
            cout<<"burst time in else = ";
            for(int i=0 ; i<SIZE ; ++i)
            {
                cout<<b[i]<<" ";
            }
            cout<<endl;
            cout<<"time in else = "<<time<<endl;
            for(int i=0 ; i<SIZE ; ++i)
            {
                if(time>=a[i] && b[i]!=0)
                {
                    if(!count(ready_queue.begin(),ready_queue.end(),i))
                    {
                        ready_queue.push_back(i);
                    }
                }
            }
            cout<<"push_back = "<<ready_queue.front()<<endl;
            cout<<"ready_queue = ";
            for(int &x : ready_queue)
            {
                cout<<x<<" ";
            }
            cout<<endl;
            ready_queue.push_back(ready_queue.front());
            // ready_queue.pop_front();
            vector<int>::iterator itrs;
            itrs=ready_queue.begin();
            ready_queue.erase(itrs);
        }

        if(ready_queue.empty())
        {
            cout<<"hello in empty"<<endl;
            while(ready_queue.empty())
            {
                for(auto i=0 ; i<SIZE ; ++i)
                {
                    if(time>=a[i] && b[i]!=0)
                    {
                        ready_queue.push_back(i);
                    }
                }
                int cnt=0;
                for(auto i=0 ; i<SIZE ; ++i)
                {
                    if(b[i]==0)
                    {
                        cnt++;
                    }
                }
                if(cnt==SIZE)
                {
                    break;
                }
                
                if(ready_queue.empty())
                {
                    time=time+1;
                    cout<<"time in empty = "<<time<<endl;
                }
            }
        }
    }

    cout<<endl;
    for(int i=0 ; i<SIZE ; ++i)
    {
        cout<<r[i].c_t<<" ";
    }


    return 0;
}