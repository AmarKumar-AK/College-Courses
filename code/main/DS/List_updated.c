#include <stdio.h>
struct List
{
	int a[20];
	int lsize;
};
void insert(struct List *pl,int pos, int x);
int del(struct List *pl,int pos);
void print(struct List pll);
int search(struct List *pl, int x);
int isFull(struct List l);
int isEmpty(struct List l);



int main()
{
	int j;
	struct List l;
	l.lsize=0;
    	insert(&l,0,20);
    	insert(&l,1,10);
	insert(&l,1,40);
	insert(&l,1,50);
	insert(&l,1,60);
    	print(l);
	printf("the deleted value is %d\n",del(&l,0));
	print(l);
        printf("%d\n",search(&l,40));
	printf("%d",isEmpty(l));
	printf("\n%d",isFull(l));
	return 0;
}
void insert(struct List *pl,int pos, int x)
{
	int i;
	
	for(i=pl->lsize;i>=pos;i--)
		pl->a[i+1]=pl->a[i];
	pl->a[pos]=x;
	pl->lsize++;
}
void print(struct List pll)
{
	int j;
	for(j=0;j<pll.lsize;j++)
    	printf("%d\n",pll.a[j]);

}

int del(struct List *pl,int pos)
{
	int i,x=pl->a[pos];
	for(i=pos+1;i<pl->lsize;i++)
	{
		pl->a[i-1]=pl->a[i];
	}
	(pl->lsize)--;
	return(x);
		
}

int search(struct List *pl, int x)
{
	int i,pos=-1;
	
	for(i=0;i<pl->lsize;i++)
		if(pl->a[i]==x)
		{
			pos=i;			
			break;
		}
	return(pos);
}

int isEmpty(struct List l)
{
	if(l.lsize==0)
 		return(1);
	else
		return(0);

}

int isFull(struct List l)
{
	if(l.lsize==20)
 		return(1);
	else
		return(0);

}

