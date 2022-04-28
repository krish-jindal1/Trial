#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter=0;
pthread_mutex_t lock;

void* update(void* arg)
{
	pthread_mutex_lock(&lock);

	unsigned long i = 0;
	counter += 1;
	printf("Counter value is %d \n", counter);

	sleep(1);

	printf("Job has finished\n\n");

	pthread_mutex_unlock(&lock);

	return NULL;
}

int main(void)
{
	int i = 0;
	int error;

	pthread_mutex_init(&lock, NULL);

	while (i < 2) {
		error = pthread_create(&(tid[i]),
							NULL,
							&update, NULL);
		if (error != 0)
			printf("\nThread can't be created :[%s]",
				strerror(error));
		i++;
	}
        pthread_join(tid[0], NULL);
		pthread_join(tid[0], NULL);
		pthread_join(tid[1], NULL);


	return 0;
}
