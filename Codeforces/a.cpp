#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
template<typename T>
void read(vector<T> &a);

inline void solve()
{
    // all the code goes here
    test
    {
        int n,m;cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin>>a[i][j];


        vector<vector<bool>> res(n,vector<bool>(m,0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                bool dirty = 0;
                int mx = 0;
                if(i-1 >= 0)
                {
                    if(a[i-1][j] > a[i][j])
                    {
                        mx = max(mx,a[i-1][j]);
                        dirty = 1;
                    }
                    if(j-1 >= 0 && a[i-1][j-1] > a[i][j])
                    {
                        mx = max(mx,a[i-1][j-1]);
                        dirty = 1;
                    }
                    if(j+1 < n && a[i-1][j+1] > a[i][j])
                    {
                        mx = max(mx,a[i-1][j+1]);
                        dirty = 1;
                    }
                }
                if(!dirty)
                    res[i][j] = 1;
                a[i][j] = max(a[i][j],mx);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cout<<res[i][j];
            cout<<NL;
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}