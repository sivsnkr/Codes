#include<bits/stdc++.h>
using namespace std;

// work only for DAG(directed acyclic graph)
// input
// 5 0
// 5 2
// 4 0
// 4 1
// 2 3
// 3 1
void dfs(int src, vector<unordered_set<int>> &graph, stack<int> &elements, vector<bool> &visited)
{
    visited[src] = 1;

    for(auto i : graph[src])
    {
        if(!visited[i])
        {
            dfs(i,graph,elements,visited);
        }
    }
    elements.push(src);
}

int main()
{
    int nodes = 6,edges = 6;

    vector<unordered_set<int>> graph(nodes);
    int i;
    for(i = 0; i < edges; i++)
    {
        int src,dest;
        cin>>src>>dest;
        graph[src].insert(dest);
    }

    stack<int> elements;
    vector<bool> visited(nodes);
    for(i = 0; i < nodes; i++)
    {
        if(!visited[i])
            dfs(i,graph,elements,visited);
    }

    while(!elements.empty())
    {
        cout<<elements.top()<<" ";
        elements.pop();
    }
    cout<<endl;
}