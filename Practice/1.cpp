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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    vector<int> t{1,2,3,4,5,6};
    int reqsum = 21;
    int n = size(t);
    vector<vector<bool>> dp(n+1,vector<bool>(reqsum+1,0));
    f(i,0,n+1)
        dp[i][0] = 1;
    f(i,1,n+1)
    {
        f(sum,1,reqsum+1)
        {
            if(sum >= t[i-1])
                dp[i][sum] = dp[i-1][sum]||dp[i-1][sum-t[i-1]];
            else
                dp[i][sum] = dp[i-1][sum];
        }
    }

    cout<<dp[n][reqsum]<<endl;
    return 0;
}