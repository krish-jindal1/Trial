#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> 
 
int main(int argc, char *argv[])
{
    printf("pid:%d\n", getpid());
    pid_t rc = fork();
    int status;
    if (rc == 0)
    {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", getpid());
        sleep(1);
    }
    else
    {
        pid_t wc = waitpid(rc, &status, WUNTRACED);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",rc, wc, getpid());
    }
    return 0;
}