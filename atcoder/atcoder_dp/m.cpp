#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

l mod = 1e9 + 7;
void add_self(int &a, int b)
{
    long long int t = a;
    t += b;
    t %= mod;
    a = t;
}

void sub_self(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int n, k;
    cin >> n >> k;

    int dp[k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int child = 0; child < n; child++)
    {
        int upto;
        cin >> upto;
        vector<int> f(k + 1, 0);
        for (int used = k; used >= 0; used--)
        {
            int l = used + 1;
            int r = used + min(upto, k - used);
            if (l <= r)
            {
                add_self(f[l], dp[used]);
                if (r + 1 <= k)
                    sub_self(f[r + 1], dp[used]);
            }
        }

        int psum = 0;
        for (int i = 0; i <= k; i++)
        {
            add_self(psum, f[i]);
            add_self(dp[i], psum);
        }
    }

    cout << dp[k] << "\n";
    return 0;
}