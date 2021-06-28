#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int series[n + 1];
    series[0] = 0;
    series[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        series[i] = 1 + series[i - series[series[i - 1]]];
    }

    for (int i : series)
    {
        cout << i << " ";
    }
    cout << endl;
}