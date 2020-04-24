#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n;cin>>n;
    int k;cin>>k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    vector<int> dp(n,INT_MAX);
    // cout<<dp[n-1]<<"\n";
    dp[0] = 0;
    dp[1] = abs(a[1]-a[0]);

    for(int i = 2; i < n; i++)
    {
        // cout<<dp[i]<<"\n";
        for(int j = 1; j <= min(k,i); j++)
            dp[i] = min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
        // cout<<dp[i]<<"\n";
    }

    cout<<dp[n-1]<<"\n";

    return 0;
}