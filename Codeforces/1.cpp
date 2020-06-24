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
string s;
int a[51];
void solve()
{
    test
    {
        cin >> s;
        cin >> n;
        f(i, 0, n) cin >> a[i];
        vector<bool> v(n, 0);
        priority_queue<char> pq;
        f(i, 0, s.length())
        {
            pq.push(s[i]);
        }
        char t[n + 1];
        f(k, 0, n)
        {
            f(i, 0, n)
            {
                if (a[i] == 0 && !v[i])
                {
                    v[i] = 1;
                    t[i] = pq.top();
                    pq.pop();
                    f(j, 0, n)
                    {
                        if (a[j] - abs(i - j) >= 0)
                            a[j] -= abs(i - j);
                    }
                }
            }
        }
        f(i, 0, n)
                cout
            << t[i];
        cout << NL;
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