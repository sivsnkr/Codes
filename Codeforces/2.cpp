#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
void read(vector<int> &a);
map<int,int> freq;
int mxf;
bool good(int m)
{
	if(m <= freq.size()-1)
	{
		for(auto [val,count] : freq)
		{
			if(count < )
		}
	}
	return false;
}
inline void solve()
{
    // all the code goes here
	test
	{
		int n;cin>>n;
		vector<int> a(n);
		read(a);
		int mx = 0;
		for(int i = 0; i < n; i++)
		{
			freq[a[i]]++;
			if(freq[a[i]] > mx)
			{
				mx = freq[a[i]];
				mxf = a[i];
			}
		}
		int l = 0,r = n-2;
		int ans = 0;
		while(l <= r)
		{
			int m = (l+r)/2;
			if(good(m))
			{
				ans = m;
				l = m+1;
			}
			else
				r = m-1;
		}
		cout<<ans<<NL;
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