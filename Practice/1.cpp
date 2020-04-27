#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int n;
float cd(pair<int,int> a, pair<int,int> b)
{
	int d = pow(abs(a.first-b.first),2)+pow(abs(a.second-b.second),2);
	return float(sqrt(d));
}

int find(int src[],int node)
{
	if(src[node] == node)
		return node;
	return find(src,src[node]);
}

float minspanningtreesum(vector<tuple<int,int,float>> &graph)
{
	int src[n];
	iota(src,src+n,0);
	priority_queue<tuple<float,int,int>,vector<tuple<float,int,int>>,greater<tuple<float,int,int>>>pg;
	for(tuple<int,int,float> a : graph)
	{
		pg.push({get<2>(a),get<0>(a),get<1>(a)});
	}

	float sum = 0;
	while(!pg.empty())
	{
		tuple<float,int,int> temp = pg.top();
		pg.pop();
		int sourc = get<1>(temp);
		int dest = get<2>(temp);
		int root1 = find(src,sourc);
		int root2 = find(src,dest);
		if(root1 != root2)
		{
			sum+=get<0>(temp);
			src[root1] = root2;
		}
	}

	return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
	cin>>n;

	vector<pair<int,int>> co(n);
	for(int i = 0; i < n; i++)
		cin>>co[i].first>>co[i].second;

	vector<tuple<int,int,float>> graph;

	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			float td = cd(co[i],co[j]);
			graph.push_back({i,j,td});
		}
	}

	// kruskal's minimum spanning tree algo

	float d = minspanningtreesum(graph);
	cout<<d<<nl;

    return 0;
}