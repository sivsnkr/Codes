#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
void read(vector<int> &a);


int n,k;
const int MX = 2e5+5;
vector<vector<int>> g(MX);
vector<bool> vis(MX);
int sum;
void dfs(int root,int len,int par)
{
    if(vis[root])
        sum+=len;
    for(int i : g[root])
        if(i != par)
            dfs(i,len+(vis[i]?0:1),root);
}

inline void solve()
{
    // all the code goes here
    cin>>n>>k;
    for(int i = 0; i < n-1; i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
    }

    queue<pair<int,int>> st;
    st.push({1,1});
    vector<int> res;
    while(!st.empty())
    {
        auto [top,par] = st.front();
        st.pop();
        for(auto c : g[top])
            if(c != par)
                st.push({c,top});
        // if()
        res.push_back(top);
    }

    int i = res.size()-1;
    while(k--)
    {
        vis[res[i]] = 1;
        i--;
    }
    for(int i = 1; i <= n; i++)
        if(vis[i])
            cout<<"r "<<i<<NL;
    dfs(1,1,1);
    cout<<sum<<NL;
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