#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int j; //simple counter
    for (j = 0; j < n; j++)
    {
        cin >> arr[n - j - 1];
    }

    int y[n];
    y[n - 1] = -1;
    for (j = n - 2; j >= 0; j--)
    {

        if (arr[j + 1] == arr[j])
        {
            y[j] = y[j + 1];
        }
        else
        {
            int index = j + 1;
            int flag = 0;
            while (1 && index < n)
            {
                if (arr[j] > arr[index])
                {
                    y[j] = arr[index];
                    flag = 1;
                    break;
                }
                if (index == -1)
                {
                    break;
                }
                index = y[index];
            }
            if (flag == 0)
            {
                y[j] = -1;
            }
        }
    }

    int print[n];
    for (j = 0; j < n; j++)
    {
        print[j] = y[j];
    }

    for (j = 0; j < n; j++)
    {
        cout << print[n - j - 1] << " ";
    }
    cout << endl;
}