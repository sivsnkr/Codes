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
map<int,int> a;
int prices[1001];

bool hc(int price)
{
    if(price == 0)
        return true;
    if(price >= 10)
    {
        if(a[10] > 0)
        {
            a[10]--;
            return true;
        }
        if(a[5] > 1)
        {
            a[5]-=2;
            return true;
        }
    }
    if(a[5] > 0)
    {
        a[5]--;
        return true;
    }
    return false;
}

void solve()
{
    test
    {
        a.clear();
        cin>>n;
        bool valid = true;
        f(i,0,n)
        {
            cin>>prices[i];
            if(!hc(prices[i]-5))
            {
                cout<<"NO";
                valid = false;
                break;
            }
            a[prices[i]]++;
        }
        if(valid)
            cout<<"YES";
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