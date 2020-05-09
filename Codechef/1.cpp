#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

ll give_new_range(ll x, ll y, ll l, ll r)
{
    if(min(x,y) == 0)
        return l;
    ll o = x|y;
    ll m = 0;
    ll z = 0;
    ll zc = z;
    ll zcc;
    int c = 0;
    ll rc = r;
    ll res = z;
    o|=l;
    int i = 0;
    while(i < 63)
    {
        if(o&(ll(1)<<i))
        {
            z = o&(~(ll(1)<<i));
            if(z < l)
                break;
            if((x&z)*(y&z) == x*y)
            {
                o = z;
            }
        }
        i++;
    }

    for(int i = 62; i >= 0; i--)
    {
        if((r&(ll(1)<<i)) == 0)
        {
            o = o&((ll(1)<<i)-1);
        }else
        {
            break;
        }
    }
    z = o;
    while(z > r)
    {
        zc = z;
        for(int i = 0; i < 63; i++)
        {
            if(z&(ll(1)<<i))
            {
                zcc = z;
                z = z&(~(ll(1)<<i));
                if((x&z)*(y&z) == 0)
                {
                    z = zcc;
                }
                if(z<=r)
                    break;
            }
        }
        m = (x&z)*(y&z);
        c = 0;
        zcc = zc;
        while(zc != 0)
        {
            c++;
            zc = zc>>1;
        }

        zcc = zcc&((ll(1)<<(c-1))-1);
        if((x&zcc)*(y&zcc) >= m || z > r)
        {
            z = zcc;
        }
    }
    if((x&z)*(y&z) == 0)
        return l;
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
        printf("%lld\n", z);
        t--;
    }
    return 0;
}