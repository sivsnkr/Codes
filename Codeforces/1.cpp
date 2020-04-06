#include <bits/stdc++.h>
using namespace std;

void getres(int m, int n, string s, string &minv, string &maxv)
{
    // get the sum of the string
    if (s.length() > m)
        return;
    if(s.length() == m)
    {
        int sum = 0;
        for (char i : s)
        {
            sum += (int(i) - '0');
        }

        if (sum == n)
        {
            if (s > maxv)
                maxv = s;
            if (s < minv)
                minv = s;
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        getres(m, n, s + to_string(i), minv, maxv);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    if(n == 0 && m == 1)
        cout<<0<<" "<<0;

    else
    {
        string minv = "9", maxv = "0";
        for (int i = 1; i <= 9; i++)
            getres(m, n, to_string(i), minv, maxv);

        // sum of minv and maxv
        int sum1 = 0, sum2 = 0;
        for (char i : minv)
            sum1 += (int(i) - '0');
        for (char i : maxv)
            sum2 += (int(i) - '0');
        if (sum1 != sum2 || maxv.length() != m || minv.length() != m)
            cout << -1 << " " << -1;
        else
        {
            cout << minv << " " << maxv;
        }
    }
    cout << "\n";
    return 0;
}