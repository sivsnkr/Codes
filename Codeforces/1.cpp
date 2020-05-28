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

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<string> st(n);
	f(i,0,n)
		cin>>st[i];
	string ans = st[0];
	f(i,0,m)
	{
		char save = ans[i];
		for(char c = 'a'; c <= 'z'; c++)
		{
			ans[i] = c;
			bool isans = true;
			f(j,0,n)
			{
				int error = 0;
				f(l,0,m)
				{
					if(ans[l] != st[j][l])
						error++;
				}
				if(error > 1)
				{
					isans = false;
					break;
				}
			}
			if(isans)
			{
				cout<<ans<<endl;
				return;
			}
		}
		ans[i] = save;
	}
	cout<<-1<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
	test
	{
		solve();
	}
    return 0;
}