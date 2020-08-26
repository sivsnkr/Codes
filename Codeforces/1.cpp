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
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

int s,w;
int p,f;

inline void solve()
{
    // all the code goes here
    test
    {
		int p,f,cnt_s,cnt_w,s,w;
		cin>>p>>f>>cnt_s>>cnt_w>>s>>w;
		if(s>w)swap(s,w),swap(cnt_s,cnt_w);
		int ans=0;
		for(int i=0;i<=cnt_s;i++){
			if(i*s>p)break;
			int k=min(cnt_s-i,f/s);
			ans=max(ans,i+k+min((p-i*s)/w+(f-k*s)/w,cnt_w));
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
        fh;
    #endif
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}