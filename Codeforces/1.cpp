#include <bits/stdc++.h>
using namespace std;

void dfs(vector<unordered_set<int>> &graph,int src,long long int &noofedge,bool visited[],int &noofver)
{
    if(visited[src])
        return;
    visited[src] = true;
    noofver++;
    noofedge+=graph[src].size();
    for(int i : graph[src])
    {
        if(!visited[i])
        {
            dfs(graph,i,noofedge,visited,noofver);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vector<unordered_set<int>> graph(n+1);

    int i;
    for(i = 0; i < m; i++)
    {
        int src,dest;
        cin>>src>>dest;
        graph[src].insert(dest);
        graph[dest].insert(src);
    }

    bool visited[n+1];
    memset(visited,0,n+1);
    bool valid = true;
    for(i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            // do the dfs
            long long int noofedge = 0;
            int noofver = 0;
            dfs(graph,i,noofedge,visited,noofver);
            if(noofedge != (long long)noofver*(noofver-1))
            {
                valid = false;
                break;
            }
        }
    }
    if(valid)
        cout<<"YES";
    else
    {
        cout<<"NO";
    }
    cout<<"\n";
    
    return 0;
}