#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int src, dest;
        cin >> src >> dest;
        graph[src].insert(dest);
        graph[dest].insert(src);
    }

    vector<int> path;
    set<int> nodes;
    vector<bool> visited(n + 1, false);
    nodes.insert(1);
    while (!nodes.empty())
    {
        int t = *nodes.begin();
        nodes.erase(nodes.begin());
        for (int v : graph[t])
        {
            if (!visited[v])
            {
                nodes.insert(v);
            }
        }
        if (!visited[t])
            path.push_back(t);
        visited[t] = true;
    }

    for (int i : path)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}