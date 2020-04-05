#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Merge(long int *a, int low, int high, int mid, int desc)
{
    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (desc == 0 && a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else if (desc == 1 && a[i] > a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void MergeSort(long int *a, int low, int high, int desc)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(a, low, mid, desc);
        MergeSort(a, mid + 1, high, desc);
        Merge(a, low, high, mid, desc);
    }
}

void sort(long int arr[], int size, int desc)
{
    MergeSort(arr, 0, size - 1, desc);
}

int main(void)
{
    long int arr[10] = {9, 8, 1, 10, 3, 7, 2, 1, 10, 5};
    int pid = fork();

    if (pid < 0)
    {
        printf("Fork break, Looks like noodle is very strong");
    }
    else if (pid == 0)
    {
        printf("Array is desc order: ");
        sort(arr, 10, 1);
        for (int i = 0; i < 10; i++)
        {
            printf("%ld ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Array is asc order: ");
        sort(arr, 10, 0);
        for (int i = 0; i < 10; i++)
        {
            printf("%ld ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}