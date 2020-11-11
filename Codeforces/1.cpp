#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
void read(vector<int> &a);

class Combinatorics
{
    public:
    vector<int> ncr(int n,int r,int p)
    {
        if(n-r < r)
            r = n-r;
        vector<int> dp(r+1,0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = min(r,i); j > 0; j--)
                dp[j] = (dp[j]+dp[j-1])%p;
        }
        return dp;// access dp[r]
    }

    vector<int> derangements(int n)
    {
        vector<int> der(n+1,0);
        der[1] = 0;
        der[2] = 1;
        for (int i = 3; i <= n; ++i)
            der[i] = (i - 1) * (der[i - 1] + der[i - 2]);
        return der;
    }
};

inline void solve()
{
    // all the code goes here
    class Combinatorics st;
    int n;cin>>n;
    int k;cin>>k;
    vector<int> der = st.derangements(n);
    int sum = 0;
    for(int i = n-k; i <= n; i++)
    {
        sum+=st.ncr(n,i,1e17)*der[n-i];
    }
    cout<<sum+1<<NL;
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