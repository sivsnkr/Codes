#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void swap(char *char1, char *char2)
{
    char temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}

int main(void)
{
    int p[2], pid;
    if (pipe(p) < 0)
        exit(0);
    if (pid < 0)
        exit(0);

    printf("Enter the string: ");
    char str[100];
    scanf("%s", str);
    pid = fork();

    if (pid == 0)
    {
        // do child stuff
        close(p[1]);
        char str[100];
        char revStr[100];
        read(p[0], str, 100);
        read(p[0], revStr, 100);
        int i = 0, flag = 0;
        while (i < strlen(str))
        {
            if (str[i] != revStr[i])
            {
                flag = 1;
                break;
            }
            i++;
        }

        if (flag == 1)
            printf("String is not plaindrome\n");
        else
            printf("String is plaindrome\n");
    }
    else if (pid > 0)
    {
        // do parent stuff
        //reverse the string
        int i = 0, j = strlen(str) - 1;
        write(p[1], str, 100);
        while (i <= j)
        {
            swap(&str[i], &str[j]);
            i++;
            j--;
        }
        write(p[1], str, 100);
        printf("Reversed String: %s\n", str);
        close(p[1]);
        wait(NULL);
    }

    return 0;
}