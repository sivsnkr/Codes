#include <bits/stdc++.h>
using namespace std;

const long int p = 1000000007;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int dp[n + 1][n + 1];
		memset(dp, 0, sizeof(dp));
		int i, j;
		for (i = 0; i <= n; i++)
			dp[i][0] = 1;
		for (i = 0; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (i == j)
				{
					dp[i][j] = 1;
				}
				else if (j > i)
					break;
				else
					dp[i][j] = (dp[i - 1][j] % p + dp[i - 1][j - 1] % p) % p;
			}
		}

		long long int sum = 0;
		for (i = 0; i <= n; i++)
		{
			long long int po = pow(dp[n][i], 2);
			sum = (sum + po % p) % p;
		}
		cout << sum << endl;
	}
}