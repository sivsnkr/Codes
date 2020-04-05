#include "../header.h"
using namespace std;

struct element
{
    int size;
    int a_t;
    int c_t;
    int w_t;
    int priority;
    int mainSize;
};

typedef struct element e;

e *sort(e arr[], int size, int runtime)
{
    e *min = new e;
    min->a_t = 100;
    min->priority = 0;
    int flag = 0;
    int zeroSize = 0;

    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i].a_t <= runtime)
        {
            if (arr[i].priority > min->priority && arr[i].size != 0)
            {
                flag = 1;
                min = &arr[i];
            }
            if (arr[i].size == 0)
            {
                zeroSize++;
            }
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
    return min;
}

void reduceSize(e &element, int rt)
{
    element.size--;
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
        cin >> arr[i].priority;
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
            handleRunTime(runtime, 1);
            reduceSize(*addrs, runtime);
        }
    }

    cout << "Average WT: " << endl;

    int sum = 0;
    cout << "CT"
         << " "
         << "AT"
         << " "
         << "Size"
         << " "
         << "Priority" << endl;
    for (i = 0; i < size; i++)
    {
        cout << arr[i].c_t << " " << arr[i].a_t << " " << arr[i].mainSize << "  " << arr[i].priority << endl;
        sum += (arr[i].c_t - arr[i].a_t - arr[i].mainSize);
    }
    cout << sum / size << endl;
}