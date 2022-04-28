#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{

    pid_t pid = vfork(); //child process is created
    if (pid == 0)
    {
        printf("Child process started\n");
       char *args[] = {"Operating","System", NULL};
       
    execv("./ex", args);
    sleep(10);
    exit(1);
    }
    else
    {
    wait(1);
        printf("Back to parent process\n");
    }
    
    return 0;
}
