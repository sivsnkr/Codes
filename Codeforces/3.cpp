#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf        \
	int t;           \
	scanf("%d", &t); \
	while (t--)
#define test  \
	int t;    \
	cin >> t; \
	while (t--)
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int

string s;
void solve()
{
	test
	{
		cin >> s;
		int minle = LLONG_MAX;
		int n = s.length();
		int freq[3] = {0};
		int j = 0;
		f(i, 0, n)
		{
			freq[s[i] - '1']++;
			while (freq[s[j] - '1'] > 1)
			{
				freq[s[j++] - '1']--;
			}
			if (*min_element(freq, freq + 3) > 0)
				minle = min(minle, (i - j + 1));
		}
		if (minle == LLONG_MAX)
			cout << 0 << NL;
		else
			cout << minle << NL;
	}
	return;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// all the code goes here
	solve();
	fflush(stdin);
	fflush(stdout);
	return 0;
}