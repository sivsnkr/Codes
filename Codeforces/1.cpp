#include <bits/stdc++.h>
using namespace std;

void dfs(vector<unordered_set<int>> &graph,int src,vector<bool> &havecats,int conscats,int &limitcats,int &noofres,vector<bool> &visited)
{
    if(conscats > limitcats)
        return;
    if(graph[src].size() == 1 && conscats+havecats[src] <= limitcats && src != 0)
    {
        noofres++;
    }
    visited[src] = true;

    for(int i : graph[src])
    {
        if(havecats[src] && !visited[i])
            dfs(graph,i,havecats,conscats+1,limitcats,noofres,visited);
        else if(!visited[i])
            dfs(graph,i,havecats,0,limitcats,noofres,visited);
    }
}

int main()
{
    int nodes,cats;
    cin>>nodes>>cats;

    vector<unordered_set<int>> graph(nodes);
    vector<bool> havecats(nodes);

    int i;
    for(i = 0; i < nodes; i++)
    {
        bool value;
        cin>>value;
        havecats[i] = value;
    }

    for(i = 0; i < nodes-1; i++)
    {
        int src,dest;
        cin>>src>>dest;
        src--,dest--;
        graph[src].insert(dest);
        graph[dest].insert(src);
    }

    int noofres = 0;
    vector<bool> visited(nodes,false);
    dfs(graph,0,havecats,0,cats,noofres,visited);
    cout<<noofres<<"\n";
}