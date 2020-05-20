#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; scanf("%d",&t); while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

vector<vector<LL>> heights;
int n,m;
LL mx = 1e18;

LL solve()
{
    LL ans = LLONG_MAX;

    f(i,0,n)
        f(j,0,m)
        {
            LL need = heights[i][j]-i-j;
            if(need > heights[0][0])
                continue;
            LL a00 = need;
            vector<vector<LL>> dp(n,vector<LL>(m,mx));
            dp[0][0] = heights[0][0]-need;
            f(k,0,n)
                f(l,0,m)
                {
                    if(k == 0 && l == 0)
                        continue;
                    LL need = a00+k+l;
                    if(heights[k][l] < need)
                        continue;
                    need = heights[k][l]-need;
                    if(k > 0)
                        dp[k][l] = min(dp[k][l],dp[k-1][l]+need);
                    if(l > 0)
                        dp[k][l] = min(dp[k][l],dp[k][l-1]+need);
                }
            ans = min(ans,dp[n-1][m-1]);
        }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test
    {
        scanf("%d%d",&n,&m);
        heights.assign(n,vector<LL>(m));
        f(i,0,n)
            f(j,0,m)
                scanf("%lld",&heights[i][j]);
        LL res = solve();
        printf("%lld\n",res);
    }
    return 0;
}