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
int n,k;
string s;
void solve()
{
    test
    {
        cin>>n>>k;
        cin>>s;
        int c = 0;
        vector<int> pos(n);
        int p = INT_MAX;
        fr(i,n-1,0)
        {
            if(s[i] == '1')
                p = i;
            pos[i] = p;
        }
        int l = -INT_MAX;
        f(i,0,n)
        {
            if(s[i] == '1')
                l = i;
            else
            {
                if(i-l > k && pos[i]-i > k)
                {
                    l = i;
                    c++;
                }
            }
        }
        cout<<c<<NL;
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