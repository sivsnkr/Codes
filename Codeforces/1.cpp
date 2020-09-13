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
const int maxn=200007;
vector<vector<int>> dp(maxn,vector<int>(26,0));

int cnt(int u, int v)
{
    int ret = 0,mx = 0;
    f(i,0,26)
    {
        ret+=dp[u][i]+dp[v][i];
        mx = max(mx,dp[u][i]+dp[v][i]);
    }
    return ret-mx;
}

inline void solve()
{
    // all the code goes here
    test
    {
        int n,k;cin>>n>>k;
        string s;cin>>s;
        dp.assign(n,vector<int>(26,0));
        f(i,0,n)
            dp[i%k][s[i]-'a']++;
        int count = 0;
        f(i,0,k)
            count += cnt(i,k-1-i);
        cout<<count/2<<NL;
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