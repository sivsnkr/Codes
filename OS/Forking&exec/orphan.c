#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t child_pid = fork();

    if (child_pid > 0)
    {
        printf("Parent End\n");
        printf("Pid of parent: %d\n", getpid());
    }

    else if (child_pid == 0)
    {
        sleep(5);
        printf("Child Process");
        printf("Pid of parent: %d\n", getpid());
    }

    return 0;
}