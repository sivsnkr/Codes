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
    int dp[n][3];
    int m[n][3];
    for(int i = 0; i< n; i++){
        for(int j = 0; j< 3; j++)
        {
            cin>>m[i][j];
            dp[i][j] = 0;
        }
    }


    
    // dp[0] = *max_element(m[0],m[0]+3);
    for(int i = 0; i < 3; i++)
    {
        dp[0][i] = m[0][i];
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(j != k)
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][k]+m[i][j]);
                }
            }
        }
    }

    cout<<*max_element(dp[n-1],dp[n-1]+3)<<"\n";
    return 0;
}