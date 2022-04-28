#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define MAX 4


int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];


void* assign1(void* arg){
	for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matA[i][j] = rand() % 10;
        }
    }
}
void* assign2(void* arg){
	for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matB[i][j] = rand() % 10;
        }
    }
}
void* multi(void* arg)
{
    sleep(2);
   for(int i=0;i<MAX;i++)
    for (int j = 0; j < MAX; j++)
      for (int k = 0; k < MAX; k++)
        matC[i][j] += matA[i][k] * matB[k][j];
}

void* print(void* arg){
	sleep(2);
	printf("\nMultiplication of A and B\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            printf("%d ",matC[i][j] ) ;       
       printf("\n");
    }
}
 
 int main(){
 	pthread_t thread[MAX];

 	pthread_create(&thread[0],NULL,assign1,NULL);
 	pthread_create(&thread[1],NULL,assign2,NULL);
 	pthread_create(&thread[2],NULL,multi,NULL);
 	pthread_create(&thread[3],NULL,print,NULL);

 	pthread_join(thread[0],NULL);
 	pthread_join(thread[1],NULL);
 	pthread_join(thread[2],NULL);
 	pthread_join(thread[3],NULL);
 	return 0;

 }



