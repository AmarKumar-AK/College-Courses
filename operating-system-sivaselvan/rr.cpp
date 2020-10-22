#include<bits/stdc++.h>
#define SIZE 6
using namespace std;
struct roundrobin
{
    public:
        int pid,a_t,b_t,c_t,ta_t,w_t;
};

int main()
{
    struct roundrobin r[SIZE];
    int time_quantum=5;
    cout<<time_quantum<<endl;
    int time=0;
    int a[]={0,3,4,8,10,11};
    int b[]={1,5,2,8,3,4};
    int b_copy[]={1,5,2,8,3,4};
    for(int i=0 ; i<SIZE ; ++i)
    {
        r[i].pid=i;
        r[i].a_t=a[i];
        r[i].b_t=b[i];
    }
    list<int>ready_queue;

    time=time+a[0];
    ready_queue.push_back(r[0].pid);

    int ct=0;
    while(ct!=SIZE)
    {
        if(b[ready_queue.front()]<=time_quantum)
        {
            int itr=ready_queue.front();
            time += b[itr];
            r[itr].c_t = time;
            b[itr]=0;
            ready_queue.pop_front();
            ct++;
        }
        else
        {
            int itr=ready_queue.front();
            time += time_quantum;
            b[itr] -= time_quantum;
           
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
            ready_queue.push_back(ready_queue.front());
            ready_queue.pop_front();
        }

        if(ready_queue.empty())
        {
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
                        cnt++;
                }
                if(cnt==SIZE)
                {
                    break;
                }
                
                if(ready_queue.empty())
                {
                    time=time+1;
                }
            }
        }
    }
    int sum=0;
    for(int i=0 ; i<SIZE ; ++i)
    {
        r[i].ta_t = r[i].c_t - r[i].a_t;
        r[i].w_t = r[i].ta_t - r[i].b_t;
        sum=sum+r[i].w_t;
    }
    cout<<"pid\tat\tbt\tct\ttat\twt"<<endl;
    for(int i=0 ; i<SIZE ; ++i)
    {
        cout<<r[i].pid<<"\t"<<r[i].a_t<<"\t"<<r[i].b_t<<"\t"<<r[i].c_t<<"\t"<<r[i].ta_t<<"\t"<<r[i].w_t<<endl;
    }
    cout<<"average wait time = "<<(float)sum/SIZE<<endl;
    return 0;
}