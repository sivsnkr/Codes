#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define testf int t; scanf("%d",&t); while(t--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define size(container) (int)container.size()
#define int long long int
const int MX = 1e5+2;
int n;
int a[MX];
void solve()
{
    cin>>n;
    f(i,0,n)
        cin>>a[i];
    int dp[n][2];
    f(i,0,n)
    {
        dp[i][0] = abs(-1-a[i]);
        dp[i][1] = abs(1-a[i]);
    }
    int ans = 0;
    int mo = dp[0][0];
    int po = dp[0][1];
    // f(i,0,n)
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<NL;
    f(i,1,n)
    {
        int cmo = mo;
        mo = min(mo+dp[i][1],po+dp[i][0]);
        po = min(po+dp[i][1],cmo+dp[i][0]);
    }
    cout<<po<<NL;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // clock_t st = clock();
    // all the code goes here
    solve();
    // cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}