#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void main()
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        printf("Error while creating pipe\n");
        exit(0);
    }

    int rc1 = fork();
   if (rc1 == 0)
    {
        printf("Entering the first child process, id : %d\n", getpid());
        dup2(fd[1], STDOUT_FILENO);
        printf("----First child process msg-----\n");
    }
    else
    {
        int rc2 = fork();
        if (rc2 < 0)
        {
            printf("Error while creating child process\n");
            exit(0);
        }
        else if (rc2 == 0)
        {
            printf("Entering the second child process, id : %d\n", getpid());
            dup2(fd[0], STDIN_FILENO);
            char msg[100];
            fgets(msg, sizeof(msg), stdin);
            printf("The message inside the second child process: %s", msg);
        }
        else
        {
            wait(NULL);
        }
    }
}        