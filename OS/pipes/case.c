#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define N 20

void toUpper(char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			//printf(".%c",a[i]);
			int k = a[i] - 32;
			a[i] = k;
			//printf("..%c",a[i]);
		}
	}
}

int main()
{
	int fd[2];
	pipe(fd);
	pid_t p = fork();

	if (p == 0)
	{
		char a[N];
		scanf("%[^\n]%*c", a);
		close(fd[0]);
		write(fd[1], a, N);
		close(fd[1]);
	}
	else
	{
		char b[N];
		char c[N] = {0};
		close(fd[1]);
		int nb, i = 0;
		read(fd[0], b, N);
		//printf("%s",b);

		toUpper(b);

		printf("%s\n", b);
	}

	return 0;
}
