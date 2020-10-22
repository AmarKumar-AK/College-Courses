#include <stdio.h>
struct List
{
	int a[20];
	int lsize;
};
void insert(struct List *pl,int pos, int x);
void print(struct List pll);
int main()
{
	int j;
	struct List l;
	l.lsize=-1;
    insert(&l,0,20);
    insert(&l,1,10);
    print(l);
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
	for(j=0;j<=pll.lsize;j++)
    	printf("%d\n",pll.a[j]);

}
