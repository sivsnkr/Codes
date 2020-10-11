#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define PI 3.14159265
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
int mod = 1000000007;
void read(vector<int> &a);

const int MX = 2e5+5;
vector<int> ranks(MX);
vector<int> p(MX);
vector<vector<pair<int,int>>> g(MX,vector<pair<int,int>>(2,{-1,0}));
int n,m;
int times;
vector<int> timer(MX,2);
int get(int c)
{
    if(p[c] == c)
        return c;
    times = min(times,timer[c]);
    return get(p[c]);
}

void join(int a, int b)
{
    int pa = get(a),pb = get(b);
    if(pa != pb)
    {
        if(ranks[pa] == ranks[pb])
            ranks[pa]++;
        if(ranks[pa] > ranks[pb])
            p[pb] = pa;
        else 
            p[pa] = pb;
    }
}

vector<bool> vis(MX,0);
void dfs(int root,int time)
{
    if(vis[root])
        return;
    vis[root] = 1;
    timer[root] = time;
    for(auto [child,vis] : g[root])
        if(vis)
        {
            join(root,child);
            dfs(child,time);
        }
    vis[root] = 0;
}

inline void solve()
{
    // all the code goes here
    iota(all(p),0);
    cin>>n>>m;
    ranks[1] = MX;
    for(int i = 1; i <= n; i++)
    {
        int x,y;cin>>x>>y;
        if(x > 0)
        {
            g[i][0] = {x,1};
        }
        if(y > 0)
        {
            g[i][1] = {y,1};
        }
    }
    vector<pair<int,int>> query(m);
    for(int i = 0; i < m; i++)
    {
        int num,hand;cin>>num>>hand;
        query[i] = {num,hand};
        g[num][hand-1].second = 0;
    }
    for(int i = m-1; i >= 0; i--)
    {
        auto [root,hand] = query[i];
        int num = g[root][hand-1].first;
        int pa = get(root);
        int pb = get(num);
        if(pa == 1 || pb == 1)
        {
            if(pa != pb && pb == 1)
            {
                dfs(pa,i);
                timer[pa] = i;
            }
            else if(pa != pb)
            {
                dfs(pb,i);
                timer[pb] = i;
            }
        }
        g[root][hand-1].second = 1;
        join(pa,pb);
    }
    for(int i = n; i >= 1; i--)
    {
        times = LLONG_MAX;
        // cout<<p[i]<<" \n"[i==n];
        get(i);
        timer[i] = times;
    }
    // for(int i = 1; i <= n; i++)
    //     if(timer[i] == LLONG_MAX)
    //         timer[i] = -1;
    for(int i = 1; i <= n; i++)
        cout<<timer[i]<<NL;
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