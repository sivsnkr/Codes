#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
void read(vector<int> &a);

const int MX = 3e5+5;
const int L = log2(MX);
vector<vector<int>> g(MX);
vector<vector<int>> up(MX,vector<int>(L+1));
vector<int> tin(MX),tout(MX);
int timer;

void dfs(int root, int par)
{
    tin[root] = ++timer;
    up[root][0] = par;
    f(i,1,L+1)
    {
        up[root][i] = up[up[root][i-1]][i-1];
    }

    for(int i : g[root])
    {
        if(i != par)
        {
            dfs(i,root);
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

int lcam;
int dist_lca(int root,int lca)
{
    int dist = 0;
    fr(i,L,0)
    {
        if(!is_ansistor(up[root][i],lca))
        {
            dist+=pow(2,i);
            root = up[root][i];
        }
    }
    // cout<<"lca "<<lcam<<NL;
    lcam = up[root][0];
    if(is_ansistor(root,lca))
        lcam = root;
    else if(is_ansistor(lca,root))
        lcam = lca;
    if(lca == root)
        return 0;
    return dist+1;
}

int calc_dist(int root,int dist)
{
    int val = root;
    while(dist > 0)
    {
        int p = 0;
        while(pow(2,p) < dist)
            p++;
        dist-=pow(2,p);
        val = up[val][p];
    }
    return val;
}

inline void solve()
{
    // all the code goes here

    int n;cin>>n;
    f(i,0,n-1)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,1);
    int q;cin>>q;
    f(i,1,n+1)
        cout<<tin[i]<<" \n"[i==n];
    while(q--)
    {
        int a,b,c;cin>>a>>b>>c;
        dist_lca(a,b);
        // cout<<"lca "<<lcam<<NL;
        int dist = dist_lca(a,lcam);
        int dist1 = dist_lca(b,lcam);

        int total_dist = dist+dist1;
        // cout<<"total "<<total_dist<<NL;
        if(c < total_dist)
        {
            if(c <= dist)
            {
                // on his side of lca
                cout<<calc_dist(a,c)<<NL;
                // cout<<"how you doing"<<NL;
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