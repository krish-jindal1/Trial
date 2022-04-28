#include<stdio.h> 
#include<fcntl.h> 
#include<unistd.h>

int main()
{
	int fd1 = open("example.txt", O_RDONLY);
	int fd2= open("new.txt",O_RDWR);
	char msg[20];
	printf("fd1 = %d\n", fd1);
	printf("fd2 = %d\n", fd2);
	if(fd1!=-1){
	int f=read(fd1,&msg,12);
	}
	if(fd2!=-1)
	{
		int sz=write(fd2,&msg,12);
	}
	return 0;
}

