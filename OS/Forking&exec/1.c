#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Execvp()
{
    char *b[] = {"ls", NULL};
    execvp("ls", b);
}

void Execlp()
{
    execlp("pwd", "pwd", NULL);
}

int main(void)
{
    printf("1. Execvp\n2. Execlp\n");
    int choice;
    printf("Which Function you want to run: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Execvp();
        break;
    case 2:
        Execlp();
    default:
        break;
    }
    printf("I won't print you\n");

    return 0;
}