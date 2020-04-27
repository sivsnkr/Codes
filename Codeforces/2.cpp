#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    ll n,b;
    cin>>n>>b;

    ll count = 0;
    for(ll i = 2; i*i <= b; i++)
    {
        if(b%i == 0)
        {
            ll c = b/i;
            for(ll j = 1; j*c < b && j*c <= n; j++)
            {
                if(c*j != i)
                    count++;
            }   
        }
    }
    // cout<<count<<"\n";
    for(ll i = 1; i*b <= n; i++)
    {
        ll t = i*b;
        while(t%b == 0)
        {
            count++;
            t/=b;
        }
    }

    cout<<count<<"\n";
    return 0;
}