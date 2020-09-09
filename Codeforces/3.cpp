#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf int t;scanf("%d", &t);while (t--)
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
int mod = 1000000007;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

inline void solve()
{
    // all the code goes here
    test
    {
        int n;cin>>n;
        vector<int> a(n);
        read(a);
        sort(all(a),greater<int>());
        vector<bool> vis(n,0);
        vector<int> res;
        vis[0] = 1;
        int g = a[0];
		res.pb(a[0]);
        while(size(res) != n)
        {
			int mx;
			int mi;
			int mxv = 0;
			f(j,0,n)
			{
				if(!vis[j] && gcd(g,a[j]) > mxv)
				{
					mxv = gcd(g,a[j]);
					mx = a[j];
					mi = j;
				}
			}
			res.pb(mx);
			vis[mi] = 1;
			g = gcd(g,mx);
        }
        f(i,0,n)
            cout<<res[i]<<" ";
        cout<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        fh;
    #endif
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}