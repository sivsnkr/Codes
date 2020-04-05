#include <bits/stdc++.h>
using namespace std;

int main()
{
    int max_dist = 2; // max weight of any edge
    int nodes = 4; // number of nodes
    int edges = 7;
    vector<set<pair<int,int>>> graph(nodes);
    int i;
    for(i = 0; i < edges; i++)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        graph[src].insert({dest,weight});
    }
    vector<set<int>> bucket(max_dist*nodes);
    vector<int> weights(nodes,0);
    vector<int> parent(nodes);
    parent[0] = 0;

    bucket[0].insert(0);

    for(i = 0; i < nodes*max_dist; i++)
    {
        if(bucket[i].size() > 0)
        {
            set<int>::iterator it;

            for(it = bucket[i].begin(); it != bucket[i].end(); it++)
            {
                int src = *it;

                if(weights[src] == 0)
                    weights[src] = i;
                else 
                    continue;
                set<pair<int,int>>::iterator it1;

                for(it1 = graph[src].begin(); it1 != graph[src].end(); it1++)
                {
                    int dest = it1->first;
                    int weight = it1->second;

                    bucket[weight+i].insert(dest);
                    parent[dest] = src;
                }
            }
        }
    }

    for(i = 0; i < nodes; i++)
    {
        cout<<"weight of "<<i<<" is "<<weights[i]<<endl;
    }
}