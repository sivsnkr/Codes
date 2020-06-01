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
#define int long long

string decimalToBinary(int N,int m) 
{
	// cout<<"N "<<N<<endl;
	string res = "";
	while(N != 0)
	{
		res+=(char(N%2)+48);
		// cout<<"res "<<res<<endl;
		N = N>>1;
	}
	while(res.length() < m)
	{
		res = res+'0';
	}
	reverse(all(res));
	return res;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> st(n);
	f(i,0,n)
	{
		string s;
		cin>>s;
		st[i] = stoll(s,0,2);
	}
	sort(all(st));
	int ls = pow(2,m)-1;
	int length = ls+1;
	int mid = (length-n-1)/2;
	f(i,0,n)
	{
		if(st[i] <= mid)
			mid++;
		else
		{
			break;
		}
		
	}
	cout<<decimalToBinary(mid,m)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
	test{
		solve();
	}
    return 0;
}