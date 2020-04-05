#include <bits/stdc++.h>
using namespace std;
// input
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 7 6 1
// 7 8 7
// 2 3 7
// 2 5 4
// 6 5 2
// 3 4 9
// 3 5 14
// 5 4 10
// 2 8 2
// 8 6 6

int main()
{
	int nodes = 9, edges = 14;
	vector<vector<pair<int, int>>> graph(nodes);

	vector<vector<bool>> taken(nodes, vector<bool>(nodes, false));
	vector<bool> nodeIncluded(nodes, false);
	int i;
	for (i = 0; i < edges; i++)
	{
		int src, dest, weight;
		cin >> src >> dest >> weight;
		graph[src].push_back({dest, weight});
		graph[dest].push_back({src, weight});
	}

	set<tuple<int, int, int>> included;

	vector<unordered_set<int>> mst(nodes);
	// find min edge

	tuple<int, int, int> minEdge;
	int min = INT_MAX;
	for (i = 0; i < nodes; i++)
	{
		int size = graph[i].size();
		for (int j = 0; j < size; j++)
		{
			if (graph[i][j].second < min)
			{
				min = graph[i][j].second;
				minEdge = {graph[i][j].second, i, graph[i][j].first};
			}
		}
	}

	taken[get<1>(minEdge)][get<2>(minEdge)] = true;
	taken[get<2>(minEdge)][get<1>(minEdge)] = true;
	nodeIncluded[get<1>(minEdge)] = true;
	nodeIncluded[get<2>(minEdge)] = true;

	mst[get<1>(minEdge)].insert(get<2>(minEdge));
	// this counter is for keeping the number of node included in mst
	// and initialized with 2 because we are including 2 node at first
	int counter = 2;
	while (counter < nodes)
	{
		// insert all the new edges to priority queue
		// all the edges connected to src
		int size = graph[get<1>(minEdge)].size();
		for (i = 0; i < size; i++)
		{
			included.insert({graph[get<1>(minEdge)][i].second, get<1>(minEdge), graph[get<1>(minEdge)][i].first});
		}

		// all the edge from dest
		size = graph[get<2>(minEdge)].size();
		for (i = 0; i < size; i++)
		{
			included.insert({graph[get<2>(minEdge)][i].second, get<2>(minEdge), graph[get<2>(minEdge)][i].first});
		}

		while (1)
		{
			minEdge = *(included.begin());
			if (!nodeIncluded[get<2>(minEdge)] || !nodeIncluded[get<1>(minEdge)])
				break;
			included.erase(included.begin());
		}
		taken[get<1>(minEdge)][get<2>(minEdge)] = true;
		taken[get<2>(minEdge)][get<1>(minEdge)] = true;
		nodeIncluded[get<2>(minEdge)] = true;
		nodeIncluded[get<1>(minEdge)] = true;
		mst[get<1>(minEdge)].insert(get<2>(minEdge));
		counter++;
	}

	int l = 0;
	for (i = 0; i < nodes; i++)
	{
		cout << l << " ";
		int size = mst[i].size();
		for (auto j = mst[i].begin(); j != mst[i].end(); j++)
		{
			cout << *j << " ";
		}
		l++;
		cout << endl;
	}
}