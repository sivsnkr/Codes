#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    fd[1] << "Hello";
    char revStr[100];
    read(p[0], revStr, 100);
    printf("%s\n", revStr);

    // if (pid == 0)
    // {
    //     dup2(fd[1], 1);
    //     close(fd[0]);
    //     execlp("ls", "ls", NULL);
    //     close(fd[1]);
    // }
    // else
    // {
    //     dup2(fd[0], 0);
    //     close(fd[1]);
    //     execlp("wc", "wc", "-l", NULL);
    // }
}
