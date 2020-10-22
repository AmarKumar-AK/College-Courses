#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3][3]={   {0,1,0},
                    {1,1,0},
                    {0,1,0}  };
    int p[3]={1,1,1};
    int count;
    int index;
    for(int i=0 ; i<2 ; ++i)
    {
        
        for(int j=i+1 ; j<3 ; ++j)
        {
            if(a[i][j]==1)
            {
                p[i]=0;
            }
            else if(a[j][i]==1)
            {
                p[j]=0;
            }
            count=0;
            for(int k=0 ; k<3 ; ++k)
            {
                if(p[k]==1)
                {
                    count++;
                    index=k;
                }
            }
        }
        if(count==1)
        {
            break;
        }
    }
    int col=0;
    int row=0;
    for(int i=0 ; i<3 ; ++i)
    {
        if(a[i][index]==1)
        col++;
        if(a[index][i]==1)
        row++;
    }
    if(row==1 && col==3)
        cout<<"present at "<<index<<endl;
    else
    {
        cout<<"not present"<<endl;
    }
    
}