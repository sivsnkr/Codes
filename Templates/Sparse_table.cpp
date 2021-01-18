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
    public:
    Sparse_table(vector<int> &_a)
    {
        a = _a;
        n = a.size();
        k = 25;
        table.resize(n,vector<int>(k));
        make();
    }
    void make()
    {
        for(int i = 0; i < n; i++)
            table[i][0] = a[i];
        for(int k = 1; k < 50; k++)
            for(int i = 0; i+(1<<k) <= n; i++)
                table[i][k] = func(table[i][k-1],table[i+(1<<(k-1))][k-1]);
    }
    int func(int a, int b)
    {
        return a+b;
    }

    int access(int l,int r)
    {
        int res = 0;
        for(int i = k; i >= 0; i--)
        {
            if((1<<k) <= r-l+1)
            {
                res+=table[l][k];
                l+=(1<<k);
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