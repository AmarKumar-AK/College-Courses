//Implementing double linked list

#include<stdio.h>
#include<stdlib.h>

struct dllist
{
struct dllist *prev;//denotes pointer previous to current pointer
int song;
struct dllist *next;//denotes pointer next to current pointer
};

struct dllist *hptr=NULL;//creating a head pointer

void insert();//prototype
void delete();//prototype
void play();//prototype
void print();//prototype

int main()
{
	
	int a;//selecting the choice
	while(1)
	{
		printf("..................\n");
		printf("enter the choice\n1.insert an audio\n2.delete an audio\n3.play the audio\n4.Show all songs\n5.exit playing\n");
		scanf("%d",&a);
		printf("..................\n");
		
		switch(a)
		{
			case 1:insert(); break;
			case 2:delete(); break;
			case 3:play(); break;
			case 4:print(); break;
			case 5: exit(0);
		}//switch ends
	}//while ends
}//main function ends

void insert()
{
	int name;
	struct dllist *temp=malloc(sizeof(struct dllist));//creating a node for dllist
	//NOTE:-insertion is being done just after the head pointer
	printf("enter the song name in integer to insert :  ");
	scanf("%d",&name);
	temp->song=name;
	temp->next=hptr;
	temp->prev=NULL;
	hptr=temp;
	
	if(temp->next!=NULL)
	(temp->next)->prev=temp;
}//insert ends


void delete()
{
	int del;//to select which song to delete
	if(hptr==NULL)
	{
		printf("No songs to delete\n");
		printf("..................\n");
	}//if ends
	else 
	{
		struct dllist *temp=hptr;
		printf("enter the name of song to delete :  ");
		scanf("%d",&del);
		
		while(temp!=NULL)
		{
			
			if(temp->song ==del)
			{
					//if only one song is present in the list
					//to delete first song
					if(temp->prev==NULL && temp->next==NULL)   
					{
						hptr=NULL;
						printf("deleted successfully\n");
						printf("..................\n");
					}//inner if ends
			
					//if more than one song is available
					//to delete first song
					else if(temp->prev==NULL && temp->next!=NULL)
					{
						hptr=temp->next;
						(temp->next)->prev=NULL;
						printf("deleted successfully\n");
						printf("..................\n");
					}//else if ends
					
					//to delete the last song
					else if (temp->next==NULL)			
					{
						(temp->prev)->next=NULL;
						temp->prev=NULL;
						printf("deleted successfully\n");
						printf("..................\n");
					}//else if ends
					
					//deleting middle song(not first and not last)
					else  
					{
						(temp->prev)->next=temp->next;
						(temp->next)->prev=temp->prev;
						printf("deleted successfully\n");
						printf("..................\n");
					}//else ends
					break;
	
			}//if ends
			else
				temp=temp->next;				
		}//while ends	
		if(temp==NULL)
		{
			printf("Song not found\n");
			printf("..................\n");
		}//if ends
	}//outer else ends
}//delete ends


void play()
{
	int sname;//song name you want to play
	struct dllist *temp=hptr;
	if(hptr==NULL)
	{
		printf("No songs to play\n");
		
		main();
	}//if ends
	else
	{
		
		printf("enter the song name you want to play :  ");
		scanf("%d",&sname);
		
		int count=0;
		while(temp!=NULL)
		{
			if(temp->song==sname)
			{
				printf("song named %d is playing\n...................\n",sname);
				
				count++;
				break;
			}//if ends
			
			temp=temp->next;
		}//while ends
		if(count==0)
		{
			printf("the entered song is not present\n........................\n");
			play();
		}//if ends
	}//else ends
	int choose;	
	while(1)
		{
			printf("what do you want to do?\n1.play next song\n2.play previous song\n3.choose a different song to play\n4.exit\n");
			scanf("%d",&choose);
			printf("..................\n");
			switch(choose)
			{
				case 1:	if(temp->next!=NULL)
							{ 
								printf("the next song %d is playing\n",(temp->next)->song);
								printf("..................\n");
								temp=temp->next;
							}
							else
							{
								printf("there is no next song\n");
								printf("..................\n");
							}
				break;
				case 2: 	if(temp->prev!=NULL)
							{
								printf("the previous song %d is playing\n",(temp->prev)->song);
								printf("..................\n");
								temp=temp->prev;
							}
							else
							{
								printf("there is no previous song\n");
								printf("..................\n");
							}			
				break;
				case 3: play();
				break;
				case 4: main();
				break;
			}//switch ends
		}//while ends	
}//play ends

void print()
{
	
	if(hptr!=NULL)
	{
		struct dllist *temp=hptr;
		printf("Songs\n");
		 do
		 {
		  printf("--%d",temp->song);
		  temp=temp->next;
		 }while(temp !=NULL);
		 printf("\n...................\n");
	} 
	else
	{ 
		printf("No songs in the list\n");
		printf("..................\n");
	}
}//print ends

