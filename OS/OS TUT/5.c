#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
{
    printf("This is start of the process\n");
    int rc = fork();
    if (rc == 0) {
    close(STDOUT_FILENO); 
    open("file1.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    printf("I am printing from the child\n");
    
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
    assert(wc >= 0);
    }
    return 0;
}