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
const int MX = 1e15;
int n,x;
void solve()
{
    test
    {
        cin>>n>>x;
        vector<int> a(n);
        f(i,0,n)cin>>a[i];
        sort(all(a));
        vector<int> dp(n,MX);
        dp[n-1] = 0;
        f(i,0,n-1)
        {
            int md = 0;
            int cx = a[i];
            if(cx >= a[i+1])
                md++;
            while(cx < a[i+1])
            {
                cx*=2;
                md++;
            }
            dp[i] = md;
        }
        fr(i,n-2,0)
            dp[i]+=dp[i+1];
        int supplies = x;
        int mind = LLONG_MAX;
        int ds = 1;
        while(supplies < a[n-1])
        {
            int in = lower_bound(all(a),supplies)-a.begin();
            if(supplies >= a[in])
                mind = min(mind,ds+dp[in]+in);
            else if(in > 0)
                mind = min(mind,ds+dp[in-1]+in-1);
            supplies*=2;
            ds++;
        }
        mind = min(mind,ds+n-1);
        cout<<mind<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // clock_t st = clock();
    // all the code goes here
    solve();
    // cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}