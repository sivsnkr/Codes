#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Fibonacci(int arr[], int n)
{
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

int prime(int n)
{
    int counter = 1;

    if (n == 1)
        return 1;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            counter++;
        }
        if (counter > 2)
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    int pid = fork();

    if (pid < 0)
    {
        printf("Fork break, Looks like noodle is very strong");
    }
    else if (pid == 0)
    {
        printf("10 Fibonacci nos are: ");
        int arr[10];

        Fibonacci(arr, 10);
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Prime Numbers till 10 are: ");
        for (int i = 1; i <= 10; i += 1)
        {
            if (prime(i) == 1)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}