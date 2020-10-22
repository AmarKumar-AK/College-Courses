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

void *merge(void *param){
    struct node *nd=param;
    int beg=nd->begs, end=nd->ends;
    int *a=nd->a;
    int mid=(beg+end)/2, i=beg, j=mid+1;
    int b[100], k=0;
    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=end){
        b[k++]=a[j++];
    }
    int p=0;
    for(int x=beg ; x<=end ; ++x){
        a[x]=b[p++];
    }
}

void *mergesort(void *param){
    struct node *nd=param;
    int beg=nd->begs;
    int end=nd->ends;
    int *a=nd->a;
    int mid;
    if(beg<end){
        mid=(beg+end)/2;

        struct node *nd1=malloc(sizeof(struct node));
        nd1->begs=beg,nd1->ends=mid,nd1->a=a;
        // mergesort(a,beg,mid);
        pthread_t tid1;
        pthread_create(&tid1,NULL,mergesort,nd1);

        struct node *nd2=malloc(sizeof(struct node));
        nd2->begs=mid+1,nd2->ends=end,nd2->a=a;
        // mergesort(a,mid+1,end);
        pthread_t tid2;
        pthread_create(&tid2,NULL,mergesort,nd2);

        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        // merge(nd->a,nd->begs,nd-end);
        pthread_t tid3;
        pthread_create(&tid3,NULL,merge,nd);
        pthread_join(tid3,NULL);
    }
}
//fp1-contains large number of elements
//
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
            pthread_create(&tid,NULL,mergesort,nd);
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
        printf("%s","yes there is some remaining elements\n");
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
        pthread_create(&tidr,NULL,mergesort,ndr);
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
        printf("%s\n",temp);
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
        if(read!=1){
            f[imin].data=-1;
            fclose(f[imin].fp);
        }    
    }
    return 0;
}
