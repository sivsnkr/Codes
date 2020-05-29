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
int n,m,a,b;
void solve()
{
	if(n*a != m*b)
	{
		cout<<"NO"<<NL;
		return;
	}
	vector<string> st;
	string s = "";
	f(i,0,m)
		s+='1';
	vector<int> rc(n,m);
	vector<int> cc(m,n);
	f(i,0,n)
	{
		st.push_back(s);
	}
	f(i,0,n)
		f(j,0,m)
		{
			cout<<rc[i]<<" "<<cc[j]<<endl;
			if(rc[i] > a && cc[j] > b)
			{
				st[i][j] = '0';
				rc[i]--,cc[j]--;
			}
		}
	cout<<"YES"<<NL;
	f(i,0,n)
		cout<<st[i]<<NL;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
	test
	{
		cin>>n>>m>>a>>b;
		solve();
	}
    return 0;
}