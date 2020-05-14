#include<iostream>
#include<vector>
 
using namespace std;
 
const int N = 2e5 + 10;
 
vector <int> v1[N],v2[N];
 
int vis1[N],vis2[N];
 
bool dfs1(int x)
{
	vis1[x] = -1;
	for(auto a : v1[x])
	{
		if(vis1[a] < 0) return 0;
		else if(!vis1[a]&&!dfs1(a)) return 0;
	}
	vis1[x] = 1;
	return 1;
}
 
bool dfs2(int x)
{
	vis2[x] = -1;
	for(auto a : v2[x])
	{
		if(vis2[a] < 0) return 0;
		else if(!vis2[a]&&!dfs2(a)) return 0;
	}
	vis2[x] = 1;
	return 1;
}
 
int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		int a,b;
		cin>>a>>b;
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	
	string ans;
	int cnt=0;
	for(int i=1; i<=n; i++)
	{
		if(!vis1[i]&&!vis2[i]) ans += 'A',cnt++;
		else ans += 'E';
		if(!dfs1(i) || !dfs2(i))
		{
			puts("-1");
			return 0;
		}
	}
	cout<<cnt<<endl<<ans<<endl;
	return 0;
}