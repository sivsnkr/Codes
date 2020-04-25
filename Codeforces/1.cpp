#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n;cin>>n;ll k;cin>>k;
    n--;

    ll le = 1;
    unordered_map<ll,int> s;
    int it  = 2;
    while(n-- && le < k)
    {
        s[le+1] = it;
        it++;
        le = 2*le+1;
    }

    while(true)
    {
        ll m = 0;
        for(pair<ll,int> a : s)
        {
            if(k-a.first >= 0)
            {
                m = max(m,a.first);
            }
        }

        if(m == k)
        {
            cout<<s[m]<<"\n";
            return 0;
        }
        k -= m;
        if(k < 0 || m == 0)
        {
            cout<<1<<"\n";
            return 0;
        }
    }
    

    return 0;
}