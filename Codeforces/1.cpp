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
#define pb push_back
#define int LL
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

const int MX = 1e5+5;
vector<vector<int>> g(MX);
vector<bool> vis(MX,0);

int pow(int n,int k)
{
    int ans = 1;
    while(k)
    {
        if(k&1)
            ans = (ans*n)%mod;
        k/=2;
        n = (n*n)%mod;
    }
    return ans;
}

int sz;

void dfs(int root)
{
    if(vis[root])
        return;
    sz++;
    vis[root] = 1;
    for(int i : g[root])
        dfs(i);
}

inline void solve()
{
    // all the code goes here
    int n,k;cin>>n>>k;
    f(i,0,n)
    {
        int x,y,c;cin>>x>>y>>c;
        if(c == 0)
            g[x].pb(y),g[y].pb(x);
    }
    int ans = pow(n,k);
    f(i,1,n+1)
    {
        if(vis[i])
            continue;
        sz = 0;
        dfs(i);
        ans-=pow(sz,k);
        ans+=mod;
        ans%=mod;
    }
    cout<<ans<<NL;
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