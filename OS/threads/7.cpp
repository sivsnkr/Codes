// CPP Program to implement merge sort using
// multi-threading
#include <iostream>
#include <pthread.h>
#include <time.h>
#define THREAD_MAX 4

using namespace std;

struct arr
{
    int *a;
    int part;
};

void merge(int low, int mid, int high, int *a)
{
    int *left = new int[mid - low + 1];
    int *right = new int[high - mid];

    int n1 = mid - low + 1, n2 = high - mid, i, j;

    for (i = 0; i < n1; i++)
        left[i] = a[i + low];

    for (i = 0; i < n2; i++)
        right[i] = a[i + mid + 1];

    int k = low;
    i = j = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1)
    {
        a[k++] = left[i++];
    }

    while (j < n2)
    {
        a[k++] = right[j++];
    }
}

void merge_sort(int low, int high, int *a)
{
    int mid = low + (high - low) / 2;
    if (low < high)
    {

        merge_sort(low, mid, a);

        merge_sort(mid + 1, high, a);

        merge(low, mid, high, a);
    }
}

void *merge_sort(void *arg)
{
    struct arr *ptr = (struct arr *)arg;

    int thread_part = ptr->part;
    int low = thread_part * (8 / 4);
    int high = (thread_part + 1) * (8 / 4) - 1;

    int mid = low + (high - low) / 2;
    if (low < high)
    {
        merge_sort(low, mid, ptr->a);
        merge_sort(mid + 1, high, ptr->a);
        merge(low, mid, high, ptr->a);
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    //printf("Enter the size of array: ");
    int n = 8;
    //cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;

    clock_t t1, t2;

    t1 = clock();
    pthread_t threads[THREAD_MAX];
    for (int i = 0; i < THREAD_MAX; i++)
    {
        struct arr *ele = new struct arr();
        ele->a = a;
        ele->part = i;
        pthread_create(&threads[i], NULL, merge_sort, (void *)ele);
    }
    for (int i = 0; i < THREAD_MAX; i++)
        pthread_join(threads[i], NULL);

    merge(0, (8 / 2 - 1) / 2, 8 / 2 - 1, a);
    merge(8 / 2, 8 / 2 + (8 - 1 - 8 / 2) / 2, 8 - 1, a);
    merge(0, (8 - 1) / 2, 8 - 1, a);

    t2 = clock();

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    // time taken by merge sort in seconds
    cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;

    return 0;
}
