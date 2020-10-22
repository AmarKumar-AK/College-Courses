//estimating pi value
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

int number_of_points;
int circle_point_count=0;
struct rndm{
    double x;
    double y;
};

void *estimatePi(void *par){
    struct rndm *r=(struct rndm *)par;
    double area=(r->x)*(r->x) + (r->y)*(r->y);
        // printf("%lf ",area);
        if(area<=1){
            circle_point_count++;
            // printf("hello\n");
        }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    printf("enter the number of points : ");
    scanf("%d",&number_of_points);
    struct rndm rd;
    pthread_t tid[number_of_points];
    for(int i=0 ; i<number_of_points ; ++i){
        rd.x=rand()/(double)RAND_MAX;
        rd.y=rand()/(double)RAND_MAX;
        pthread_create(&tid[i],NULL,(void*)estimatePi,(void*)&rd);
    }
    for(int i=0 ; i<number_of_points ; ++i){
        pthread_join(tid[i],NULL);    
    }
    double pi=((double)circle_point_count/(double)number_of_points)*4;
    printf("pi : %lf\n",pi);
    return 0;
}
