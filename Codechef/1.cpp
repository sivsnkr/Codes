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
vector<pair<string, string>> st(101);
int getp(string st)
{
    int sum = 0;
    for (char c : st)
    {
        sum += (c - 48);
    }
    return sum;
}
void solve()
{
    test
    {
        cin >> n;
        f(i, 0, n) cin >> st[i].first >> st[i].second;
        int c = 0, m = 0;
        f(i, 0, n)
        {
            int p = getp(st[i].first);
            int p1 = getp(st[i].second);
        }
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