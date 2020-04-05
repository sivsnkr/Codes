#include <bits/stdc++.h>
using namespace std;

// programme for nth catalan number based on binomial cofficient
// in o(n) time

// formula is catalan(n) = (1/(n+1))(2n n);
int ncn(int n,int c)
{
	if(c > n-c)
		c = n-c;
	long long int res = 1;
	for(int i = 0; i < c; i++)
	{
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

int main()
{
	for(int i = 0; i < 10; i++)
	{
		int res = ncn(2*i,i);
		res/=(i+1);
		cout<<res<<" ";
	}
	cout<<endl;
}