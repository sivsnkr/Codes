#include <bits/stdc++.h>
using namespace std;
int k,a,b;
string s;
int main()
{
	int n;
	cin>>k>>a>>b;
	cin>>s;
	n = s.length();
 
	int c,d;
	c = n/k;
	d = n%k;
	if(c < a) cout<<"No solution";
	else if(c > b || (c == b && d > 0)) cout<<"No solution";
	else 
	{
		for(int i=0;i<n;i++)
		{
			cout<<s[i];
			if((i+1) % c == 0 && (i+1) != k*c ) cout<<endl;
		}
	}
}