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
// #define int LL
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
int mod = 1000000007;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

#define int long double
void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

const int MX = 1e5+5;
int n,m,d;
vector<vector<pair<int,int>>> g(MX);
vector<bool> vis(MX);
int num;
vector<pair<int,int>> dp(MX);
vector<int> re;

int mi = 1e8;
bool dfs(int root, bool print,int plength,int cnum)
{
    if(vis[root])
        return false;
    vis[root] = 1;
    if(root == n)
    {
        mi = min(mi,cnum/plength);
        vis[root] = 0;
        if(plength > 0 && cnum/plength > num)
            return false;
        if(print)
            re.pb(root);
        return true;
    }
    
    bool res = false;
    for(auto[child,num] : g[root])
    {
        res  = dfs(child,print,plength+1,cnum+num);
        if(res)
            break;
    }
    if(res && print)
        re.pb(root);
    vis[root] = 0;
    return res;
}

inline void solve()
{
    // all the code goes here
    cin>>n>>m;
    f(i,0,m)
    {
        int x,y,c;cin>>x>>y>>c;
        g[x].pb({y,c});
    }
    dfs(1,0,0,0);
    num = mi;
    dfs(1,1,0,0);
    // cout<<"mi "<<mi<<NL;
    cout<<size(re)-1<<NL;
    reverse(all(re));
    f(i,0,size(re))
        cout<<re[i]<<" \n"[i==size(re)-1];
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