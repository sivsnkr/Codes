#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<unordered_set<int>> &graph, vector<bool> &visited, set<int> &cycle)
{
    visited[src] = 1;
    unordered_set<int>::iterator it;

    for(it = graph[src].begin(); it != graph[src].end(); it++)
    {
        if(visited[*it])
            cycle.insert(*it);
        else
        {
            dfs(*it,graph,visited,cycle);
        }
    }
}

void getnodes(int src, vector<unordered_set<int>> &graph, vector<bool> &visited, int &noofnodes)
{
    visited[src] = true;
    unordered_set<int>::iterator it;

    for(it = graph[src].begin(); it != graph[src].end(); it++)
    {
        if(!visited[src])
        {
            noofnodes++;
            getnodes(*it,graph,visited,noofnodes);
        }
    }
}

int power(int x, unsigned int y, unsigned int m) 
{ 
    if (y == 0) 
        return 1; 
    int p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}

int modInverse(int a, int m) 
{ 
    return power(a, m-2, m);
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    nodes++;
    vector<unordered_set<int>> graph(nodes);

    int i;
    for(i  = 0; i < edges; i++)
    {
        int src, dest; 
        cin>>src>>dest;
        graph[src].insert(dest);
    }

    vector<bool> visited(nodes,0);
    set<int> cycle;
    vector<int> cyclenodes;
    dfs(1,graph,visited,cycle);

    for(auto i : cycle)
    {
        cyclenodes.push_back(i);
    }
    int noofedges = cycle.size()-1;

    if(edges == 0)
        cout<<0<<" "<<0<<endl;
    else
    {
        int a = 0,b = 0;
        for(i = 0; i <= noofedges; i++)
        {
            for(int j = i+1; j <= noofedges; j++)
            {
                // get nodes in parnet
                graph[cyclenodes[i]].erase(cyclenodes[j]);
                int parentnodes,childnodes;
                vector<bool> visited(noofedges,false);
                getnodes(i,graph,visited,parentnodes);
                visited.assign(noofedges,false);
                getnodes(j,graph,visited,childnodes);
                if(parentnodes == childnodes)
                {
                    if(parentnodes % 2 == 0)
                    {
                        a++;
                    }
                }
                else
                {
                    b++;
                }
                graph[cyclenodes[i]].insert(cyclenodes[j]);
            }
        }

        int c = 1000000007;
        int totalinverse = modInverse(noofedges,c);
        totalinverse = (totalinverse%c);
        a = ((a%c)*totalinverse)%c;
        b = ((b%c)*totalinverse)%c;
        cout<<a<<" "<<b<<endl;
    }
}