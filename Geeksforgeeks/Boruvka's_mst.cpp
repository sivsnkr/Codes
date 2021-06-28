#include<bits/stdc++.h>
using namespace std;

int find(vector<pair<int,int>> &root,int node)
{
    if(root[node].first == node)
        return node;
    return find(root,root[node].first);
}

void merge_set(vector<pair<int,int>> &root, int set1, int set2)
{
    if(root[set1].second > root[set2].second)
        root[set2].first = set1;
    else if(root[set1].second < root[set2].second)
        root[set1].first = set2;
    else
    {
        root[set2].first = set1;
        root[set1].second++;
    }  
}

// input
// 0 3 5
// 0 1 10
// 0 2 6
// 1 3 15
// 2 3 4
int main()
{
    int nodes = 4,edges = 5;
    vector<tuple<int,int,int>> graph(edges);
    int i;

    for(i = 0; i < edges; i++)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        graph[i] = {src,dest,weight};
    }

    vector<pair<int,int>> root(nodes);
    for(i = 0; i < nodes; i++)
    {
        // parent and rank respectively
        root[i] = {i,0};
    }

    int subsets = nodes;
    int minweight = 0;

    while(subsets > 1)
    {
        // distance and dest respectively
        vector<pair<int,int>> minDistancefromSubset(nodes,{-1,-1});

        for(auto edge : graph)
        {
            int src = get<0>(edge),dest = get<1>(edge),weight = get<2>(edge);

            int set1 = find(root,src);
            int set2 = find(root,dest);

            if(set1 == set2)
                continue;
            if(minDistancefromSubset[src].first == -1 || minDistancefromSubset[src].first > weight)
                minDistancefromSubset[src] = {weight,dest};
            if(minDistancefromSubset[dest].first == -1 || minDistancefromSubset[dest].first > weight)
                minDistancefromSubset[dest] = {weight,src};
        }

        for(i = 0; i < nodes; i++)
        {
            if(minDistancefromSubset[i].first != -1)
            {
                int src = i,dest = minDistancefromSubset[i].second;
                int set1 = find(root,src);
                int set2 = find(root,dest);

                if(set1 == set2)
                    continue;
                minweight+=minDistancefromSubset[i].first;
                merge_set(root,set1,set2);
                subsets--;
            }
        }
    }

    cout<<minweight<<endl;
}