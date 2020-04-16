#include<bits/stdc++.h>
using namespace std;

int maxv(vector<pair<int,int>> &items, int w, int n)
{
    if(w == 0||n == 0)
        return 0;
    else if(items[n-1].first <= w)
        return max(items[n-1].second+maxv(items,w-items[n-1].first,n-1),maxv(items,w,n-1));
    return maxv(items,w,n-1);
}

int main()
{
    int n,w;cin>>n>>w;
    vector<pair<int,int>> items(n);
    for(auto &a : items)
    {
        cin>>a.first>>a.second;
    }

    int m = maxv(items,w,n);
    cout<<m<<"\n";

    // int weight = 0;
    // long long int k[n+1][w+1];
    // for(int i = 0; i <= n; i++)
    // {
    //     for(int j = 0; j <= w; j++)
    //     {
    //         if(i == 0 || j == 0)
    //             k[i][j] = 0;
    //         else if(items[i-1].first <= j)
    //         {
    //             k[i][j] = max(items[i-1].second+k[i-1][j-items[i-1].first], k[i-1][j]);
    //         }
    //         else
    //         {
    //             k[i][j] = k[i-1][j];
    //         }
    //     }
    // }

    // cout<<k[n][w]<<"\n";
}