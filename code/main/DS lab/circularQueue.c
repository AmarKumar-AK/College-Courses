#include<stdio.h>
struct circularQueue{
    int array[5];
    int front;
    int rear;
};

void enqueue(struct circularQueue *ps, int x);
void dequeue(struct circularQueue *ps);






void main(){
    // Declaration of empty struct
    struct circularQueue s;
    s.front=-1;
    s.rear=-1;
    int checker=1;
    while(checker==1){
        printf("Enter value to be entered in the queue : ");
        int y;
        scanf("%d",&y);
        enqueue(&s, y);
        printf("Do you want to enter again (1 or 0)");
        scanf("%d", &checker);
    }
    
    int dchecker=1;
    while(dchecker==1){
        printf("Do you want to deque(1 or 0) : ");
        int y;
        scanf("%d",&y);
        if(y==1){
        	dequeue(&s);
        }
        printf("Dequeue again (1 or 0)");
        scanf("%d", &dchecker);
    }
    
    checker=1;
    while(checker==1){
        printf("Enter value to be entered in the queue : ");
        int y;
        scanf("%d",&y);
        enqueue(&s,y);
        printf("Do you want to enter again (1 or 0)");
        scanf("%d", &checker);
    }
    
    dchecker=1;
    while(dchecker==1){
        printf("Do you want to deque(1 or 0) : ");
        int y;
        scanf("%d",&y);
        if(y==1){
        		dequeue(&s);
        }
        printf("Dequeue again (1 or 0)");
        scanf("%d", &dchecker);
    }
    
    puts("");
    for(int i=s.front; i!=s.rear; i=(i+1)%5){
    printf("%d ",s.array[i]);
    		int z=(s.front%5) + (s.rear%5);
    		if(z==5){
    		break;
    		}
    }
    puts("");
   
}

void enqueue(struct circularQueue *ps, int x){
    if((ps->rear+1)%5==ps->front){
        printf("\nQueue is full\n");
    }
    else if(ps->front==-1 && ps->rear==-1){
        ps->rear+=1;
        ps->front+=1;
        ps->array[(ps->rear)%5]=x;
        
    }
    else{
    ps->rear+=1;
    ps->array[(ps->rear)%5]=x;
    }
}

void dequeue(struct circularQueue *ps){
    if(ps->rear==-1 && ps->front==-1){
        printf("\nQueue is Empty\n");
    }
    else{
        int x=ps->array[(ps->front)%5];
        ps->front+=1;
        printf("\nThe number dequeued is : %d\n",x);
    }
}

