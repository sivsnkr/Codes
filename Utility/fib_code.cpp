#include <bits/stdc++.h>
using namespace std;

int fib(int i)
{
    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    else
    {
        int f[i];
        f[0] = 0, f[1] = 1;
        int j = 2;
        while (j <= i)
        {
            f[j] = f[j - 1] + f[j - 2];
            j++;
        }
        return f[i];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> f_code(n + 1);

    int i = n;
    int maxIndex = 0;
    while (n > 0)
    {
        while (fib(i) > n)
        {
            i--;
        }
        n -= fib(i);
        f_code[i - 2] = 1;
        if (i - 2 > maxIndex)
        {
            maxIndex = i - 1;
        }
        i = n + 1;
    }

    f_code[maxIndex] = 1;

    for (i = 0; i <= maxIndex; i++)
    {
        cout << f_code[i];
    }
    cout << endl;
}