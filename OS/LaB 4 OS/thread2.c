#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
void * start_thread (void *message)
{
printf ("%s\n", (const char *) message);
pthread_exit(NULL);
}
int main (void)
{
pthread_t thread1, thread2;
const char *message1 = "Thread 1";
const char *message2 = "Thread 2";

pthread_create (&thread1, NULL, start_thread, (void *) message1);
pthread_create (&thread2, NULL, start_thread, (void *) message2);

pthread_join (thread1, NULL);
pthread_join (thread2, NULL);
return 0;
}