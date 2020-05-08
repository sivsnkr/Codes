#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

ll give_new_range(ll x, ll y, ll l, ll r)
{
    ll o = x|y;
    int count1 = 0;
    ll rc = r;
    while(rc!= 0)
    {
        count1++;
        rc = rc>>1;
    }
    ll z = 0;
    ll m = -1;
    ll res = z;
    for(int i = count1-1; i >=0; i--)
    {
        if(o&(ll(1)<<i))
        {
            ll zc = z;
            zc |= (ll(1)<<i);
            if(zc >= l && zc <= r)
            {
                z = zc;
                if((x&z)*(y&z) >= m)
                {
                    m = (x&z)*(y&z);
                    res = z;
                }
            }
            else if(zc > r)
            {
                int c = 0;
                ll zcc = zc;
                while(zcc != 0)
                {
                    c++;
                    zcc = zcc>>1;
                }
                zc = zc&((ll(1)<<(c-1))-1);
                if(zc >= l && zc <= r)
                {
                    z = zc;
                    if((x&z)*(y&z) >= m)
                    {
                        m = (x&z)*(y&z);
                        res = z;
                    }
                }
            }
        }
    }
    if(m == 0)
        return l;
    return res;
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