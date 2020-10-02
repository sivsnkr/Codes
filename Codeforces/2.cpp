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

int n;
vector<int> a;

bool good(int m)
{
    vector<pair<int,int>> res;
    f(i,0,n)
    {
        if(a[i] == -1)
        {
            if(i-1 >= 0 && a[i-1] != -1)
            {
                res.pb({a[i-1]-m,a[i-1]+m});
            }
            if(i+1 < n && a[i+1] != -1)
            {
                res.pb({a[i+1]-m,a[i+1]+m});
            }
        }
    }
    int l = 0,r = 1e9;
    for(auto [f,s] : res)
    {
        l = max(l,f);
        r = min(r,s);
    }
    bool ret = r >= l;
    f(i,0,n-1)
    {
        if(a[i] != -1 && a[i+1] != -1)
        {
            if(abs(a[i]-a[i+1]) > m)
                return false;
        }
    }
    return ret;
}

inline void solve()
{
    // all the code goes here
    test
    {
        cin>>n;
        a.resize(n);
        read(a);
        int l = 0,r = 1e9,ans = 0;
        while(l <= r)
        {
            int m = (l+r)/2;
            if(good(m))
            {
                ans = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        vector<pair<int,int>> res;
        int m = ans;
        f(i,0,n)
        {
            if(a[i] == -1)
            {
                if(i-1 >= 0 && a[i-1] != -1)
                {
                    res.pb({a[i-1]-m,a[i-1]+m});
                }
                if(i+1 < n && a[i+1] != -1)
                {
                    res.pb({a[i+1]-m,a[i+1]+m});
                }
            }
        }
        l = 0,r = 1e9;
        for(auto [f,s] : res)
        {
            l = max(l,f);
            r = min(r,s);
        }
        if(r >= l)
        {
            cout<<ans<<" "<<l;
        }
        else
        {
            cout<<-1;
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
        fh;
    #endif
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}