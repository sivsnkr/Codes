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

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    vector<int> a(n);
    read(a);
    int neg = 0,mx = 0,pos = 0;
    f(i,0,n)
    {
        if(a[i] >= 0)
            a[i] = -a[i]-1;
        if(a[i] < 0)
            neg++;
        if(abs(a[i]) > mx)
        {
            mx = abs(a[i]);
            pos = i;
        }
    }

    if(neg%2)
    {
        a[pos] = -a[pos]-1;
    }
    f(i,0,n)
        cout<<a[i]<<" \n"[i==n-1];
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