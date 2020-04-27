#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        int k = 2;
        int r = pow(2,k)-1;
        while(r < n+2)
        {
            if(n%r == 0)
            {
                // cout<<k<<nl;
                cout<<n/r<<nl;
                break;
            }
            k++;
            r = pow(2,k)-1;
        }
    }
    
    return 0;
}