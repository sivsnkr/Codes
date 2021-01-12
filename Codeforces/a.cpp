#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
template<typename T>
void read(vector<T> &a);
int inf = 1e15;
inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    int dp[n+1][8];
    f(i,0,n+1)
        f(j,0,8)
            dp[i][j] = inf;
    dp[0][0] = 0;
    f(i,0,n)
    {
        int n;string s;
        cin>>n>>s;
        int s_mask = 0;
        f(pos,0,3)
        {
            if(find(all(s),'A'+pos) != s.end())
                s_mask+=((int)1<<pos);
        }
        f(mask,0,8)
        {
            dp[i+1][mask] = min(dp[i+1][mask],dp[i][mask]);
            dp[i+1][mask|s_mask] = min(dp[i+1][mask|s_mask],dp[i][mask]+n);
        }
    }

    cout<<(dp[n][7] >= inf ? -1 : dp[n][7])<<NL;
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