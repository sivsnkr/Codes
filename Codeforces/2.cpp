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
    const int MX = 1e6+6;
    vector<int> dp(MX,0);
    f(i,2,MX)
    {
        if(i*i < MX && dp[i] == 0)
        {
            if(dp[i*i] == 1)
                dp[i*i]++;
            else
            {
                dp[i*i]+=2;
            }
        }
        for(int j = i*i; j < MX; j+=i)
        {
            if(dp[j] == 0)
            {
                dp[j]++;
            }
        }
    }

    f(i,1,MX)
    {
        dp[i]+=dp[i-1];
    }
    int q;cin>>q;
    f(i,0,q)
    {
        int x;cin>>x;
        cout<<x-dp[x]<<NL;
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