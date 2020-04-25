#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    // all the code goes here
    string a,b;cin>>a>>b;
 
    vector<vector<tuple<int,int,int>>> dp(a.length()+1,vector<tuple<int,int,int>>(b.length()+1,make_tuple(0,-1,-1)));
 
    int n = a.length(),m = b.length();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i] == b[j])
            {
                if(get<0>(dp[i+1][j+1]) < get<0>(dp[i][j])+1)
                {
                    dp[i+1][j+1] = make_tuple(get<0>(dp[i][j])+1,i,j);
                }
            }
            if(get<0>(dp[i+1][j]) < get<0>(dp[i][j]))
            {
                dp[i+1][j] = dp[i][j];
            }
            if(get<0>(dp[i][j+1]) < get<0>(dp[i][j]))
            {
                dp[i][j+1] = dp[i][j];
            }
        }
    }
 
    pair<int,int> in = {-1,-1};
    int mv = 0;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(mv < get<0>(dp[i][j]))
            {
                mv = get<0>(dp[i][j]);
                in = make_pair(get<1>(dp[i][j]),get<2>(dp[i][j]));
            }
        }
    }
 
    string res = "";
    while(in.first != -1 && in.second != -1)
    {
        res+=a[in.first];
        in = make_pair(get<1>(dp[in.first][in.second]),get<2>(dp[in.first][in.second]));
    }
 
    reverse(res.begin(),res.end());
    cout<<res<<"\n";
 
    return 0;
}
