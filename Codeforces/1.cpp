#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
void read(vector<int> &a);

const int MX = 2e5+5;
vector<vector<int>> g(MX);
vector<int> cost(MX);
vector<int> cost_sum(MX);
int costt,sum,ans,total;

void dfs(int root, int par,int depth)
{
    cost_sum[root] = cost[root];
    total+=cost[root];
    costt+=depth*cost[root];
    for(int i : g[root])
    {
        if(i != par)
        {
            dfs(i,root,depth+1);
            cost_sum[root]+=cost_sum[i];
        }
    }
}

void dfs(int root, int par)
{
    ans = max(ans,costt);

    for(int i : g[root])
    {
        if(i != par)
        {
            int ccost = cost_sum[i];
            int pcost = total-ccost;

            costt+=(pcost-ccost);
            dfs(i,root);
            costt-=(pcost-ccost);
        }
    }
}

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    f(i,1,n+1)
        cin>>cost[i];
    f(i,0,n-1)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1,1,0);

    dfs(1,1);

    cout<<ans<<NL;
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