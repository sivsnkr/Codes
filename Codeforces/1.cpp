#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf        \
    int t;           \
    scanf("%d", &t); \
    while (t--)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
int n;
int a[100001];
void solve()
{
    test
    {
        cin>>n;
        f(i,0,n)cin>>a[i];
        int s = 0;
        int sum = 0;
        f(i,1,n)
        {
            if(a[i] < a[i-1])
            {
                if(s > 0)
                {
                    if(a[i]+sum > a[i-1])
                    {
                        int j = 0;
                        while(a[i] < a[i-1])
                        {
                            a[i]+=pow(2,++j-1);
                        }
                    }
                    else
                    {
                        a[i]+=sum;
                    }
                    
                }
                while(a[i] < a[i-1])
                {
                    int p = pow(2,++s-1);
                    a[i]+=p;
                    sum+=p;
                }
            }
        }
        cout<<s<<NL;
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