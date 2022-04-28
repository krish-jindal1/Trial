#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int max=0,min=100000;
int list[] = {7,12,4,2};

void * maximum ()
{
  for(int i=0;i<4;i++){
  	if(list[i]>max)
  		max=list[i];
  		printf("nvjf");
  }
pthread_exit(NULL);
}

void * minimum ()
{
 for(int i=0;i<4;i++){
  	if(list[i]<min)
  		min=list[i];
  }
pthread_exit(NULL);
}


int main (void)
{
pthread_t thread1, thread2;

pthread_create (&thread1, NULL, maximum, NULL);
pthread_create (&thread2, NULL, minimum, NULL);

pthread_join (thread1, NULL);
pthread_join (thread2, NULL);
  printf("This is a difference between max and min %d\n",max-min);
return 0;
}
