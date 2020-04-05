#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#define N 20
int main()
{
	int fd[2];
	pipe(fd);

	pid_t p = fork();

	if (p == 0)
	{
		char a[N] = "hello";
		write(fd[1], a, strlen(a) + 1);
	}
	else
	{
		char b[N] = "Shiv";
		char c[N];
		int nb = read(fd[0], c, strlen(c));
		strcat(c, b);
		printf("%s", c);
	}

	return 0;
}
