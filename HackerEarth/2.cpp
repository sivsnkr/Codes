#include<bits/stdc++.h>
using namespace std;

int mind,maxd;
void Dfs(int startNode, unordered_set<int> edgeNode, vector<unordered_set<int>> nodes,unordered_set<int> cities,vector<int> &visited,int d){
    if(visited[startNode])
        return;

    visited[startNode] = 1;

    unordered_set<int>::iterator it;

    int maxDl = 0;

    for(it = nodes[startNode].begin(); it != nodes[startNode].end(); it++){
        if(!visited[*it]){
            Dfs(*it,edgeNode,nodes,cities,visited,d+1);
        }
    }

    if(cities.find(startNode)!=cities.end()){
        // cout<<"startnode d "<<startNode<<" "<<d<<endl;
        maxd = max(maxd,d);
        mind = min(mind,d);
    }
}

int main(){
    int n,q;
    cin>>n>>q;

    vector<unordered_set<int>> nodes(n+1);

    int i;
    for( i = 0; i < n-1; i++){
        int u,v;
        cin>>u>>v;
        nodes[u].insert(v);
        nodes[v].insert(u);
    }

    unordered_set<int> edgeNode;

    for(i = 0; i < n; i++){
        if(nodes[i].size() == 1){
            edgeNode.insert(i);
        }
    }

    for(i = 0; i < q; i++){
        int k;
        cin>>k;
        unordered_set<int> cities,src;

        int j;
        for(j = 0; j < k; j++){
            int t;
            cin>>t;
            cities.insert(t);
        }

        int startNode = *cities.begin();

        vector<int> visited(n,0);

        mind = 1000000,maxd = 0;


        Dfs(startNode,edgeNode,nodes,cities,visited,0);


        // cout<<"startNode "<<startNode<<endl;
        // cout<<"maxd mind "<<maxd<<" "<<mind<<endl;
        int ceilv = ceil(float(maxd-mind)/2);
        int maxdc = ceil(float(maxd)/2);
        int maxv = max(maxdc,ceilv);
        cout<<maxv<<endl;
    }
}