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
int n,x;
int a[100001];
void solve()
{
    test
    {
        cin>>n>>x;
        int l=-1,r=n-1;
        int sum = 0;
        f(i,0,n)
        {
            cin>>a[i];
            sum+=a[i];
            if(a[i]%x)
            {
                if(l == -1)
                    l = i;
                r = i;
            }
        }
        if(sum%x)
        {
            cout<<n;
        }
        else if(l == -1)
        {
            cout<<-1;
        }
        else
        {
            cout<<n-min(l+1,n-r);
        }
        cout<<NL;
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