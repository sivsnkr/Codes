#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, unordered_set<int>> &graph, vector<bool> &visited, int src)
{
    visited[src] = true;

    unordered_set<int>::iterator it;
    for (it = graph[src].begin(); it != graph[src].end(); it++)
    {
        if (!visited[*it])
            dfs(graph, visited, *it);
    }
}

void insert(unordered_map<int, unordered_set<int>> &graph, int src, int dest)
{
    if (graph.find(src) != graph.end())
    {
        graph[src].insert(dest);
    }
    else
    {
        unordered_set<int> temp;
        temp.insert(dest);
        graph.insert({src, temp});
    }
}

int main()
{
    int n;
    cin >> n;

    int n1;
    cin >> n1;

    unordered_map<int, unordered_set<int>> graph(n);

    int i;
    for (i = 0; i < n1; i++)
    {
        int src, dest;
        cin >> src >> dest;
        insert(graph, src, dest);
        insert(graph, dest, src);
    }

    vector<bool> visited(n);

    int roots = 0;

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            roots++;
            dfs(graph, visited, i);
        }
    }

    cout << roots << endl;
}