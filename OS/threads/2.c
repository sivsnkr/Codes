#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct arr
{
    int arr[100];
    int size;
};

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

void sort(int arr[], int size)
{
    MergeSort(arr, 0, size - 1);
}

void *mean(void *p)
{
    struct arr *arr = malloc(sizeof(struct arr));
    arr = (struct arr *)p;
    int n = arr->size;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr->arr[i];
    }
    printf("Mean: %d\n", sum / n);
    return NULL;
}

void *mode(void *p)
{
    struct arr *arr = malloc(sizeof(struct arr));
    arr = (struct arr *)p;
    int n = arr->size;
    int i;
    //find max
    int max = 0;
    for (i = 0; i < n; i++)
    {
        if (max < arr->arr[i])
        {
            max = arr->arr[i];
        }
    }
    int freq[max];
    for (i = 0; i < max; i++)
    {
        freq[i] = 0;
    }

    //store frequency
    for (i = 0; i < n; i++)
    {
        freq[arr->arr[i]]++;
    }

    //find max freq
    int maxFreqCount = 0;
    int maxFreq;

    for (i = 0; i < max; i++)
    {
        if (maxFreqCount < freq[i])
        {
            maxFreq = i;
            maxFreqCount = freq[i];
        }
    }
    printf("Mode: %d\n", maxFreq);
    return NULL;
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

    sort(array, n);
    printf("Median: %d\n", array[n / 2]);
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
    pthread_t pid_0;
    pthread_t pid_1;
    pthread_t pid_2;
    pthread_create(&pid_0, NULL, mean, (void *)params);
    pthread_create(&pid_1, NULL, mode, (void *)params);
    pthread_create(&pid_2, NULL, median, (void *)params);
    pthread_join(pid_0, NULL);
    pthread_join(pid_1, NULL);
    pthread_join(pid_2, NULL);
    for (i = 0; i < n; i++)
    {
        printf("%d ", params->arr[i]);
    }
    printf("\n");
    //pthread_exit(0);
}

//will modify it