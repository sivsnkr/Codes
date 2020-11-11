#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
void read(vector<int> &a);

class Combinatorics
{
    public:
    int ncr(int n,int r,int p)
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
        return dp[r];
    }

    int derangements(int n)
    {
        vector<int> der(n+1,0);
        der[1] = 0;
        der[2] = 1;
        for (int i = 3; i <= n; ++i)
            der[i] = (i - 1) * (der[i - 1] + der[i - 2]);
        return der[n];
    }
};


inline void solve()
{
    // all the code goes here
    class Combinatorics st;
    int nc = st.ncr(5,2,1e9);
    int dis = st.derangements(5);

    cout<<nc<<" "<<dis<<NL;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}