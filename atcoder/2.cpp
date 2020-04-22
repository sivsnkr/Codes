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

    vector<int> a(n);
    for(int &i : a)
    {
        cin>>i;
    }

    int dp[n];
    memset(dp,0,sizeof(dp));

    ll sum = 0;
    dp[0] = 0;dp[1] = a[0]+a[1];

    for(int i = 2; i < n; i++)
    {
        dp[i] = min(a[i]+a[i-1],dp[i-1]+a[i]);
    }

    for(int a : dp)
        cout<<a<<" ";
    cout<<"\n";

    return 0;
}