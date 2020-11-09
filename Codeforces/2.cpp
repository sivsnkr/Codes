#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
void read(vector<int> &a);

const int MX = 1e5+5;
int n,minn = 1e9+5,cx,cy;
vector<int> g[MX],sizes(MX),fa(MX);

void dfs(int r, int p)
{
	fa[r] = p;
	sizes[r] = 1;
	int mx = 0;
	for(int x : g[r])
	{
		if(x == p)
			continue;
		dfs(x,r);
		sizes[r]+=sizes[x];
		mx = max(mx,sizes[x]);
	}
	mx = max(mx,n-sizes[r]);
	// cout<<"r mx "<<r<<" "<<mx<<NL;
	if(minn > mx)
	{
		minn = mx,cx = r;
		cy = -1;
	}
	else if(mx == minn)
		cy = r;
}

int S;
void dfs2(int r, int p)
{
	if(g[r].size() == 1)
	{
		S = r;
		return;
	}
	for(int x : g[r])
	{
		if(x ==  p)
			continue;
		dfs2(x,r);
	}
}
inline void solve()
{
    // all the code goes here
	test
	{
		cin>>n;
		sizes.assign(n+1,0),minn = 1e9+5,cx = -1,cy = -1,fa.assign(n+1,0);
		for(int i = 0; i <= n; i++)
			g[i].clear();
		for(int i = 0; i < n-1; i++)
		{
			int x,y;cin>>x>>y;
			g[x].push_back(y),g[y].push_back(x);
		}

		dfs(1,0);
		// cout<<cx<<" "<<cy<<NL;
		if(cy == -1)
		{
			cout<<1<<" "<<g[1][0]<<NL;
			cout<<1<<" "<<g[1][0]<<NL;
		}
		else
		{
			if(fa[cy] != cx)
				swap(cx,cy);
			dfs2(cy,cx);
			cout<<S<<" "<<fa[S]<<NL;
			cout<<cx<<" "<<S<<NL;
		}
	}
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