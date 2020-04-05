#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
struct element
{
    int *arr;
    int low;
    int heigh;
    int element;
};

int bo = -1;
void *binarySearch(void *argv)
{
    struct element *ptr = (struct element *)argv;
    int min = ptr->low, max = ptr->heigh - 1;
    int mid;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (ptr->arr[mid] == ptr->element)
        {
            bo = mid;
            return NULL;
        }
        else if (ptr->arr[mid] < ptr->element)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return NULL;
}

int main(void)
{
    int arr[13] = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    int i;
    pthread_t tid[4];
    for (i = 0; i < 4; i++)
    {
        struct element *ptr = malloc(sizeof(struct element));
        ptr->arr = arr;
        ptr->heigh = (i + 1) * (13 / 4);
        ptr->low = (i) * (13 / 4);
        ptr->element = 7;
        pthread_create(&tid[i], NULL, binarySearch, (void *)ptr);
    }
    for (i = 0; i < 4; i++)
    {
        pthread_join(tid[i], NULL);
    }
    int counter = 0;
    int allIndex[12] = {0};
    i = bo + 1;
    while (i <= 12)
    {
        if (arr[bo] == arr[i])
        {
            counter++;
        }
        else
        {
            break;
        }
        i++;
    }
    i = bo - 1;
    while (i >= 0)
    {
        if (arr[bo] == arr[i])
        {
            counter++;
        }
        else
        {
            break;
        }
        i--;
    }

    i++;
    counter += i;
    if (bo >= 0)
    {
        printf("Element is present at locations: ");
        for (; i <= counter; i++)
        {
            printf("%d ", i + 1);
        }
    }
    else
    {
        printf("There are no such element in array");
    }
    printf("\n");
}