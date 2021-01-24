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
    vector<int> a({ 10, 3, 2, 5, 7, 8 });
    int n = a.size();
    vector<bool> in(n,0);
    in[0] = 1;
    vector<int> dp = a;
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i-2; j >= 0; j--)
        {
            if(i != n-1)
            {
                if(dp[j]+a[i] > dp[i])
                {
                    in[i] = in[j];
                    dp[i] = dp[j]+a[i];
                }
            }
            else
            {
                if(dp[j]+a[i] > dp[i])
                {
                    if(in[j])
                        dp[i] = max(dp[i],dp[j]+a[i]-a[0]);
                    else    
                        dp[i] = max(dp[i],dp[j]+a[i]);
                }
            }
        }
        mx = max(mx,dp[i]);
    }

    for(int i : dp)
        cout<<i<<" ";
    cout<<NL;
    cout<<mx<<NL;
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