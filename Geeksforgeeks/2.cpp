#include <bits/stdc++.h>
using namespace std;

// dijkastra's algorithim to find and print the shortest path,

int find_min(vector<int> &path, vector<bool> &visited)
{
    int i;

    int min_path = INT_MAX;
    int size = path.size();
    int newSource = 0;

    for(i = 0; i < size; i++)
    {
        if(path[i] < min_path && !visited[i])
        {
            min_path = path[i];
            newSource = i;
        }
    }

    return newSource;
}

void print_path(vector<int> &parent, int node, int source)
{
    while(node != source)
    {
        cout<<node;
        node = parent[node];
    }
    cout<<source<<endl;
}

int main()
{
    int nodes = 4,edges = 5;
    vector<vector<pair<int,int>>> graph(nodes);
    int i;

    for(i = 0; i < edges; i++)
    {
        int source,dest,weight;
        cin>>source>>dest>>weight;

        graph[source].push_back({dest,weight});
    }

    // an array to keep track of visited elements
    vector<bool> visited(nodes);
    vector<int> path(nodes,INT_MAX);

    vector<int> parent(nodes);
    int source = 0;

    path[source] = 0;
    parent[source] = source;

    // for(i = 0; i < nodes-1; i++)
    // {
    //     visited[source] = 1;

    //     vector<pair<int,int>>::iterator it;

    //     for(it = graph[source].begin(); it != graph[source].end(); it++)
    //     {
    //         int dest = it->first;
    //         int weight = it->second;

    //         int dist = path[source]+weight;

    //         if(path[dest] > dist)
    //         {
    //             path[dest] = dist;
    //             parent[dest] = source;
    //         }
    //     }

    //     // source = find_min(path,visited);
    // }

    stack<int> sources;
    sources.push(source);

    while(!sources.empty())
    {
        int source = sources.top();
        sources.pop();
        visited[source] = 1;

        vector<pair<int,int>>::iterator it;

        for(it = graph[source].begin(); it != graph[source].end(); it++)
        {
            int dest = it->first;
            int weight = it->second;
            if(!visited[dest])
            {
                sources.push(dest);
            }

            int dist = path[source]+weight;

            if(path[dest] > dist)
            {
                path[dest] = dist;
                parent[dest] = source;
            }
        }
    }

    source = 0;
    for(i = 0; i < nodes; i++)
    {
        // cout<<"path to "<<i<<" is ";
        // print_path(parent,i,source);
        cout<<"Min path from 0 to "<<i<<" is "<<path[i]<<endl;
    }
    // cout<<path[4]<<endl;
}