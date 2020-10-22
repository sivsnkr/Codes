#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    int n,p,q,r;cin>>n>>p>>q>>r;
    vector<int> a(n);
    read(a);
    vector<vector<int>> dp(n+1,vector<int>(3,LLONG_MIN));

    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i-1][0],p*a[i-1]);
        dp[i][1] = max(dp[i-1][1],dp[i][0]+q*a[i-1]);
        dp[i][2] = max(dp[i-1][2],dp[i][1]+r*a[i-1]);
    }
    cout<<dp[n][2]<<NL;
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
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}