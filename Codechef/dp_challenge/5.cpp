#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define  f(i,j,n) for(int i = j; i <= n; i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; scanf("%d",&t); while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // all the code goes here
    int n,k,x;
    cin>>n>>k;
    map<int,int>m;
   
    f(i,1,n)
    {
        cin>>x;
        m[x]++;
    }
    n = (int)m.size();
    vector<int> a(n+1,0);
    int i = 1;
    for(auto it : m)
        a[i++] = it.second;
    k = min(n,k);
    vector<vector<LL>> dp(n+1,vector<LL>(k+1,0));
    LL ans = 0;
    f(i,0,n)
        dp[i][0]=1;
    f(i,1,n)
        f(j,1,k)
            dp[i][j]=((dp[i-1][j-1]*a[i])%mod +dp[i-1][j])%mod;
    f(i,0,k)
        ans = (ans+dp[n][i])%mod;
    cout<<ans<<endl;
    return 0;
}