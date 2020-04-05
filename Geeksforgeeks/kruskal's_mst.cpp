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

int find(vector<int> root, int node)
{
	if (root[node] == node)
		return node;
	return find(root, root[node]);
}

int main()
{
	int edges = 14, nodes = 9;

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> graph;

	int i;
	for (i = 0; i < edges; i++)
	{
		int src, dest, weight;
		cin >> src >> dest >> weight;
		graph.push({weight, src, dest});
	}

	vector<unordered_set<int>> mst(nodes);
	vector<int> root(nodes);
	iota(root.begin(), root.end(), 0);
	int nodesCounter = 0;
	while (!graph.empty())
	{
		int src, dest;
		auto top = graph.top();
		src = get<1>(top);
		dest = get<2>(top);

		graph.pop();
		int root1 = find(root, src);
		int root2 = find(root, dest);
		if (root1 != root2)
		{
			mst[src].insert(dest);
		}
		// take union
		root[root2] = root1;
	}

	for (i = 0; i < nodes; i++)
	{
		cout << i << " ";
		for (auto j = mst[i].begin(); j != mst[i].end(); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}