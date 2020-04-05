#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int p[2], pid, p1[2];
    if (pipe(p) < 0)
        exit(0);
    if (pipe(p1) < 0)
        exit(0);

    pid = fork();

    if (pid < 0)
        exit(0);

    if (pid > 0)
    {
        int choice = 1;
        while (choice)
        {
            char msg[30];
            printf("Enter message for Child: ");
            scanf("%s", msg);
            write(p[1], msg, 30);
            read(p1[0], msg, 30);
            printf("Message from child: %s\n", msg);
            printf("Do you want to continue: ");
            scanf("%d", &choice);
            write(p[1], &choice, sizeof(choice));
        }
        wait(NULL);
    }
    else
    {
        int choice = 1;
        while (choice)
        {
            char msg[30];
            read(p[0], msg, 30);
            printf("Message from parent: %s\n", msg);
            printf("Enter message for parent: ");
            scanf("%s", msg);
            write(p1[1], msg, 30);
            read(p[0], &choice, sizeof(choice));
        }
    }
    return 0;
}