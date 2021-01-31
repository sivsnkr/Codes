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
    int n;cin>>n;
    const int mod = 1e9+7;
    vector<vector<int>> dp(2,vector<int>(n+1,0));
    dp[0][0] = 1,dp[0][1] = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[0][i] = (dp[0][i-1]*19+dp[1][i-1]*6)%mod;
        dp[1][i] = (dp[1][i-1]*20+dp[0][i-1]*7)%mod;
    }

    int res = dp[0][n];
    cout<<res<<NL;
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