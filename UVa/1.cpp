#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int nbits(ll n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        n = n>>1;
    }
    return count;
}

ll fg(int k)
{
    ll re = k^(k>>1);
    return re;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    // given kth gray code, find the k

    ll kth_gray = 13;
    int bits = nbits(kth_gray);
    ll k = 0;

    for(int i = bits; i >0; i--)
    {
        if(i == bits)
        {
            if(kth_gray&(ll(1)<<(i-1)))
            {
                k|=(ll(1)<<(bits-1));
            }
        }
        else
        {
            if(!((kth_gray&(ll(1)<<(i-1)))&&(k&(ll(1)<<i))))
            {
                k|=(ll(1)<<(i-1));
            }
        }    
    }
    printf("%lld\n",k);
    ll gcode = fg(k);
    if(gcode == kth_gray)
    {
        puts("True");
    }
    else
    {
        puts("False");
    }
    
    return 0;
}