#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int pid = fork();

    if (pid < 0)
    {
        printf("Fork break, Looks like noodle is very strong");
    }
    else if (pid == 0)
    {
        for (int i = 0; i <= 10; i += 2)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= 10; i += 2)
        {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}