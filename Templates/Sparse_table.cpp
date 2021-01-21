#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
template<typename T>
void read(vector<T> &a);

class Sparse_table
{
    vector<int> a;
    int n,k;
    vector<vector<int>> table;
    void make()
    {
        for(int i = 0; i < n; i++)
            table[i][0] = a[i];
        for(int j = 1; j < k; j++)
            for(int i = 0; i+(1<<j) <= n; i++)
                table[i][j] = func(table[i][j-1],table[i+(1<<(j-1))][j-1]);
    }
    int func(int a, int b)
    {
        return min(a,b);
    }
    public:
    Sparse_table(vector<int> &_a)
    {
        a = _a;
        n = a.size();
        k = 25;
        table.resize(n,vector<int>(k));
        make();
    }

    int access(int l,int r)
    {
        int res = LLONG_MAX;
        for(int i = k; i >= 0; i--)
        {
            if((1<<i) <= r-l+1)
            {
                res = func(res,table[l][i]);
                l+=(1<<i);
            }
        }
        return res;
    }
};

inline void solve()
{
    // all the code goes here
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