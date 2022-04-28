#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int flag[2];
int turn,count=0;
const int MAX = 1e4;
void lock_init()
{
    flag[0] = flag[1] = 0;
    turn = 0;
}

void lock(int current)
{
    flag[current] = 1;
    turn = 1-current;
    while (flag[1-current]==1 && turn==1-current) ;
}

void unlock(int current)
{
    flag[current] = 0;
}

void *process(void *s)
{
    int i = 0;
    int current;
    // int *x=s;
    current = *((int*)s);
    printf("Process : %d\n", current);

    lock(current);
    for (i=0; i<MAX; i++)
        count++;
    printf("%d\n",count);
        unlock(current);
    // pthread_exit(NULL);
}



void main(){
	printf("Peterson Algorithm\n");
	pthread_t p1,p2;
	  count = 0;
   
    lock_init();
    int i=0;
    pthread_create(&p1, NULL, process, (void*)&i);
    int j=1;
    pthread_create(&p2, NULL, process, (void*)&j);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Actual Count: %d | Expected Count: %d\n",count, MAX*2);
}