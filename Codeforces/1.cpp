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
int num;
vector<int> re;
bool dfs(int root, bool print,int plength,int cnum)
{
    if(root == n)
    {
        if(plength > 0 && cnum/plength > num)
            return false;
        if(print)
            re.pb(root);
        return true;
    }
    
    bool res = false;
    for(auto[child,num] : g[root])
    {
        // cout<<"child "<<child<<NL;
        res = (res || dfs(child,print,plength+1,cnum+num));
    }
    // cout<<"res root "<<res<<" "<<root<<NL;
    if(res && print)
        re.pb(root);
    return res;
}

bool good(int m)
{
    // cout<<"m "<<m<<NL;
    num = m;
    return dfs(1,0,0,0);
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

    int ans = -1,l = 0,r = 1e10;
    f(i,0,100)
    {
        int m = (l+r)/2;
        if(good(m))
        {
            ans = m;
            r = m-1;
        }
        else
        {
            l = m+1;
        }
    }
    // cout<<"ans "<<ans<<NL;
    num = ans;
    dfs(1,1,0,0);
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