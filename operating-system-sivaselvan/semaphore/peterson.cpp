#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<time.h>
#define MAX_BUFFER_SIZE 10
using namespace std;

int item_counter=0;
int from_where_data_is_consumed=0;
//turn 0 means producer turn
int turn;
// flag[0] is for producer
bool flag[2]={false};
int produce_at=0;
int buffer[MAX_BUFFER_SIZE];
void *producer(void *param){
    while(1){
        while(item_counter==MAX_BUFFER_SIZE);
        turn=0;
        flag[0]=true;
        while(flag[1] && !turn);
        int produced=buffer[produce_at]=rand()%100;
        printf("producer : %d\n",produced);
        item_counter++;
        produce_at=(produce_at+1)%MAX_BUFFER_SIZE;
        flag[0]=false;
        sleep(rand()%3);
    }
}

void *consumer(void *param){
    while(1){
        while(item_counter==0);
        turn=1;
        flag[1]=true;
        while(flag[0] && turn);
        int consumed=buffer[from_where_data_is_consumed];
        printf("item consumed : %d\n",consumed);
        item_counter--;
        from_where_data_is_consumed=(from_where_data_is_consumed+1)%MAX_BUFFER_SIZE;
        flag[1]=false;
        sleep(rand()%3);
    }
}

int main(){
    srand(time(NULL));
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,producer,NULL);
    pthread_create(&tid[1],NULL,consumer,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}