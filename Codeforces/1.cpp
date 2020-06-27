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
bool is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;
    return true;
}

int n;
void solve()
{
    test
    {
        cin>>n;
        bool win = n==1;
        if(n > 2 && n%2 == 0)
        {
            if((n&(n-1)) == 0)
            {
                win = 1;
            }
            else if(n%4 != 0 && is_prime(n/2))
            {
                win = 1;
            }
        }
        if(win)
            cout<<"FastestFinger";
        else
        {
            cout<<"Ashishgup";
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