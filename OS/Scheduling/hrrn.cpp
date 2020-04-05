#include "../header.h"
using namespace std;

struct element
{
    int size;
    int a_t;
    int c_t;
    int w_t;
    int mainSize;
};

typedef struct element e;

e *sort(e arr[], int size, int runtime)
{
    e *max;
    int minrr = 0;
    int flag = 0;
    int zeroSize = 0;

    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i].a_t <= runtime && arr[i].size != 0)
        {
            int rr = ((runtime - arr[i].a_t) + arr[i].size) / arr[i].size;
            if (rr > minrr)
            {
                flag = 1;
                minrr = rr;
                max = &arr[i];
            }
        }
        if (arr[i].size == 0)
        {
            zeroSize++;
        }
    }

    if (zeroSize == size)
    {
        return &arr[0];
    }
    if (flag == 0)
    {
        return NULL;
    }
    return max;
}

void reduceSize(e &element, int rt)
{
    element.size = 0;
    if (element.size == 0)
    {
        element.c_t = rt;
    }
}

void handleRunTime(int &rt, int add)
{
    rt += add;
}

int main()
{
    int size;
    cin >> size;
    e arr[size];
    int i;

    for (i = 0; i < size; i++)
    {
        cin >> arr[i].a_t;
        cin >> arr[i].size;
        arr[i].mainSize = arr[i].size;
    }

    int runtime = 0;

    while (1)
    {
        e *addrs = sort(arr, size, runtime);
        if (addrs == NULL)
        {
            handleRunTime(runtime, 1);
        }
        else
        {
            if (addrs->size <= 0)
            {
                break;
            }
            handleRunTime(runtime, addrs->size);
            reduceSize(*addrs, runtime);
        }
    }

    cout << "---------------" << endl;

    int sum = 0;
    cout << "CT"
         << "\t"
         << "AT"
         << "\t"
         << "Size" << endl;
    for (i = 0; i < size; i++)
    {
        cout << arr[i].c_t << "\t" << arr[i].a_t << "\t" << arr[i].mainSize << endl;
        sum += (arr[i].c_t - arr[i].a_t - arr[i].mainSize);
    }
    cout << "---------------" << endl;
    cout << "Average WT: ";
    cout << sum / size << endl;
}