#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

bool isp(ll a)
{
    string s = to_string(a);
    int l = 0,r = s.length()-1;
    while(l < r)
    {
        if(s[l] != s[r])
            return false;
        l++,r--;
    }
    return true;
}

ll rev(ll a)
{
    string s = to_string(a);
    reverse(s.begin(),s.end());
    ll res = stoll(s);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        int maxc = 1000;
        while(maxc-- && n <= 4294967295)
        {
            n+=rev(n);
            if(isp(n))
                break;
        }
        printf("%d %lld\n",1000-maxc,n);
    }

    return 0;
}