#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
void read(vector<int> &a);

int ncr(int n,int r,int p)
{
    if(n-r < r)
        r = n-r;
    vector<int> dp(r+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = min(r,i); j >= 0; j--)
            dp[j] = (dp[j]+dp[j-1])%p;
    }
    return dp[r];
}

inline void solve()
{
    // all the code goes here
    int res = ncr(35,2,1e7+9);
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
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}