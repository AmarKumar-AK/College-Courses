#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define INT_MAX 10000

struct node{
    int *a;
    int begs;
    int ends;
};

struct File{
    FILE *fp;
    int data;
};

int partition(int *a,int beg,int end){
    int i = beg;
    int j = end;
    int pivot = a[beg];
    
    while (i <= j){
        while (a[i] <= pivot && i <= end){
            i++;
        }
        while (a[j] > pivot && j > beg){
            j--;
        }
        
        int temp;
        if (i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[beg];
    a[beg] = a[j];
    a[j] = temp;
    
    return j;
}


void *sorting(void *param){
    struct node *nd=param;
    int beg=nd->begs;
    int end=nd->ends;
    
    if (beg < end){
        pthread_t tid1,tid2;
        int p = partition(nd->a, beg, end);

        struct node *nd1=malloc(sizeof(struct node));
        nd1->begs=beg;
        nd1->ends=p-1;
        nd1->a=nd->a;
        pthread_create(&tid1,NULL,sorting,nd1);

        struct node *nd2=malloc(sizeof(struct node));
        nd2->begs=p+1;
        nd2->ends=end;
        nd2->a=nd->a;
        pthread_create(&tid2,NULL,sorting,nd2);

        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
    }
}

int main(int argc, char const *argv[]){
    srand(time(NULL));
    int data,total_element;
    FILE *fp1=fopen("input.txt","w");
    printf("how many data you want to input in a file for external sorting : ");
    scanf("%d",&total_element);
    //creating file having large number of data
    for(int i=0 ; i<total_element ; ++i){
        data=rand()%1000+1;
        fprintf(fp1,"%d ",data);
    }
    fclose(fp1);

    FILE *fp2=fopen("input.txt","r");
    //counter is for file naming
    //count is for counting the number of elements
    int counter=1,count=0;
    char temp[10];
    
    int how_many_in_each_file;
    printf("how many number you want to keep in each file : ");
    scanf("%d",&how_many_in_each_file);
    int a[how_many_in_each_file];

    while(fscanf(fp2,"%d",&data)!=EOF){
        //naming the splitted file
        a[count]=data;
        count++;
        if(count==how_many_in_each_file){
            count=0;
            strcpy(temp,"");
            sprintf(temp,"%d",counter++);
            strcat(temp,".txt");
            // printf("%s\n",temp);

            //sorting
            struct node *nd=malloc(sizeof(struct node));
            nd->begs=0;
            nd->ends=how_many_in_each_file-1;
            nd->a=a;
            pthread_t tid;
            pthread_create(&tid,NULL,sorting,nd);
            pthread_join(tid,NULL);

            //opening each file and writing data in sorted form in each file
            FILE *fp=fopen(temp,"w");
            for(int i=0 ; i<how_many_in_each_file ; ++i){
                fprintf(fp,"%d ",a[i]);
            }
            fclose(fp);
        }
    }
    //cheking if there are remaining elements
    if(floor((double)total_element/how_many_in_each_file)!=ceil((double)total_element/how_many_in_each_file)){
        //naming for remaining elements
        strcpy(temp,"");
        sprintf(temp,"%d",counter);
        strcat(temp,".txt");

        FILE *fp=fopen(temp,"w");
        //sorting remaining elements
        struct node *ndr=malloc(sizeof(struct node));
        ndr->begs=0;
        ndr->ends=total_element-(total_element/how_many_in_each_file)*how_many_in_each_file-1;
        ndr->a=a;
        pthread_t tidr;
        pthread_create(&tidr,NULL,sorting,ndr);
        pthread_join(tidr,NULL);

        for(int i=0 ; i<total_element-(total_element/how_many_in_each_file)*how_many_in_each_file ; ++i){
            fprintf(fp,"%d ",a[i]);
        }
        fclose(fp);
    }
    else{
        counter=counter-1;
    }
    fclose(fp2);
    //open all files and set pointer to the begining of each file
    struct File f[counter];
    for(int i=0 ; i<counter ; ++i){
        strcpy(temp,"");
        sprintf(temp,"%d",i+1);
        strcat(temp,".txt");
        // printf("%s\n",temp);
        f[i].fp=fopen(temp,"r");
        fscanf(f[i].fp,"%d",&data);
        f[i].data=data;
    }
    //counter is giving the value of total number of files created to store data
    FILE *out=fopen("output.txt","w");
    //merging and writing to file
    for(int i=0 ; i<total_element ; ++i){
        int min=INT_MAX, imin=0;
        for(int j=0 ; j<counter ; ++j){
            if(f[j].data<min && f[j].data!=-1){
                min=f[j].data;
                imin=j;
            }
        }
        int read=fscanf(f[imin].fp,"%d",&data);
        fprintf(out,"%d ",min);
        //if min is found then place another element
        f[imin].data=data;
        //indicates that a file read has reached end
        if(read!=1){
            f[imin].data=-1;
        }    
    }
    return 0;
}
