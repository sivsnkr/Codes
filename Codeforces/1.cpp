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
    int n;cin>>n;
    const int INF = 1e10;
    vector<vector<int>> dp(n+1,vector<int>(8,INF));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++)
    {
        int c;cin>>c;
        string s;cin>>s;
        int smask = 0;
        for(int j = 0; j < 3; j++)
        {
            char c = 'C'-j;
            bool have = 0;
            for(char ci : s)
                if(ci == c)
                    have = 1;
            if(have)
                smask+=((int)1<<j);
        }

        for(int mask = 0; mask < 8; mask++)
        {
            dp[i+1][mask] = min(dp[i+1][mask],dp[i][mask]);
            dp[i+1][mask|smask] = min(dp[i+1][mask|smask],dp[i][mask]+c);
        }
    }

    int ans = dp[n][7];
    cout<<(ans >= INF ? -1:ans)<<NL;
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