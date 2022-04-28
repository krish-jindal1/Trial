#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("PID of program2.c = %d\n", getpid());
  
    printf("Calling ex.c from first process\n");
    char *args[] = {"Operating","System", NULL};
    execv("./ex", args);
    printf("This statement will not run\n");
    
    return 0;
}
