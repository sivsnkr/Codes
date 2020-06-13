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
int n,m,x;

void solve()
{
    int mi = x,mx = x;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        if(b < mi || a > mx)
            continue;
        mi = min(mi,a);
        mx = max(mx,b);
    }

    cout<<mx-mi+1<<NL;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // clock_t st = clock();
    // all the code goes here
    test
    {
        cin>>n>>x>>m;
        solve();
    }
    // cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}