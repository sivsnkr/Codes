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
// #define int LL
#define int long double
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
vector<pair<int,int>> a;

bool good(int m)
{
    // cout<<"m "<<m<<NL;
    vector<int> re(n);
    f(i,0,n)
    {
        auto [x,y] = a[i];
        re[i] = x-m*y;
    }
    sort(all(re),greater<int>());
    int sum = 0;
    f(i,0,k)
        sum+=re[i];
    // cout<<"sum "<<sum<<NL;
    return sum >= 0;
}

inline void solve()
{
    // all the code goes here
    cin>>n>>k;
    f(i,0,n)
    {
        int x,y;cin>>x>>y;
        a.emplace_back(x,y);
    }

    int ans = 0,l = 0,r = 1e11;
    f(i,0,100)
    {
        // cout<<l<<" "<<r<<NL;
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
    cout<<setprecision(20)<<ans<<NL;
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