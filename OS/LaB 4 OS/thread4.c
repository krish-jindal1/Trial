#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define MAX 4


int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];


void* assign1(NULL){
	for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matA[i][j] = abs(i-j);
        }
    }
    pthread_exit(NULL);
}
void* assign2(void* arg){
	for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matB[i][j] = i+j;
        }
    }
    pthread_exit(NULL);
}
void* multi(NULL)
{
	sleep(2);
   for(int i=0;i<MAX;i++)
    for (int j = 0; j < MAX; j++)
      for (int k = 0; k < MAX; k++)
        matC[i][j] += matA[i][k] * matB[k][j];
    pthread_exit(NULL);
}

void* print(NULL){
	sleep(4);
	printf("\nMultiplication of A and B\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            printf("%d ",matC[i][j] ) ;       
       printf("\n");
    }
    pthread_exit(NULL);
}
 
 int main(){
 	pthread_t thread1,thread2,thread3,thread4;

 	pthread_create(&thread1,NULL,assign1,NULL);
 	pthread_create(&thread2,NULL,assign2,NULL);
 	pthread_create(&thread3,NULL,multi,NULL);
 	pthread_create(&thread4,NULL,print,NULL);

 	pthread_join(thread1,NULL);
 	pthread_join(thread2,NULL);
 	pthread_join(thread3,NULL);
 	pthread_join(thread4,NULL);
 	return 0;

 }



