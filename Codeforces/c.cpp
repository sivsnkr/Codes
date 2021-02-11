#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
template<typename T>
void read(vector<T> &a);

inline void solve()
{
    // all the code goes here
    int cnt = 1e10;
    int sum = 0;
    for(int i = 0; i < cnt; i++)
    {
        sum+=i;
        sum%=mod;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<setprecision(20);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}