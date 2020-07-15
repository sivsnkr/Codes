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

void solve()
{
    test
    {
        int n,a,b;cin>>n>>a>>b;
        int s = 0;
        string res = "";
        int l = a;
        int d = b;
        int c = -1;
        while(n > 0)
        {
            while(l > 0 && n > 0)
            {
                if(s > 0 && res[s] != res[s-1])
                    d = 1;
                else if(s > 0)
                    d = 0;
                // cout<<s<<" "<<d<<NL;
                while(d > 0 && l > 0 && n > 0)
                {
                    c = (c+1)%26;
                    res+=(char)(c+97);
                    d--,l--,n--;
                }
                if(l > 0)
                {
                    res+=(char)(c+97);
                    l--,n--;
                }
            }
            // cout<<"l "<<n<<NL;
            l = 1;
            s++;
        }
        cout<<res<<NL;
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