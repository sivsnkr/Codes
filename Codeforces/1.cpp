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
	test{
		int n;
		cin>>n;
		vector<int> m(n);
		for(int &it : m)cin>>it;
		sort(all(m));
		vector<int> dp(n,0);
		for(int i = 0; i < n; i+=2)
		{
			if(m[i+1]-m[i] == 1)
			{
				dp[i] = -1;
				dp[i+1] = -1;
			}
		}

		f(i,0,n)
		{
			if(dp[i] == 0)
			{
				dp[i] = m[i]%2;
			}
		}

		int onem = 0;
		int one = 0;
		int zero = 0;
		f(i,0,n)
		{
			switch (dp[i])
			{
			case -1:
				onem++;
				break;
			case 0:
				zero++;
				break;
			case 1:
				one++;
				break;
			}
		}

		if(one%2 == 0 && onem%2 == 0 && zero%2 == 0 && one+zero+onem == n)
			cout<<"YES";
		else
		{
			cout<<"NO";
		}
		
		cout<<endl;
	}
    return 0;
}