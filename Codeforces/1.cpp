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

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    vector<int> a(n);
    read(a);
    int co = 0;
    int mx = a[0];
    vector<tuple<int,int,int>> res;
    f(i,1,n)
    {
        if(a[i] <= mx)
        {
            co++;
            res.pb({1,i+1,mx+1-a[i]});
            a[i] = mx+1;
        }
        mx = max(a[i],mx);
    }
    cout<<size(res)<<NL;
    f(i,0,size(res))
        cout<<get<0>(res[i])<<" "<<get<1>(res[i])<<" "<<get<2>(res[i])<<NL;
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