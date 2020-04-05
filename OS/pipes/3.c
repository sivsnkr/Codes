#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXCHAR 1000

int main(void)
{
    int p[2], pid;
    if (pipe(p) < 0)
        exit(0);

    pid = fork();

    FILE *fp;
    char str[MAXCHAR];

    if (pid < 0)
        exit(0);
    if (pid > 0)
    {
        fp = fopen("1.txt", "r");
        if (fp == NULL)
        {
            printf("Failed to open file\n");
            exit(3);
        }
        int noOfLines = 0;
        close(p[0]);
        while (fgets(str, MAXCHAR, fp) != NULL)
        {
            write(p[1], str, MAXCHAR);
            noOfLines++;
        }
        fclose(fp);
        printf("Number of lines: %d\n", noOfLines);
        close(p[1]);
        wait(NULL);
    }
    else if (pid == 0)
    {
        close(p[1]);
        char string[MAXCHAR];
        int i;
        int noOfChar = 0, noOfWord = 0;
        while (read(p[0], string, MAXCHAR) > 0)
        {
            printf("%d\n", rd);
            for (i = 0; i < strlen(string); i++)
            {
                if (string[i] == ' ')
                {
                    noOfWord++;
                }
                else
                {
                    noOfChar++;
                }
            }
            noOfWord++;
        }
        printf("Number of Words: %d\nNumber of Characters: %d\n", noOfWord, noOfChar);
    }

    return 0;
}