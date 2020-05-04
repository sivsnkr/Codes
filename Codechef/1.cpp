#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

ll give_new_range(ll x, ll y, ll l, ll r)
{
    ll o = x|y;
    int count = 0;
    ll zc = o;
    while(zc != 0)
    {
        zc = zc>>1;
        count++;
    }

    while(count > 0)
    {
        if(o<=r)
            break;
        o &=~(ll(1)<<(count-1));
        count--;
    }
    return o;
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
        printf("%lld\n", z);
        t--;
    }
    return 0;
}