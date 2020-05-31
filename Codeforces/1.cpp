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

int decimalToBinary(int N) 
{ 
  
    // To store the binary number 
    int B_Number = 0; 
    int cnt = 0; 
    while (N != 0) { 
        int rem = N % 2; 
        int c = pow(10, cnt); 
        B_Number += rem * c; 
        N /= 2; 
  
        // Count used to store exponent value 
        cnt++; 
    } 
  
    return B_Number; 
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
	int mid = ls/2;
	f(i,0,n)
	{
		if(length%2 == 0)
		{
			if(st[i] <= mid)
				mid++;
		}else
		{
			if(st[i] >= mid)
				mid--;
		}
		length--;
	}
	cout<<decimalToBinary(mid)<<endl;
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