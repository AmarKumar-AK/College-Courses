#include<stdio.h>
void main()
{
int A,B,C,D,a,b,c,d,e,p,q,r,s,t;

printf("enter a,b,c,d,e\n");
scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
/*
A=axb;   
B=bxc;
C=cxd;      //A,B,C,D are four matrices and (axb), (bxc), (cxd), (dxe) are their orders respectively
D=dxe;

((AB)C)D=p;
(A(BC))D=q;
A((BC)D)=r; 
A(B(CD))=s;
(AB)(CD)=t;
*/
p=a*b*c+a*c*d+a*d*e;  
q=a*b*d+b*c*d+a*d*e;
r=a*b*e+b*c*d+b*d*e;    //p,q,r,s,t are no. of scalar multiplication 
s=a*b*e+b*c*e+c*d*e;
t=a*b*c+c*d*e+a*c*e;

if(p<q && p<r && p<s && p<t)
{printf("p has minimum scalar multiplication\n");}
else if(q<p && q<r && q<s && q<t)
{printf("q has minimum scalar multiplication\n");}
else if(r<p && r<q && r<s && r<t)
{printf("r has minimum scalar multiplication\n");}
else if(s<p && s<q && s<r && s<t)
{printf("s has minimum scalar multiplication\n");}
else if(t<p && t<q && t<r && t<s)
{printf("t has minimum scalar multiplication\n");}
else
{printf("two or more has same no. of scalar multiplication\n");}

}

