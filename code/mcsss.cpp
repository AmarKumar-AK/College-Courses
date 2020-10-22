#include<bits/stdc++.h>
using namespace std;

class DNA
{
        char S[20];
        char F[20];
   public:
        void read();
        void bruteForce();
        void incDesign();
        int divNconFather(int ,int );
        int divNconSon(int ,int );
        void prunning();
        void print();
}d;
int first,last;
int Father[20], Son[20];
int maximumFather,maximumSon;
int startf,starts,finishf,finishs;
void DNA::read()
{   
    //sequence must contain only A,C,G & T
    //A= 2  ,C= 1  ,G= -1  ,T= -2  
    cout<<"enter DNA sequence for father"<<endl;
    cin>>F;
    cout<<"enter DNA sequence for son"<<endl;
    cin>>S;
    first=0;
    last=strlen(F);
    if(strlen(F)==strlen(S))
    {
        //assigning integer value to the sequence for father
        for(int i=0 ; i<strlen(F) ; ++i)
        {
            if(F[i]=='A')
                Father[i]=2;
            else if(F[i]=='C')
                Father[i]=1;
            else if(F[i]=='G')
                Father[i]=-1;
            else if(F[i]=='T')
                Father[i]=-2;
            else
            {
                cout<<"incorrect input for father"<<endl;
                break;
            }
        }//end for
        
        //assigning integer value to the sequence for son
        for(int i=0 ; i<strlen(S) ; ++i)
        {
            if(S[i]=='A')
                Son[i]=2;
            else if(S[i]=='C')
                Son[i]=1;
            else if(S[i]=='G')
                Son[i]=-1;
            else if(S[i]=='T')
                Son[i]=-2;
            else
            {
                cout<<"incorrect input for son"<<endl;
                break;
            }
        }//end for
        //printing the sequence
        /*cout<<"\nSequence for father"<<endl;
        for(int i=0 ; i<strlen(F) ; ++i)
            cout<<Father[i]<<" ";
        cout<<"\nsequence for son"<<endl;
        for(int i=0 ; i<strlen(S) ; ++i)
            cout<<Son[i]<<" ";*/        
      }
        
    
}//end read
///////////////////////////////////////////////////////////
void DNA::print()
{
   //DNA check using bruteForce algorithm
   cout<<endl<<"beginf : "<<startf<<endl<<"endf : "<<finishf<<endl<<"begins : "<<starts<<endl<<"ends : "<<finishs;
    cout<<endl<<"using divide & conquer algorithm : ";
    cout<<endl<<"contiguous sequence for father is : ";
    for(int i=startf ; i<=finishf ; ++i)
    {
        cout<<F[i];
    }
    cout<<endl<<"contiguous sequence for son is : ";
    for(int i=starts ; i<=finishs ; ++i)
    {
        cout<<S[i];
    }
    if(abs(maximumSon-maximumFather)<=10)
    {
        cout<<endl<<"DNA matched"<<endl;
        cout<<"For father : "<<maximumFather<<endl;
        cout<<"For son : "<<maximumSon<<endl;
    }
    else
    {
        cout<<endl<<"DNA does not matched"<<endl;
        cout<<"For father : "<<maximumFather<<endl;
        cout<<"For son : "<<maximumSon<<endl;
    }
   
        
    
}//end print
///////////////////////////////////////////////////////////
void DNA::bruteForce()
{
    //msumf:max sum for father
    //sumf:current sum for father
    //beginf:starting of MCSSS for father
    //endf:ending of MCSSS for father
    
    int msumf=0,i,j,k,sumf,msums=0,sums;
    int beginf,endf,begins,ends;
 
    for(i=0 ; i<strlen(F) ; ++i)
    {
        
        for(j=i ; j<strlen(F) ; ++j)
        {
            
            
            sumf=0;
            sums=0;
            for(k=i ; k<=j ; ++k)
            {
                sumf=sumf+Father[k];
                sums=sums+Son[k];
            }//end for k
            if(msumf<sumf)
            {
                msumf=sumf;
                beginf=i;
                endf=j;
            }//end if
            if(msums<sums)
            {
                msums=sums;
                begins=i;
                ends=j;
            }//end if
        }//end for j
    }//end for i
    
    cout<<endl<<"beginf : "<<beginf<<endl<<"endf : "<<endf<<endl<<"begins : "<<begins<<endl<<"ends : "<<ends;
    cout<<"\nusing bruteForce algorithm";
    cout<<endl<<"contiguous sequence for father is : ";
    for(int i=beginf ; i<=endf ; ++i)
    {
        cout<<F[i];
    }
    cout<<endl<<"contiguous sequence for son is : ";
    for(int i=begins ; i<=ends ; ++i)
    {
        cout<<S[i];
    }
    
    
    if(abs(msums-msumf)<=10)
    {
        cout<<endl<<"DNA matched"<<endl;
        cout<<"For father : "<<msumf<<endl;
        cout<<"For son : "<<msums<<endl;
    }   
    else
    {
        cout<<endl<<"DNA does not match"<<endl;
        cout<<"For father : "<<msumf<<endl;
        cout<<"For son : "<<msums<<endl;
    }
}//end bruteForce function
///////////////////////////////////////////////////////////
void DNA::incDesign()
{
    int msumf=0,i,j,sumf,msums=0,sums;
    int beginf,endf,begins,ends;
    for(i=0 ; i<strlen(F) ; ++i)
    {
        sumf=0;
        sums=0;
        for(j=i ; j<strlen(S) ; ++j)
        {
            sumf=sumf+Father[j];
            sums=sums+Son[j];
            if(msumf<sumf)
            {
                msumf=sumf;
                beginf=i;
                endf=j;
            }//end if
            if(msums<sums)
            {
                msums=sums;
                begins=i;
                ends=j;
            }//end if
        }//end for j
    }//end for i
    cout<<endl<<"beginf : "<<beginf<<endl<<"endf : "<<endf<<endl<<"begins : "<<begins<<endl<<"ends : "<<ends;
    cout<<"\nusing incDesign algorithm";
    
    cout<<endl<<"contiguous sequence for father is : ";
    for(int i=beginf ; i<=endf ; ++i)
    {
        cout<<F[i];
    }
    cout<<endl<<"contiguous sequence for son is : ";
    for(int i=begins ; i<=ends ; ++i)
    {
        cout<<S[i];
    }
    if(abs(msums-msumf)<=10)
    {
        cout<<endl<<"DNA matched"<<endl;
        cout<<"For father : "<<msumf<<endl;
        cout<<"For son : "<<msums<<endl;
    }   
    else
    {
        cout<<endl<<"DNA does not match"<<endl;
        cout<<"For father : "<<msumf<<endl;
        cout<<"For son : "<<msums<<endl;
    }
    
}//end incDesign function
///////////////////////////////////////////////////////////
void DNA::prunning()
{
    int msumf=0,msums=0,csumf=0,csums=0,i;
    int beginf=0,endf,begins=0,ends;
    
    for(i=0 ; i<strlen(F) ; ++i)
    {
        csumf=csumf+Father[i];
        csums=csums+Son[i];
        if(csumf<0)
        {
            csumf=0;
            beginf=i+1;
        }
        if(csumf>msumf)
         {
            msumf=csumf;
            endf=i;
        }
        if(csums<0)
         {
            csums=0;
            begins=i+1;
        }
        if(csums>msums)
        { 
            msums=csums;
            ends=i;
        }
    }
    cout<<endl<<"beginf : "<<beginf<<endl<<"endf : "<<endf<<endl<<"begins : "<<begins<<endl<<"ends : "<<ends;
    cout<<"\nusing prunning algorithm";
    cout<<endl<<"contiguous sequence for father is : ";
    for(int i=beginf ; i<=endf ; ++i)
    {
        cout<<F[i];
    }
    cout<<endl<<"contiguous sequence for son is : ";
    for(int i=begins ; i<=ends ; ++i)
    {
        cout<<S[i];
    }
    if(abs(msums-msumf)<=10)
    {
        cout<<endl<<"DNA matched"<<endl;
        cout<<"For father : "<<msumf<<endl;
        cout<<"For son : "<<msums<<endl;
    }   
    else
    {
        cout<<endl<<"DNA does not match"<<endl;
        cout<<"For father : "<<msumf<<endl;
        cout<<"For son : "<<msums<<endl;
    }
}
//////////////////////////////////////////////////////////
int DNA::divNconFather(int begf,int endf)
{
	
    if(begf==endf)
    {
        if(Father[begf]<0)
        {
            return 0;
        }
        else
        {
            return Father[begf];
        }
       
    }
    int midf=(begf+endf)/2;
    int LSf=divNconFather(begf,midf);
    int RSf=divNconFather(midf+1,endf);
    int rosumf=0;
    int rsumf=0;
    int i;
    for(i=midf ; i<strlen(F) ; ++i)
    {
        rsumf=rsumf+Father[i];
        if(rsumf>rosumf)
        {
            rosumf=rsumf;
            finishf=i;
        }
    }
    
    int losumf=0;
    int lsumf=0;
    for(i=midf-1 ; i>=begf ; --i)
    {
        lsumf=lsumf+Father[i];
        if(lsumf>losumf)
        {
            losumf=lsumf;
            startf=i;
        }
    }
    
    int maxf=LSf;
    int msumf=losumf+rosumf;
    if(msumf>maxf)
    {
        maxf=msumf;
    }
    if(RSf>maxf)
    {
        maxf=RSf;
    }
    maximumFather=maxf;
    
    
    
    /*cout<<"\nusing divNcon algorithm"<<endl;
    if(abs(maxf-maxs)<=10)
    {
        cout<<"DNA matched"<<endl;
        //cout<<"For father : "<<msumf<<endl;
        //cout<<"For son : "<<msums<<endl;
    }   
    else
    {
        cout<<"DNA does not match"<<endl;
        //cout<<"For father : "<<msumf<<endl;
        //cout<<"For son : "<<msums<<endl;
    }*/
}
/////////////////////////////////////////////////////////
int DNA::divNconSon(int begs,int ends)
{
    if(begs==ends)
    {
         if(Son[begs]<0)
        {
            return 0;
        }
        else
        {
            return Son[begs];
        }
    }
    
    int mids=(begs+ends)/2;
    int LSs=divNconSon(begs,mids);
    int RSs=divNconSon(mids+1,ends);
    
    int losums=0;
    int lsums=0;
    int i;
    for(i=mids-1 ; i>=begs ; --i)
    {
        lsums=lsums+Son[i];
        if(lsums>losums)
        {
            losums=lsums;
            starts=i;
        }
    }
    
    int rosums=0;
    int rsums=0;
    for(i=mids ; i<strlen(S) ; ++i)
    {
        rsums=rsums+Son[i];
        if(rsums>rosums)
        {
            rosums=rsums;
            finishs=i;
        }
    }
    
    int maxs=LSs;
    int msums=losums+rosums;
    if(msums>maxs)
    {
        maxs=msums;
    }
    if(RSs>maxs)
    {
        maxs=RSs;
    }
    maximumSon=maxs;
    
}

/////////////////////////////////////////////////////////
int main()
{
    d.read();
    d.bruteForce();
    d.incDesign();
    d.prunning();
    d.divNconFather(first,last);
    d.divNconSon(first,last);
    d.print();
    
    
    
}//end main




