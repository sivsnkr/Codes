#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	int fd[2];
	pipe(fd);
	pid_t p = fork();
	if (p == 0)
	{
		char a[20];
		scanf("%s", a);

		write(fd[1], a, 20);
		char b[20];
		scanf("%s", b);
		write(fd[1], b, 20);
	}
	else
	{
		char p[20], q[20];
		read(fd[0], p, 20);
		//printf("%s",p);
		read(fd[0], q, 20);

		//printf("%s",q);

		if (strcmp(p, q) == 0)
			printf("Matched!\n");
		else
			printf("not matched!");
	}

	return 0;
}
