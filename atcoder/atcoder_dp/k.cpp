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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool dp[k + 1];
    for (int i = 0; i <= k; i++)
    {
        for (int j : a)
        {
            if (j <= k && !dp[k - j])
                dp[i] = true;
        }
    }
    puts(dp[k] ? "First" : "Second");
    return 0;
}