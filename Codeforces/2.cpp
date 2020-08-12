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
void readarray(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

void solve()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    long long n,l,r;
	cin>>n>>l>>r;
	// long long a[n][3];
    vector<vector<int>> a(n,vector<int>(3,0));
	a[0][0]=r/3-(l-1)/3;
	a[0][1]=(r+2)/3-(l+1)/3;
	a[0][2]=(r+1)/3-l/3;
	
	for (int i=1;i<n;i++)
		for (int j1=0;j1<3;j1++)
			for (int j2=0;j2<3;j2++)
				a[i][(j1+j2)%3]=(a[i][(j1+j2)%3] + a[i-1][j1]*a[0][j2]) % 1000000007;
		
	cout<<a[n-1][0];
    // fh;// comment this line before submitting to online judge
    // all the code goes here
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}