#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{

    int id=fork();
    if(id)
    {
        printf("Process id of Parent process = %d\n",getpid());
        
    }
    else
    {
    wait();
        printf("Process id of child process = %d\n",getpid());
        printf("Process id of parent process = %d\n",getppid());
    }
    return 0;
}
