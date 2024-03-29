#include <bits/stdc++.h>
using namespace std;

class Trees
{
    vector<vector<int>> g;
    public:
    Trees(int size,int v)
    {
        g.resize(size+1);
        for(int i = 0; i < size-1; i++)
        {
            int x,y;cin>>x>>y;
            g[x].push_back(y),g[y].push_back(x);
        }
    }

    void dfs(int root, int par)
    {
        for(int i : g[root])
        {
            if(i != par)
            {
                dfs(i,root);
            }
        }
    }

    int diameter_of_tree(int root, int par)
    {
        // find the farhtest node from 1, then find the farthest node form that node, that will be the diameter of the tree

        // to make this work, declare 'dia' globally
        int len = 0;
        for(int child : g[root])
        {
            if(child != par)
            {
                int cur = 1+diameter_of_tree(child,root);
                dia = max(dia,cur+len);
                len = max(len,cur);
            }
        }
        return len;
    }

    void bfs(int root)
    {
        queue<pair<int,int>> q;
        q.push({root,root});
        while(!q.empty())
        {
            auto [root, par] = q.front();
            q.pop();
            for(int i : g[root])
            {
                if(i != par)
                {
                    q.push({i,root});
                }
            }
        }
    }
};

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    class Trees st(n,1);
    st.dfs(1,1);
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
