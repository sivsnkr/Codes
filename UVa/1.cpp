#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test
    {
        int a, b, c;
        cin >> a >> b >> c;
        f(i, 0, 101)
            f(j, 0, 101)
                f(k, 0, 101)
        {
            if (i + j + k == a && i * j * k == b && (i * i + j * j + k * k) == c)
            {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    }
    return 0;
}