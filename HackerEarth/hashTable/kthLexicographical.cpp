#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    long long int n, q, l, r, k, i, j, x;
    cin >> n >> q >> s;

    long long int a[26][n];

    for (j = 0; j < 26; j++)
        a[j][0] = 0;
    a[s[0] - 97][0]++;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < 26; j++)
            a[j][i] = a[j][i - 1];
        a[s[i] - 97][i]++;
    }

    while (q--)
    {
        cin >> l >> r >> k;
        x = 0;
        for (i = 0; i < 26; i++)
        {
            x += a[i][r - 1] - (l > 1 ? a[i][l - 2] : 0);
            if (x >= k)
                break;
        }
        cout << (char)(i + 97) << endl;
    }
}
