#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n,w;cin>>n>>w;

    vector<pair<int,int>> items(n);
    for(int i = 0; i < n; i++)
        cin>>items[i].first>>items[i].second;

    l dp[n+1][w+1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(items[i-1].first > j)
                dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = max(items[i-1].second+dp[i-1][j-items[i-1].first],dp[i-1][j]);
            }
        }
    }

    cout<<dp[n][w]<<"\n";

    return 0;
}