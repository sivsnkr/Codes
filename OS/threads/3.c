#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct arr
{
    int arr[100];
    int size;
};

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void Merge(int *a, int low, int high, int mid)
{
    int i, j, k, temp[high - low + 1];
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

void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, high, mid);
    }
}

void mergeSort(int arr[], int size)
{
    MergeSort(arr, 0, size - 1);
}

void *median(void *p)
{
    struct arr *arr = malloc(sizeof(struct arr));
    arr = (struct arr *)p;
    int n = arr->size;
    int i;
    int array[n];
    for (i = 0; i < n; i++)
    {
        array[i] = arr->arr[i];
    }

    mergeSort(array, n);
    printf("Sorted with Merge Sort: ");
    printArray(array, n);
    return NULL;
}

void *mode(void *p)
{
    struct arr *arr = malloc(sizeof(struct arr));
    arr = (struct arr *)p;
    int n = arr->size;
    int i;
    int array[n];
    for (i = 0; i < n; i++)
    {
        array[i] = arr->arr[i];
    }

    quickSort(array, 0, n - 1);
    printf("Sorted with Quick Sort: ");
    printArray(array, n);
    return NULL;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct arr *params = malloc(sizeof(struct arr));
    for (i = 0; i < n; i++)
    {
        params->arr[i] = arr[i];
    }
    params->size = n;
    pthread_t pid_1;
    pthread_t pid_2;
    pthread_create(&pid_1, NULL, mode, (void *)params);
    pthread_create(&pid_2, NULL, median, (void *)params);
    pthread_join(pid_1, NULL);
    pthread_join(pid_2, NULL);
    //pthread_exit(0);
}
