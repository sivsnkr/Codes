#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll dp[n][n];

    for (int l = n - 1; l >= 0; l--)
    {
        for (int r = l; r < n; r++)
        {
            if (l == r)
                dp[l][r] = a[l];
            else
            {
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}