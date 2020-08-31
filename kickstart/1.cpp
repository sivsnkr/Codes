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

const int MX = 1e4+2;
int a[MX];

int penalty(int i,int j,int k)
{
    if(a[i] > a[i-1] && j <= k)
        return 1;
    if(a[i] < a[i-1] && j >= k)
        return 1;
    return 0;
}

inline void solve()
{
    // all the code goes here
    int te = 1;
    test
    {
        int n;cin>>n;
        f(i,0,n)
            cin>>a[i];
        int dp[n][4];
        memset(dp,0,sizeof(dp));
        f(i,1,n)
        {
            f(j,0,4)
            {
                int mx = LLONG_MAX;
                f(k,0,4)
                {
                    int p = penalty(i,j,k);
                    mx = min(mx,dp[i-1][k]+p);
                }
                dp[i][j] = mx;
            }
        }
        int ans = *min_element(dp[n-1],dp[n-1]+4);
        cout<<"Case #"<<te++<<": "<<ans<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}