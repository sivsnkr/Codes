#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    while(true)
    {
        ll n;cin>>n;
        if(!n)
            return 0;
        
        map<ll,ll> pf;

        for(ll i = 2; i*i <= n; i++)
        {
            while(n%i == 0)
            {
                pf[i]++;
                n/=i;
            }
        }

        if(n > 1)
            pf[n]++;

        for(auto it : pf)
        {
            cout<<it.first<<"^"<<it.second<<" ";
        }
        cout<<"\n";
    }

    return 0;
}