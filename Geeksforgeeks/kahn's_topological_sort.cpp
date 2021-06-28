#include<bits/stdc++.h>
using namespace std;

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

    vector<int> indegree(nodes,0);
    queue<int> elements;
    
    for(i = 0; i < nodes; i++)
    {
        for(auto j = graph[i].begin(); j != graph[i].end(); j++)
        {
            indegree[*j]++;
        }
    }

    // push all indegree to queue
    for(i = 0; i < nodes; i++)
    {
        if(indegree[i] == 0)
        {
            elements.push(i);
        }
    }

    while(!elements.empty())
    {
        // print top element in queue and decrease there 
        // child indegree by 1
        int top = elements.front();
        elements.pop();
        for(int j : graph[top])
        {
            indegree[j]--;
            if(indegree[j] == 0)
            {
                elements.push(j);
            }
        }

        cout<<top<<" ";
    }
    cout<<endl;
}