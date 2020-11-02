#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
void read(vector<int> &a);

const int MX = 2e5+5;
vector<vector<int>> g(MX);
vector<bool> vis(MX);
vector<pair<int,int>> cost;
int sum;
int dfs(int root, int len, int par)
{
	if(vis[root])
		sum+=len;
	int size = 0;
	for(int i : g[root])
	{
		if(i != par)
			size = max(size,dfs(i,len+(vis[root]?0:1),root));
	}
	cost.emplace_back(len-size,root);
	return size+1;
}

inline void solve()
{
    // all the code goes here
	int n,k;cin>>n>>k;
	for(int i = 0; i < n-1; i++)
	{
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0,1);
	sort(all(cost),greater<pair<int,int>>());
	int i = 0;
	while(k--)
	{
		vis[cost[i].second] = 1;
		i++;
	}
	sum = 0;
	dfs(1,0,1);
	cout<<sum<<NL;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}