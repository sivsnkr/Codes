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
    string s;cin>>s;
    string a = "";
    int n = s.length();
    f(i,0,n)
    {
        if(s[i] == 'a' || s[i] == 'b')
            a+=s[i];
    }
    int r = 1;
    int k = 0;
    n = a.length();
    f(i,0,n)
    {
        if(a[i] == 'a')
        {
            k++;
        }
        else
        {
            r*=(k+1);
            r%=mod;
            k = 0;
        }
    }
    if(k > 0)
    {
        r*=(k+1);
            r%=mod;
            k = 0;
    }
    r-=1;
    cout<<r<<NL;
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