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
    int n;cin>>n;
    vector<int> a(n);
    read(a);
    sort(all(a));
    int l = 0,r = n+1;
    while(r-l > 1)
    {
        int m = (l+r)/2;
        bool valid = 1;
        if(2*m+1 > n)
            valid = 0;
        else
        {
            vector<int> res;
            int a_pos = 0,b_pos = n-1-m;
            f(i,0,2*m+1)
            {
                if(i%2)
                {
                    res.pb(a[a_pos]);
                    a_pos++;
                }
                else
                {
                    res.pb(a[b_pos]);
                    b_pos++;
                }
            }
            for(int i = 1; i < 2*m+1; i+=2)
            {
                if(res[i] >= res[i-1] || res[i] >= res[i+1])
                {
                    valid = 0;
                    break;
                }
            }
        }
        if(!valid)
            r = m;
        else
            l = m;
    }
    cout<<l<<NL;
    vector<int> res;
    int a_pos = 0,b_pos = n-1-l;
    f(i,0,2*l+1)
    {
        if(i%2)
        {
            res.pb(a[a_pos]);
            a_pos++;
        }
        else
        {
            res.pb(a[b_pos]);
            b_pos++;
        }
    }
    f(i,a_pos,n-l-1)
        res.pb(a[i]);
    f(i,0,size(res))
        cout<<res[i]<<" \n"[i==size(res)-1];
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