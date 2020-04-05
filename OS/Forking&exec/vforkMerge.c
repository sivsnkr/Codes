#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void Merge(long int *a, int low, int high, int mid)
{
    long int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
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
int lpid, pid;
void MergeSort(long int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        pid = vfork();

        if (pid == 0)
        {
            MergeSort(a, mid + 1, high);
            exit(0);
        }
        else if (pid > 0)
        {
            wait(NULL);
            MergeSort(a, low, mid);
        }
        Merge(a, low, high, mid);
    }
}

void sort(long int arr[], int size)
{
    MergeSort(arr, 0, size - 1);
}

int main(void)
{
    long int arr[8] = {4, 3, 1, 10, 3, 7, 8, 9};
    sort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%ld ", arr[i]);
    }
    printf("\n");
}