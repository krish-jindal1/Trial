#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("PID of program2.c = %d\n", getpid());
    int p = fork();
    if(p==-1)
    {
        printf("Error while calling fork()");
    }
    if(p==0)
    {
    printf("PID of child of program2.c = %d\n", getpid());
    printf("We are in the child process\n");
    printf("Calling ex.c from child process\n");
    char *args[] = {"Operating","System", NULL};
    execv("./ex", args);
    }
    else{
    printf("Parent process\n");
    }
    
    return 0;
}
