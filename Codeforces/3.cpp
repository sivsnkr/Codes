#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max 300005
vector<int>v[max];
int red[max],blu[max],color[max];
int tred=0,tblu=0;
int ans=0;

void dfs_color(int u, int prev)
{
		if(color[u]==1) { red[u]=1; tred++; }
		if(color[u]==2) { blu[u]=1; tblu++; }
		
		
		for(int i=0; i<v[u].size(); i++)
		{
			int nei=v[u][i];
			if(nei==prev) continue;
			dfs_color(nei,u);
			red[u]+=red[nei]; blu[u]+=blu[nei];
		}
}

void dfs_edge(int u, int prev)
{
	for(int i=0; i<v[u].size(); i++)
	{
		int nei=v[u][i];
		if(nei==prev) continue;
		if((red[nei]==tred and blu[nei]==0) or (red[nei]==0 and blu[nei]==tblu) )  ans++;
		dfs_edge(nei,u);
	}
}

int main()
{
	int n; cin>>n; 
	for(int i=1; i<=n; i++) cin>>color[i];
	
	int l,r;
	for(int i=1; i<n; i++)
	{
		cin>>l>>r;
		v[l].push_back(r); v[r].push_back(l);
	}
	
	dfs_color(1,0); dfs_edge(1,0);
	cout<<ans<<"\n";  
	
}