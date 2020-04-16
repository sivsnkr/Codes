#include <bits/stdc++.h>
using namespace std;

int maxv(vector<pair<int, int>> &items, int w, int n, map<pair<int, int>, int> &me)
{
    if (w == 0 || n == 0)
        return 0;
    if (me.find({n, w}) != me.end())
        return me[{n, w}];
    if (items[n - 1].first <= w)
        return me[{n, w}] = max(items[n - 1].second + maxv(items, w - items[n - 1].first, n - 1, me), maxv(items, w, n - 1, me));
    return me[{n, w}] = maxv(items, w, n - 1, me);
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> items(n);
    for (auto &a : items)
    {
        cin >> a.first >> a.second;
    }

    map<pair<int, int>, int> me;
    maxv(items, w, n, me);
    cout << me[{n, w}] << "\n";

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