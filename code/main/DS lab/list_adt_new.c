

#include<stdio.h>
struct list
{
	int array[25];
	int lsize;
};

void insert(struct list *ptrl, int pos, int x);//prototype
void delete(struct list *ptrl, int pos);//prototype
void search(struct list *ptrl,int x);//prototype
void print(struct list *xyz);//prototype
void isFull(struct list l);//prototype
void isEmpty(struct list l);//prototype


int main()
{
	struct list l;
	l.lsize=-1;
	
	int a;				//for choosing what to do
	int pos;			//position of the element
	int x;				//element of the array
	int n; 				//position to be deleted
	int c;				//continue
	
	
			
			
			
		while(1)
		{	
				printf("what do you want to do?\n1. Insert\n2. Delete\n3. Search\n4. print\n5. check for empty\n6. check for full\n7. exit\n");
				scanf("%d",&a);
				if(a<1 || a>7)
				printf("invalid input\n\n");
				
				

			switch(a)
			{

				case 1: 	printf("enter the postion and element of the array\n");
							scanf("%d %d",&pos,&x);				//entering the position and element

							if(pos>=0 && pos<=l.lsize+1)
							insert(&l,pos,x);						//inserting the number in the array at a certain position
															
							else
							printf("invalid input\n\n");		
				break;//case 1 break


				case 2: 	printf("enter the postion which you want to delete\n");
							scanf("%d",&n);		//taking the value of position to be deleted

							if(l.lsize==-1)
							{							//prints if deletion is not possible
								printf("Delete is not possible\n\n");
								break;				
							}
							
							delete(&l,n);				
				break;//case 2 break


				case 3: printf("enter the number you want to search\n");
						scanf("%d",&x);			//elements to be searched
						search(&l,x);	
				break;//case 3 break


				case 4: print(&l);				//for printing the list
				break;//case 4 break


				case 5: isEmpty(l);				//checks whether the array is empty or not after inserting the number in the array
				break;//case 5 break


				case 6: isFull(l);				//checks whether the array is full or not before entering the element
				break;//case 6 break
				
				case 7: return 0;
				
			
					
			}//switching ends	
			
		}//while ends
		
}//main function ends


void isEmpty(struct list l)
{
	if(l.lsize==-1)
	printf("\nthe array is empty\n\n");
	else
	printf("\nthe array is not empty\n\n");
}//isEmpty function ends


void isFull(struct list l)
{
	if(l.lsize==25)
	printf("\nthe array is full\n\n");
	else
	printf("\nthe array is not full\n\n");
}//isFull function ends


void insert(struct list *ptrl, int pos, int x)
{
	int i;
	for(i=ptrl->lsize; i>=pos; i--)
	ptrl->array[i+1]=ptrl->array[i];
	ptrl->array[pos]=x;
	ptrl->lsize++;
}//insert function ends



void delete(struct list *ptrl, int pos)
{
	int i,x=ptrl->array[pos];
	for(i=pos+1; i<ptrl->lsize;i++)
	ptrl->array[i-1]=ptrl->array[i];
	ptrl->lsize--;
	printf("Deleted number is %d\n\n",x);
	
}//delete function ends


void print(struct list *xyz)
{
	if(xyz->lsize==-1)
	{
		printf("there is nothing to print\n\n");
	}
	else
	{
		int i;
		printf("Final data is\n");
		for(i=0;i<=xyz->lsize;i++)
		printf("%d\n",xyz->array[i]);
	}
}//print function ends


void search(struct list *ptrl,int x)
{
	int i,counter=0;
	for(i=0;i<=ptrl->lsize;i++)
			if(ptrl->array[i]==x)
			{
				counter++;	
				printf("the position of the entered number is %dth\n",i);		
				break;
			}//if ends
		if(counter==0)
		printf("the entered number is not present\n\n");
				
}//search function ends


