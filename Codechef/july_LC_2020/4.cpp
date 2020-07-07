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
map<int,int> x,y;
void solve()
{
    test
    {
        y.clear();
        x.clear();
        cin>>n;
        f(i,0,4*n-1)
        {
            int xp,yp;
            cin>>xp>>yp;
            x[xp]++,y[yp]++;
        }
        int xp,yp;
        for(pair<int,int> a : x)
            if(a.second%2 != 0)
            {
                xp = a.first;
                break;
            }
        for(pair<int,int> a : y)
            if(a.second%2 != 0)
            {
                yp = a.first;
                break;
            }
        cout<<xp<<" "<<yp<<NL;      
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