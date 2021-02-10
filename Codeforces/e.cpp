#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
template<typename T>
void read(vector<T> &a);

const int MX = 1e5+5;
vector<vector<int>> g(MX);
vector<int> len(MX);
vector<int> pop(MX),hi(MX),unhappy(MX),happy(MX);

int dfs(int root, int par)
{
    int length = 0;
    for(int i : g[root])
    {
        if(i != par)
        {
            length += dfs(i,root);
        }
    }
    len[root] = length+pop[root];;
    return len[root];
}

bool ok = 1;
void dfs(int root, int par, int p_un)
{
    int hap = (len[root]+hi[root]);
    if(hap%2)
    {
        ok = 0;
    }
    hap/=2;
    // p_un = min(p_un,len[root]);
    int un = len[root]-hap;
    if(un > len[root] || un < 0)
        ok = 0;
    unhappy[root] = un;
    happy[root] = hap;
    for(int i : g[root])
    {
        if(i != par)
        {
            dfs(i,root,un);
        }
    }
}

pair<int,int> dfs_check(int root, int par)
{
    int un = 0;
    int ha = 0;
    bool en = 0;
    for(int i : g[root])
    {
        if(i != par)
        {
            en = 1;
            auto [unh,hap] = dfs_check(i,root);
            un+=unh;ha+=hap;
        }
    }
    cout<<"root "<<root<<NL;
    cout<<unhappy[root]<<" "<<un<<" "<<en<<NL;
    if((unhappy[root] > un && en) || (ha > happy[root] && en))
        ok = 0;
    return {unhappy[root],happy[root]};
}

inline void solve()
{
    // all the code goes here
    test
    {
        int n,m;cin>>n>>m;
        ok = 1;
        for(int i = 0; i <= n; i++)
        {
            g[i].clear();
            len[i] = 0;
            unhappy[i] = 0;
            happy[i] = 0;
        }
        for(int i = 1; i <= n; i++)
            cin>>pop[i];
        for(int i = 1; i <= n; i++)
            cin>>hi[i];
        for(int i = 0; i < n-1; i++)
        {
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1,1);
        dfs(1,1,-1e17);
        if(ok)
            dfs_check(1,1);

        if(ok)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<NL;
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
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}
