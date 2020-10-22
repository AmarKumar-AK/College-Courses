#include <stdio.h>
#include <stdlib.h>

struct setOperation
{
    int data;
    struct setOperation *next;
} s;

struct setOperation *headA = NULL;
struct setOperation *headB = NULL;
struct setOperation *store = NULL; //to store universal set to find the complement

void A(struct setOperation *s)
{
    printf("enter the data in set A, enter -666 to stop\n");
    while (1)
    {
        struct setOperation *temp = malloc(sizeof(struct setOperation));
        printf("enter data:  ");
        scanf("%d", &temp->data);
        if (temp->data == -666)
            break;
        temp->next = headA;
        headA = temp;
    } //end while
} //end A

void B(struct setOperation *s)
{

    printf("enter the data in set B, enter -666 to stop\n");
    while (1)
    {
        struct setOperation *temp = malloc(sizeof(struct setOperation));
        printf("enter data:  ");
        scanf("%d", &temp->data);
        if (temp->data == -666)
            break;
        temp->next = headB;
        headB = temp;
    } //end while
} //end B

void Union(struct setOperation s)
{
    struct setOperation *tmp1 = headA;
    printf("the union of setA and setB is :\n");
    while (tmp1 != NULL)
    {
        printf("-->%d", tmp1->data);
        tmp1 = tmp1->next;
    } //end while

    struct setOperation *tmp2 = headB;
    while (tmp2 != NULL)
    {
        int counter = 0;
        struct setOperation *tmp = headA;
        while (tmp != NULL)
        {
            if (tmp2->data == tmp->data)
            {
                counter++;
                break;
            } //end if

            tmp = tmp->next;

        } //end inner while
        if (counter == 0)
            printf("-->%d", tmp2->data);
        tmp2 = tmp2->next;
    } //end outer while
} //end union

void intersection(struct setOperation s)
{
    //printf("helloworld");
    struct setOperation *tmp2 = headB;
    while (tmp2 != NULL)
    {
        int counter = 0;
        struct setOperation *tmp = headA;
        while (tmp != NULL)
        {
            if (tmp2->data == tmp->data)
            {
                counter++;
                break;
            } //end if

            tmp = tmp->next;

        } //end while
        if (counter > 0)
        {
            printf("-->%d", tmp2->data);
        }//end if
        tmp2 = tmp2->next;
    } //end while
} //end intersection

void complement(struct setOperation s)
{
    printf("enter the data in universal set, enter -666 to stop\n");
    while (1)
    {
        struct setOperation *temp = malloc(sizeof(struct setOperation));
        printf("enter data:  ");
        scanf("%d", &temp->data);
        if (temp->data == -666)
            break;
        temp->next = store;
        store = temp;
    } //end while

    int choice;
    printf("enter \"1\" to find complement of setA and \"2\" to find the complement of setB : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        struct setOperation *tmp4 = store;
        while (tmp4 != NULL)
        {
            int counter = 0;
            struct setOperation *tmp3 = headA;
            while (tmp3 != NULL)
            {
                if (tmp4->data == tmp3->data)
                {
                    counter++;
                    break;
                } //end if
                tmp3 = tmp3->next;
            } //end while
            if (counter == 0)
            {
                printf("-->%d", tmp4->data);
            }//end if
            tmp4 = tmp4->next;

        } //end outer while
    }
    else if (choice == 2)
    {
        struct setOperation *tmp5 = store;
        while (tmp5 != NULL)
        {
            int counter = 0;
            struct setOperation *tmp6 = headB;
            while (tmp6 != NULL)
            {
                if (tmp6->data == tmp5->data)
                {
                    counter++;
                    break;
                }//end if
                tmp6 = tmp6->next;
            }//end inner while
            if (counter == 0)
            {
                printf("-->%d", tmp5->data);
            }//end if
            tmp5 = tmp5->next;
        }//end outer while
    }//end else if
}//end complement function

//here uneversal set is A union B
/*void complement(struct setOperation s)
{
    int choice;
    printf("enter \"1\" to find complement of setA and \"2\" to find the complement of setB : ");
    scanf("%d", &choice);

    struct setOperation *tmp2 = headB;
    while (tmp2 != NULL)
    {
        int counter = 0;
        struct setOperation *tmp = headA;
        struct setOperation *temp = malloc(sizeof(struct setOperation));
        while (tmp != NULL)
        {
            if (tmp2->data == tmp->data)
            {
                counter++;
                break;
            } //end if

            tmp = tmp->next;

        } //end while
        if (counter > 0)
        {

            temp->data = tmp2->data;
            temp->next = store;
            store = temp;
        }
        tmp2 = tmp2->next;
    } //end while

    if (choice == 1)
    {
        struct setOperation *tmp4 = headB;
        while (tmp4 != NULL)
        {
            int counter = 0;
            struct setOperation *tmp3 = store;
            while (tmp3 != NULL)
            {
                if (tmp4->data == tmp3->data)
                {
                    counter++;
                    break;
                } //end if
                tmp3 = tmp3->next;
            } //end while
            if (counter == 0)
            {
                printf("-->%d", tmp4->data);
            }
            tmp4 = tmp4->next;

        } //end outer while
    }     //end if
    else if (choice == 2)
    {
        struct setOperation *tmp5 = headA;
        while (tmp5 != NULL)
        {
            int counter = 0;
            struct setOperation *tmp6 = store;
            while (tmp6 != NULL)
            {
                if (tmp6->data == tmp5->data)
                {
                    counter++;
                    break;
                }
                tmp6 = tmp6->next;
            }
            if (counter == 0)
            {
                printf("-->%d", tmp5->data);
            }
            tmp5 = tmp5->next;
        }//end while
    } //end else if
} //complement
*/

void main()
{
    int choice;

    while (1)
    {
        printf("\nenter your choice\n1.add elements in set A\n2.add elements in set B\n3.find union\n4.find intersection\n5.find complement\n6.exit\n...................\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                A(&s);
                break;
            case 2:
                B(&s);
                break;
            case 3:
                Union(s);
                break;
            case 4:
                intersection(s);
                break;
            case 5:
                complement(s);
                break;
            case 6:
                exit(0);
        } //end switch
    }     //end while
} //end main
