#include <stdio.h>
struct List
{
	int a[20];
	int lsize;//here lsize is used to count no of var in array a which have a VALUE ASSIGNED TO THEM
};
void insert(struct List *amar,int pos, int x);//prototype
void print(struct List *kumar);//prototype
int main()
{
	int j;
	struct List l;
	l.lsize=-1;
    insert(&l,0,20);
    insert(&l,1,10);
    print(&l);
	return 0;
}
void insert(struct List *amar,int pos, int x)
{
	int i;
	
	for(i=amar->lsize ; i>=pos ; i--)
		amar->a[i+1] = amar->a[i];
	amar->a[pos]=x;
	amar->lsize++;
}
void print(struct List *kumar )
{
	int j;
	for(j=0;j<=kumar->lsize;j++)
    	printf("%d\n",kumar->a[j]);

}
