#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    test
	{
		int n;cin>>n;
		int res = 4*n;
		vector<int> val;
		vector<int> is_prime(res+1,0);
		vector<int> primelist;
		for(int i = 2; i <= res; i++)
		{
			if(is_prime[i] == 0)
			{
				is_prime[i] = i;
				primelist.push_back(i);
			}
			for(int j = 0; j < primelist.size()&&i*primelist[j]<=res&&primelist[j]<=is_prime[i]; j++)
			{
				is_prime[i*primelist[j]] = primelist[j];
			}
		}

		for(int i = 2; i <= res; i++)
		{
			if(is_prime[i] == i)
			{
				val.push_back(i);
			}
		}
		int i = 0;
		while(n--)
		{
			cout<<val[i]<<" ";
			i++;
		}
		cout<<NL;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}