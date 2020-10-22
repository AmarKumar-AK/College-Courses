#include<stdio.h>
#include<stdlib.h>

struct arithmatic
{
    int data;
    struct arithmatic *next;
}ar;

struct arithmatic *headA=NULL;
struct arithmatic *headB=NULL;
struct arithmatic *add=NULL;

void insertA()
{
    char data;
    int change;
    printf("enter value of A, press any character and hit 'enter' to stop\n");
    while(1)
    {
        scanf(" %c",&data);
        change=data-48;      
        if(change>=0 && change<=9)
        {
            struct arithmatic *temp=malloc(sizeof(struct arithmatic));
            temp->data=change;
            temp->next=headA;
            headA=temp;
        }//end if
        else break;
    }//end while
    /*struct arithmatic *tmp=headA;
    while(tmp!=NULL)
    {
        printf("-->%d",tmp->data);
        tmp=tmp->next;
    }//end while*/
}//end insertA function

void insertB()
{
     char data;
    int change;
    printf("enter value of B, press any character and hit 'enter' to stop\n");
    while(1)
    {
        scanf(" %c",&data);
        change=data-48;      
        if(change>=0 && change<=9)
        {
            struct arithmatic *temp=malloc(sizeof(struct arithmatic));
            temp->data=change;
            temp->next=headB;
            headB=temp;
        }//end if
        else break;
    }//end while
    /*struct arithmatic *tmp=headB;
    while(tmp!=NULL)
    {
        printf("-->%d",tmp->data);
        tmp=tmp->next;
    }//end while*/
}//end insertB function

void incrementA()
{
    struct arithmatic *tempA=headA;
    
    while(tempA!=NULL)
    {
        if(tempA->data<9)
        {
            tempA->data++;
            break;
        }
        else if(tempA->data>=9)
        {
            tempA->data=0;
        }
        if(tempA->data==0 && tempA->next==NULL)
        {
            //printf("\nhello\n");
            struct arithmatic *tmpA=malloc(sizeof(struct arithmatic));
            tmpA->data=0;
            tempA->next=tmpA;
        }
        tempA=tempA->next;
    }
    struct arithmatic *printA=headA;
    while(printA!=NULL)
    {
        printf("-->%d",printA->data);
        printA=printA->next;
    }//end while
}//end incrementA

void incrementB()
{
    struct arithmatic *tempB=headB;
    
    while(tempB!=NULL)
    {
        if(tempB->data<9)
        {
            tempB->data++;
            break;
        }
        else if(tempB->data>=9)
        {
            tempB->data=0;
        }
        if(tempB->data==0 && tempB->next==NULL)
        {
            //printf("\nhello\n");
            struct arithmatic *tmpB=malloc(sizeof(struct arithmatic));
            tmpB->data=0;
            tempB->next=tmpB;
        }
        tempB=tempB->next;
    }
    struct arithmatic *printB=headB;
    while(printB!=NULL)
    {
        printf("-->%d",printB->data);
        printB=printB->next;
    }//end while
}//end incrementB

void decrementA()
{
    struct arithmatic *tempA=headA;
    
    while(tempA!=NULL)
    {
        if(tempA->data>0)
        {
            tempA->data--;
            break;
        }
        else if(tempA->data<=0)
        {
            tempA->data=9;
        }
        tempA=tempA->next;
    }
    struct arithmatic *printA=headA;
    while(printA!=NULL)
    {
        printf("-->%d",printA->data);
        printA=printA->next;
    }//end while
}

void decrementB()
{
    struct arithmatic *tempB=headB;
    
    while(tempB!=NULL)
    {
        if(tempB->data>0)
        {
            tempB->data--;
            break;
        }
        else if(tempB->data<=0)
        {
            tempB->data=9;
        }
        
        tempB=tempB->next;
    }
    struct arithmatic *printB=headB;
    while(printB!=NULL)
    {
        printf("-->%d",printB->data);
        printB=printB->next;
    }//end while
}

void sum()
{

}

void difference()
{

}
void main()
{
    int choice;
    while(1)
    {
        printf("\nwhat do you want to do?\n");
        printf("1.insert A\n2.insert B\n3.increment in A\n4.incement in B\n5.decrement in A\n6.decrement in B\n7.find A+B\n8.find A-B\n9.exit\n");
        printf("................\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertA();
            break;
            case 2: insertB();
            break;
            case 3: incrementA();
            break;
            case 4: incrementB();
            break;
            case 5: decrementA();
            break;
            case 6: decrementB();
            break;
            case 7: sum();
            break;
            case 8: difference();
            break;
            case 9: exit(0);
            default : printf("invalid choice\n");
        }
    }
     
}