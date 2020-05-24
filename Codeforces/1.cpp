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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
	int n,a,r,m;
	cin>>n>>a>>r>>m;
	int sum = 0;
	vector<int> arr(n);
	for(int &it : arr)cin>>it,sum+=it;
	int mh = *min_element(all(arr));
	int mxh = *max_element(all(arr));
	int mincost = INT_MAX;
	f(height,mh,mxh+1)
	{
		int cost = 0;
		int optotal = height*n;
		if(optotal > sum)
		{
			cost+=(optotal-sum)*a;
			cost-=(optotal-sum)*m;
		}
		else if(sum > optotal)
		{
			cost+=(sum-optotal)*r;
			cost-=(sum-optotal)*m;
		}
		f(i,0,n)
		{
			cost+=abs(arr[i]-height)*m;
		}
		mincost = min(mincost,cost);
	}
	cout<<mincost<<endl;
    return 0;
}