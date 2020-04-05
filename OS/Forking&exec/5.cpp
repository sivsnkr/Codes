#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 109;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    pid_t pid = vfork();
    if (pid == 0)
    {
        //sort0-4
        sort(arr, arr + 5);
        exit(0);
    }
    else
    {
        //sort5-9
        wait(NULL);
        sort(arr + 5, arr + 10, greater<int>());
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}