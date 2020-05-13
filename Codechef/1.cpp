#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

ll solve(ll x, ll y, ll L, ll r)
{
    ll res = 0;
    ll z = L;
    ll o = x|y;
    int k = 42;
    ll temp = 0;
    for(int i = k; i >= 0; i--)
    {
        if((L&(ll(1)<<i)) != (r&(ll(1)<<i)))
        {
            k = i;
            break;
        }
        temp|=(L&(ll(1)<<i));
    }

    for(int m = k; m >= 0; m--)
    {
        ll ta = temp;
        for(int j = k; j >= m+1; j--)
        {
            if(r&(ll(1)<<j))
                ta|=(ll(1)<<j);
        }

        for(int j = m-1; j >=0; j--)
        {
            if(o&(ll(1)<<j))
                ta|=(ll(1)<<j);
        }
        if(ta >= L && ta <= r)
        {
            if((x&ta)*(y&ta) > res)
            {
                res = (x&ta)*(y&ta);
                z = ta;
            }
            else if((x&ta)*(y&ta) == res)
                z = min(z,ta);
        }
    }

    for(int m = k; m >= 0; m--)
    {
        ll ta = temp;
        for(int j = k; j >= m+1; j--)
        {
            if(L&(ll(1)<<j))
                ta|=(ll(1)<<j);
        }

        ta|=(ll(1)<<m);
        for(int j = m-1; j >=0; j--)
        {
            if(o&(ll(1)<<j))
                ta|=(ll(1)<<j);
        }

        if(ta >= L && ta <= r)
        {
            if((x&ta)*(y&ta) > res)
            {
                res = (x&ta)*(y&ta);
                z = ta;
            }
            else if((x&ta)*(y&ta) == res)
                z = min(z,ta);
        }
    }

    if((x&r)*(y&r) > res)
        return r;

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