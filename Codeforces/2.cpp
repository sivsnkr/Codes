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
    int n;cin>>n;
    vector<pair<int,int>> data(n);
    f(i,0,n)cin>>data[i].first>>data[i].second;
    int k;cin>>k;
    vector<int> kval(k);
    f(i,0,k)cin>>kval[i];
    sort(all(kval));
    sort(all(data));
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    // int mx = 0;
    f(i,0,n+1)
    {
        f(j,0,k+1)
        {
            if(data[i-1].first <= kval[j] && i < n && j < k)
            {
                dp[i+1][j+1] = dp[i][j]+data[i].second;
            }
            // dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
            // mx = max(dp[i][j],mx);
        }
    }


    f(i,0,n+1)
        f(j,0,k+1)
            cout<<dp[i][j]<<" \n"[j==k];

    cout<<dp[n][k]<<NL;
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