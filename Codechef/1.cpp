#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';
ll give_new_range(ll x, ll y, ll l, ll r)
{
    ll m = max(x, y);
    int nofbits = 0;
    ll re;
    while (m >= 2)
    {
        re = m % 2;
        m /= 2;
        nofbits++;
    }
    if (re > 0)
        nofbits++;
    printf("bits %d\n", nofbits);
    ll z = 0;
    while (z <= r && nofbits > 0)
    {
        z |= (1 << nofbits - 1);
        nofbits--;
    }
    printf("z %lld\n", z);
    return z;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int t;
    scanf("%d", &t);
    while (t > 0)
    {
        ll x, y, l, r;
        scanf("%lld%lld%lld%lld", &x, &y, &l, &r);
        ll z = give_new_range(x, y, l, r);
        // ll m = 0, z = l;
        // for (int i = min(r, range.second); i >= max(l, range.first); i--)
        // {
        //     if ((x & i) * (y & i) >= m)
        //     {
        //         m = (x & i) * (y & i);
        //         z = i;
        //     }
        // }
        printf("%lld\n", z);
        t--;
    }
    return 0;
}