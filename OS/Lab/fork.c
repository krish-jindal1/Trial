#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    int x=100;

    int id=fork();
    if(id==0)
    {
        printf("Process id of child process = %d\n",getpid());
        printf("Value of x is %d/n",x);
        x++;
        printf("Value of x after increment %d/n",x);
    }
    else
    {  
        printf("Process id of parent process = %d\n",getpid());
        x--;
        printf("Value of x after decrement %d/n",x);
    }
    return 0;
}
