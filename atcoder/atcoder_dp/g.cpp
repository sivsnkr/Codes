#include<bits/stdc++.h>
using namespace std;
 
int dfs(vector<set<int>> &graph,bool visited[],int src,vector<int> &dp)
{
    if(visited[src])
    {
        return dp[src];
    }
 
    visited[src] = 1;
    int m = 0;
    for(int a : graph[src])
    {
        int b = dfs(graph,visited,a,dp);
        dp[a] = max(dp[a],b);
        m = max(m,b);
    }
    return m+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    // all the code goes here
    int n,m;cin>>n>>m;
 
    vector<set<int>> graph(n);
    vector<int> dp(n,0);
 
    for(int i = 0; i < m; i++)
    {
        int src,dest;cin>>src>>dest;src--,dest--;
        graph[src].insert(dest);
    }
 
    bool visited[n];
    memset(visited,0,sizeof(visited));
 
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            int v = dfs(graph,visited,i,dp);
            dp[i] = max(dp[i],v);
        }
    }
 
    int mv = *max_element(dp.begin(),dp.end());
    cout<<mv-1<<"\n";
 
    return 0;
}
