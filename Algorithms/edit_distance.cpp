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

int in,de,su;
int edit_distance(string s, string t)
{
    int n = s.length(),m = t.length();
    const int inf = 1e10;
    vector<vector<int>> dp(n+1,vector<int>(m+1,inf));

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = i == 0 ? j : i;
                continue;
            }
            if(s[i-1] == t[j-1])
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            dp[i][j] = min({dp[i][j],dp[i-1][j]+de,dp[i][j-1]+in,dp[i-1][j-1]+su});
        }
    }
    return dp[n][m];
}
inline void solve()
{
    // all the code goes here
    in = 1,de = 1,su = 2;
    cout<<edit_distance("intention","execution")<<NL;
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
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}