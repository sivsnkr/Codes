#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
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