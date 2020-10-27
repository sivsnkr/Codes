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
    test
    {
        int n;cin>>n;
        vector<int> a(n+4,0);
        for(int i = 2; i < n+2; i++)
        {
            cin>>a[i];
        }
        vector<int> dp(n+5,0);
        int sum = 0;
        int mx = 0;
        for(int i = 2; i < n+2; i++)
        {
            if(i%2)
            {
                dp[i] = max(dp[i],dp[i-2]+a[i]-a[i-1]);
            }
            else
            {
                dp[i] = max(dp[i],dp[i-2]+a[i-1]-a[i]);
                sum+=a[i];
            }
            mx = max(mx,dp[i]);
        }
        for(int i = 0; i < n+2; i++)
            cout<<dp[i]<<" \n"[i==n+1];
        cout<<sum+mx<<NL;
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