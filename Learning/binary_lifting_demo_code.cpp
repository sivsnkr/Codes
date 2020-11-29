// problem url https://codeforces.com/gym/102694/problem/C
#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
void read(vector<int> &a);

int L;
vector<vector<int>> g;
vector<vector<int>> up;
vector<int> tin,tout;
vector<int> depths;
int timer;

void dfs(int root, int par,int depth)
{
    tin[root] = ++timer;
    up[root][0] = par;
    depths[root] = depth;
    f(i,1,L+1)
    {
        up[root][i] = up[up[root][i-1]][i-1];
    }

    for(int i : g[root])
    {
        if(i != par)
        {
            dfs(i,root,depth+1);
        }
    }

    tout[root] = ++timer;
}

bool is_ansistor(int u, int v)
{
    if(tin[u] <= tin[v] && tout[u] >= tout[v])
        return 1;
    return 0;
}

int dist_lca(int root,int lca)
{
    if(is_ansistor(root,lca))
        return root;
    else if(is_ansistor(lca,root))
        return lca;
    fr(i,L,0)
    {
        if(!is_ansistor(up[root][i],lca))
        {
            root = up[root][i];
        }
    }
    return up[root][0];
}

int calc_dist(int root,int dist)
{
    int val = root;
    if(dist == 0)
        return val;
    while(dist > 0)
    {
        int p = 0;
        while(pow(2,p) <= dist)
            p++;
        dist-=pow(2,p-1);
        val = up[val][p-1];
    }
    return val;
}

inline void solve()
{
    // all the code goes here

    int n;cin>>n;
    L = ceil(log2(n));
    g.resize(n+1);
    up.assign(n+1,vector<int>(L+1));
    depths.resize(n+1);
    tin.resize(n+1),tout.resize(n+1);
    f(i,0,n-1)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,1,0);
    int q;cin>>q;
    while(q--)
    {
        int a,b,c;cin>>a>>b>>c;
        int lca = dist_lca(a,b);
        int dist = depths[a]-depths[lca];
        int total_dist = depths[a]+depths[b]-2*depths[lca];
        if(c < total_dist)
        {
            if(c <= dist)
            {
                // on his side of lca
                cout<<calc_dist(a,c)<<NL;
            }
            else
            {
                // on the other side of lca
                cout<<calc_dist(b,total_dist-c)<<NL;
            }
        }
        else
            cout<<b<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}