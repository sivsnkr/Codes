#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t child_pid = fork();

    if (child_pid > 0)
    {
        sleep(5);
        printf("Parent End\n");
    }

    else if (child_pid == 0)
    {
        printf("Child Process\n");
        exit(0);
    }

    return 0;
}