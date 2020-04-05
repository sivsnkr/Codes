#include <iostream>
using namespace std;

struct element
{
    long int ai;
    long int di;
    int status;
};

int main()
{
    int n, q;
    cin >> n >> q;
    struct element arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i].ai >> arr[i].di;
        arr[i].status = 3;
    }

    for (i = 0; i < q; i++)
    {
        int t, id;
        int j; //simple counter
        cin >> t >> id;
        id--;
        arr[id].status = t;
        long int firstSoln = abs(arr[id].ai - arr[id].di);
        long int secondSoln = arr[id].ai + arr[id].di;
        int soln = n + 1;
        int flag = 0;
        switch (t)
        {
        case 1:
            for (j = 0; j < n; j++)
            {
                if (j != id && arr[j].status == 2)
                {
                    if (abs(arr[j].ai - firstSoln) == arr[j].di)
                    {
                        soln = 0;
                        flag = 1;
                        cout << soln;
                        break;
                    }
                    if (abs(arr[j].ai - secondSoln) == arr[j].di)
                    {
                        soln = 0;
                        flag = 1;
                        cout << soln;
                        break;
                    }
                }
            }
            if (flag != 1)
            {
                soln = 2;
                if (firstSoln == secondSoln)
                {
                    soln = 1;
                    cout << soln << " " << firstSoln;
                }
                else
                {
                    cout << soln << " " << firstSoln << " " << secondSoln;
                }
            }
            break;
        case 2:
            for (j = 0; j < n; j++)
            {
                if (j != id && arr[j].status == 1)
                {
                    if (abs(arr[j].ai - firstSoln) == arr[j].di)
                    {
                        soln = 0;
                        flag = 1;
                        cout << soln;
                        break;
                    }
                    if (abs(arr[j].ai - secondSoln) == arr[j].di)
                    {
                        soln = 0;
                        flag = 1;
                        cout << soln;
                        break;
                    }
                }
            }
            if (flag != 1)
            {
                if (soln > n)
                {
                    cout << -1;
                    break;
                }
                soln = 2;
                if (firstSoln == secondSoln)
                {
                    soln = 1;
                    cout << soln << " " << firstSoln;
                }
                else
                {
                    cout << soln << " " << firstSoln << " " << secondSoln;
                }
            }
            break;
        case 3:
            for (j = 0; j < n; j++)
            {
                if (j != id && arr[j].status == 1)
                {
                    if (abs(arr[j].ai - firstSoln) == arr[j].di)
                    {
                        soln = 1;
                    }
                    if (abs(arr[j].ai - secondSoln) == arr[j].di)
                    {
                        soln = 2;
                    }
                }
            }
            if (soln > n)
            {
                cout << -1;
                break;
            }
            if (firstSoln == secondSoln)
            {
                cout << 1 << " " << firstSoln;
            }
            else
            {
                cout << soln << " " << firstSoln << " " << secondSoln;
            }
        }
        cout << endl;
    }
}