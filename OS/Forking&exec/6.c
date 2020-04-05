#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char a[100][100] = {'\0'};

    int i;
    int choice = 1;
    i = 0;
    while (choice)
    {
        printf("Enter the command: ");
        char *arg[2] = {NULL, NULL};
        char b[10];
        scanf("%s", b);
        arg[0] = b;

        int pid = fork();
        if (pid == 0)
        {
            execvp(arg[0], arg);
            exit(0);
        }
        else if (pid > 0)
            wait(NULL);
        strcpy(a[i], b);
        i++;
        printf("want to continue: ");
        scanf("%d", &choice);
    }

    printf("Enter the number of history you want: ");
    int history;
    scanf("%d", &history);
    int count = abs(i - (history - 1));
    int c = history;
    i = 0;
    while (count >= 0 && c >= 0)
    {
        if (strlen(a[count]) > 0)
            printf("%s ", a[count]);
        count--;
        c--;
    }
    printf("\n");
}