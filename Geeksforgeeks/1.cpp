#include<bits/stdc++.h>
using namespace std;

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
    int nodes = 26;
    vector<string> dict(5);
    for(int i = 0; i < 5; i++)
    {
        cin>>dict[i];
    }

    vector<unordered_set<int>> graph(nodes);
    int i;
    for(i = 0; i < 5; i++)
    {
        int length = dict[i].length();
        for(int j = 0; j < length; j++)
        {
            for(int k = j+1; k < length; k++)
            {
                if(graph[dict[i][k]-97].find(dict[i][j]-97) == graph[dict[i][k]-97].end())
                    graph[dict[i][j]-97].insert(dict[i][k]-97);
            }
        }
    }

    stack<int> elements;
    vector<bool> visited(nodes,false);
    for(i = 0; i < nodes; i++)
    {
        if(!visited[i])
            dfs(i,graph,elements,visited);
    }

    while(!elements.empty())
    {
        int top = elements.top();
        elements.pop();
        cout<<char(top+97)<<" ";
    }
    cout<<endl;
}