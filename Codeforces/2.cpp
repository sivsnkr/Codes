#include<bits/stdc++.h>
using namespace std;
const int N = 500043;
const int MOD = 998244353;
int fact[N];

int add(int x, int y)
{
	x += y;
	while(x >= MOD) x -= MOD;
	while(x < 0) x += MOD;
	return x;
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y&1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

int inv(int x)
{
	return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
	return mul(x, inv(y));
}

void precalc()
{
	fact[0] = 1;
	for(int i = 1; i < N; i++)
		fact[i] = mul(i, fact[i - 1]);
}

int C(int n, int k)
{
	if(k > n) return 0;
	return divide(fact[n], mul(fact[n - k], fact[k]));
}

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	precalc();
	for(int i = 1; i <= n; i++)
	{
		int d = n / i;
		ans = add(ans, C(d - 1, k - 1));
	}
	cout << ans << endl;
}