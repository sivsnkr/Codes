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
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(a[1]-a[0]);

    for(int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
    }

    cout<<dp[n-1]<<"\n";

    return 0;
}