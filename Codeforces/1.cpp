#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

void add_self(int &a, int b)
{
	a+=b;
	a%=mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
	int n;
	scanf("%d",&n);
	vector<vector<int>> places(n,vector<int>(2));
	f(i,0,n)
	{
		scanf("%d%d",&places[i][0],&places[i][1]);
	}
	vector<vector<int>> dp(n,vector<int>(2));
	dp[n-1][0] = dp[n-1][1] = 1;
	fr(i,n-2,0)
	{
		f(j,0,2)
		{
			f(k,0,2)
			{
				if(places[i][j] != places[i+1][k])
					add_self(dp[i][j],dp[i+1][k]);
			}
			if(places[i+1][0] == places[i+1][1])
				dp[i][j]/=2;
		}
	}
	printf("%d\n",dp[0][0]+dp[0][1]);
    return 0;
}