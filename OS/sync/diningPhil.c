#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>

// #define THINKING 2
// #define hungry 1
// #define EATING 0

int state[5];
int phil[5] = { 0, 1, 2, 3, 4 };

sem_t lock;
sem_t S[5];



void test(int phnum)
{
if (state[phnum] == 1 && state[(phnum+4)%5] != 0 && state[(phnum+1)%5] != 0)
    {
// state that eating
state[phnum] = 0;

sleep(2);

printf("Philosopher %d takes fork %d and %d\n",phnum + 1, (phnum+4)%5 + 1, phnum + 1);

printf("Philosopher %d is Eating\n", phnum + 1);

// sem_post(&S[phnum]) has no effect
// during takefork
// used to wake up hungry philosophers
// during putfork
sem_post(&S[phnum]);
}
}

// take up chopsticks
void take_fork(int phnum)
{

sem_wait(&lock);

// state that hungry
state[phnum] = 1;

printf("Philosopher %d is Hungry\n", phnum + 1);

// eat if neighbours are not eating
test(phnum);

sem_post(&lock);

// if unable to eat wait to be signalled
sem_wait(&S[phnum]);

sleep(1);
}

// put down chopsticks
void put_fork(int phnum)
{

sem_wait(&lock);

// state that thinking
state[phnum] = 2;

printf("Philosopher %d putting fork %d and %d down\n",phnum + 1, (phnum+4)%5 + 1, phnum + 1);
printf("Philosopher %d is thinking\n", phnum + 1);

test((phnum+4)%5);
test((phnum+1)%5);

sem_post(&lock);
}

void* philosopher(void* num)
{

while (1) {

int* i = num;

sleep(1);

take_fork(*i);

sleep(0);

put_fork(*i);
}
}

int main()
{

int i;
pthread_t thread_id[5];

// initialize the semaphores
sem_init(&lock, 0, 1);

for (i = 0; i < 5; i++)
    {
        sem_init(&S[i], 0, 0);
    }

for (i = 0; i < 5; i++)
    {

// create philosopher processes
pthread_create(&thread_id[i], NULL,philosopher, &phil[i]);

printf("Philosopher %d is thinking\n", i + 1);
}

for (i = 0; i < 5; i++)
    {
        pthread_join(thread_id[i], NULL);
    }
}