#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

ll solve(ll x, ll y, ll L, ll r)
{
    // find common sequence
    int k = 42;
    while((r&(ll(1)<<k))==(L&(ll(1)<<k)))
    {
        k--;
    }
    ll o = x|y;
    ll res = 0;
    ll z = LLONG_MAX;
    for(int m = k-1; m >= 0; m--)
    {
        if(r&(ll(1)<<m))
        {
            ll temp = r&(~(ll(1)<<m));
            for(int j = m-1; j >= 0; j--)
            {
                if(o&(ll(1)<<j))
                {
                    temp|=ll(1<<j);
                }
            }
            if((x&temp)*(y&temp) >= res)
            {
                res = (x&temp)*(y&temp);
                z = min(z,temp);
            }
        }
    }

    for(int m = k-1; m >= 0; m--)
    {
        if(!(L&(ll(1)<<m)))
        {
            ll temp = (ll(1)<<m);
            for(int j = m-1; j >= 0; j--)
            {
                if(o&(ll(1)<<j))
                {
                    temp|=(ll(1)<<j);
                }
            }

            if((x&temp)*(y&temp) >= res)
            {
                res = (x&temp)*(y&temp);
                z = min(z,temp);
            }
        }
    }

    if(z == LLONG_MAX)
        return L;
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int t;
    scanf("%d",&t);
    while(t > 0)
    {
        ll x,y,l,r;
        scanf("%lld%lld%lld%lld",&x,&y,&l,&r);
        ll res = solve(x,y,l,r);
        printf("%lld\n",res);
        t--;
    }
    return 0;
}