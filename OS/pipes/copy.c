#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

#define N 20
int main()
{
	int fd[2];
	pipe(fd);
	pid_t p=fork();

	if(p==0)
	{
		char a[N] ="hello";
		close(fd[0]);
		write(fd[1],a,strlen(a)+1);
		close(fd[1]);

	}
	else
	{
		char b[N] ;
		close(fd[1]);
		int nb = read(fd[0],b,strlen(b)+1);
		close(fd[0]);
		int i=0;
		while(nb>=0)
		{
			printf("%c",b[i++]);
			nb--;
		}
	}


	return 0;
}

