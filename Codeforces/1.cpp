#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
template <typename T>
void read(vector<T> &a);

inline void solve()
{
    // all the code goes here
    test
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        f(i, 0, n)
        {
            int t, x;
            cin >> t >> x;
            a[i] = {t, x};
        }

        int it = a[0].first;
        int mi = 0, mx = a[0].second;
        int sp = 1;
        int cnt = 0;
        f(i, 1, n)
        {
            if (a[i].first < it + mx)
            {
                int ri = mi + (a[i].first - it) * sp;
                int rf = min(mi + ((i + 1 < n ? a[i + 1].first : (int)1e9 + 5) - it) * sp, mx);
                if ((a[i].second >= ri && a[i].second <= rf) || (a[i].second >= ri && a[i].second <= rf))
                    cnt++;
            }
            else
            {
                cnt++;
                it = a[i].first;
                // mi =
            }
        }
        cout << cnt << NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
template <typename T>
void read(vector<T> &a)
{
    for (auto &it : a)
        cin >> it;
}