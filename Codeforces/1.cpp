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

const int N = 3e5+5;
vector<int> dp[N],ans(N),a(N);
inline void solve()
{
    // all the code goes here
    test
    {
        int n;cin>>n;
        f(i,1,n+1)
            dp[i].clear();
        f(i,1,n+1)
        {
            int x;cin>>x;
            ans[i] = 1e9;
            dp[x].pb(i);
        }
        f(i,1,n+1)
        {
            if(size(dp[i]) == 0)
                continue;
            int diff = max(dp[i][0],n+1-dp[i].back());
            f(j,0,size(dp[i])-1)
                diff = max(diff,dp[i][j+1]-dp[i][j]);
            ans[diff] = min(ans[diff],i);
        }

        f(i,1,n+1)
        {
            if(i >= 2)
                ans[i] = min(ans[i],ans[i-1]);
            if(ans[i] == 1e9)
                cout<<-1<<" ";
            else
            {
                cout<<ans[i]<<" ";
            }
        }
        cout<<NL;
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