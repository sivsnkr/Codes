#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> colors(n + 2, 1);
    int i;
    for (i = 2; i * i <= n + 1; i++)
    {
        if (colors[i] == 1)
        {
            for (int j = i * i; j <= n + 1; j += i)
            {
                if (colors[j] == 1)
                    colors[j] = colors[i] + 1;
            }
        }
    }

    vector<int> c = colors;
    sort(c.begin(), c.end());
    int no = 0;
    for (int i = 0; i < n + 2; i++)
    {
        if (c[i] != c[i + 1])
            no++;
    }
    cout << no << "\n";
    for (i = 2; i <= n + 1; i++)
    {
        cout << colors[i] << " ";
    }
    cout << "\n";
    return 0;
}