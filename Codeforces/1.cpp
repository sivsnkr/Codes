#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define testf int t; scanf("%d",&t); while(t--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define size(container) (int)container.size()
#define int long long int

vector<int> sums;
vector<int> heights;
int n,a,r,m;

int solve(int height)
{
	int h = upper_bound(heights.begin(), heights.end(), height) - heights.begin();
	int p = height*h - sums[h-1];
	int q = sums[n-1]-sums[h-1]-height*(n-h);
	int cost = LLONG_MAX;
	if(p >= q)
	{
		int tcost = (p-q)*a+q*m;
		cost = min(tcost,cost);
	}
	if(q >= p)
	{
		int tcost = (q-p)*r+p*m;
		cost = min(cost,tcost);
	}
	return cost;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
	cin>>n>>a>>r>>m;
	m = min(m,a+r);
	heights.assign(n,0);
	f(i,0,n)cin>>heights[i];
	sort(all(heights));
	sums.assign(n,0);
	sums[0] = heights[0];
	f(i,1,n)
	{
		sums[i] = sums[i-1]+heights[i];
	}

	int ans = solve(sums[n-1]/n);
	ans = min(ans,solve((sums[n-1])/n+1));

	f(i,0,n)
	{
		ans = min(ans,solve(heights[i]));
	}

	cout<<ans<<endl;
    return 0;
}