#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    test
    {
        int n;cin>>n;
        vector<int> a(n);
        read(a);
        sort(all(a));
        const int inf = 1e9;
        vector<vector<int>> dp(n+1,vector<int>(2*n+1,inf));
        dp[0][0] = 0;
        f(i,1,n+1)
        {
            f(j,1,2*n)
            {
                if(dp[i-1][j-1] < inf && i < n)
                {
                    dp[i][j] = dp[i-1][j-1]+abs(a[i-1]-j);
                }
                dp[i][j] = min({dp[i][j-1],dp[i][j],dp[i-1][j]});
            }
        }

        cout<<dp[n][2*n]<<NL;
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
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}