#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define testf int t; scanf("%d",&t); while(t--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define size(container) (int)container.size()
#define int long long int
int n;
const int MX = 2e5+1;
int a[MX],l[MX],r[MX];

void solve()
{
    l[0] = 1;
    r[n-1] = 1;
    int ans = 0;
    f(i,1,n)
    {
        if(a[i] > a[i-1])
            l[i]+=l[i-1]+1;
        else
        {
            l[i] = 1;
        }
        ans = max(ans,l[i]);
    }

    fr(i,n-2,0)
    {
        if(a[i] < a[i+1])
            r[i]+=r[i+1]+1;
        else
        {
            r[i] = 1;
        }
    }

    f(i,1,n-1)
    {
        if(a[i+1] > a[i-1])
            ans = max(ans,l[i-1]+r[i+1]);
    }
    cout<<ans<<NL;
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // clock_t st = clock();
    // all the code goes here
    cin>>n;
    f(i,0,n)
        cin>>a[i];
    solve();
    // cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}