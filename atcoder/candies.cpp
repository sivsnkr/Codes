#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

l mod = 1e9+7;
void add_self(int &a, int b)
{
    a+=b;
    a%=mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n,k;cin>>n>>k;

    int dp[k+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;

    for(int child = 0; child < n; child++)
    {
        int upto;cin>>upto;
        for(int used = k; used >= 0; used--)
        {
            for(int here = 1; here <= min(upto,k-used); here++)
            {
                add_self(dp[used+here],dp[used]);
            }
        }
    }

    cout<<dp[k]<<"\n";
    return 0;
}