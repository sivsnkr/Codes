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
#define pb push_back
#define int LL
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
int n,k;
vector<int> a;

bool good(int m)
{
    int total = m*k;
    f(i,0,n)
        total-=min(m,a[i]);
    return total<=0;
}

inline void solve()
{
    // all the code goes here
    cin>>k>>n;
    a.resize(n);
    read(a);
    int ans = 0,l = 0,r = 1e11;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(good(m))
        {
            ans = m;
            l = m+1;
        }
        else
        {
            r = m-1;
        }
    }
    cout<<ans<<NL;
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