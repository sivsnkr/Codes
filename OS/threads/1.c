#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *checkPrime(void *args)
{
    int *n = (int *)args;
    int counter = 0;
    int flag = 1;
    for (int i = 1; i <= *n; i++)
    {
        if (*n % i == 0)
        {
            counter++;
        }
        if (counter > 2)
        {
            flag = 0;
        }
    }
    if (flag == 1)
        printf("%d ", *n);
    return NULL;
}

void generatePrime(int value)
{
    pthread_t pid[value + 1];
    int k = value;
    int a[value + 1];
    for (int i = 0; i <= value; i++)
    {
        a[i] = i;
    }
    while (value > 1)
    {
        pthread_create(&pid[value], NULL, checkPrime, (void *)&a[value]);
        value--;
    }

    for (int i = 0; i <= k; i++)
    {
        pthread_join(pid[i], NULL);
    }
    printf("\n");
}

int main(int n, char *c[])
{
    printf("vl: %d, %s\n", n, c[0]);
    //int value = atoi(c[1]);
    //generatePrime(value);
}