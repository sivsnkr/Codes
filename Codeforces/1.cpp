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
    cin>>n;
    set<int> r;
    f(i,0,n+1)
        r.insert(i);
    f(i,0,n)
    {
        cin>>a[i];
        if(r.find(a[i]) != r.end())
            r.erase(a[i]);
    }
    vector<int> res(n,-1);
    f(i,1,n)
    {
        if(a[i] != a[i-1])
        {
            res[i] = a[i-1];
            if(r.find(a[i-1]) != r.end())
                r.erase(res[i]);
        }
    }
    f(i,0,n)
        if(res[i] == -1)
        {
            res[i] = *r.begin();
            r.erase(r.begin());
        }
    for(int it : res)
        cout<<it<<" ";
    cout<<NL;
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