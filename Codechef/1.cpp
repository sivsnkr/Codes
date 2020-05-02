#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

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
        ll num = (ll(1)<<62)-ll(1);
        for(int i = 62; i >= 0; i--)
        {
            if(num>=l&&num<=r)
                break;
            num &= ~(ll(1)<<i);
        }
        printf("%lld\n",num);
        t--;
    }
    return 0;
}