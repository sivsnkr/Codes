#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf int t;scanf("%d", &t);while (t--)
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
int mod = 1000000007;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

inline void solve()
{
    // all the code goes here
    test
    {
        int n;cin>>n;
        vector<int> a(n);
        read(a);
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        f(i,0,n)
        {
            dp[i+1][0] = max(dp[i+1][0],dp[i][0]+i%2 == 0?a[i]:0);
            if(i+2 < n)
                dp[i+2][1] = max(dp[i+2][1],max(dp[i][0],dp[i][1])+i%2 == 0?a[i]:a[i+1]);
            dp[i+1][2] = max(dp[i+1][2],max({dp[i][0],dp[i][1],dp[i][2]})+i%2 == 0 ? a[i]:0);
        }
        cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        fh;
    #endif
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}