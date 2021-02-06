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
        int res = 1e9;
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
    test
    {
        int n;cin>>n;
        vector<int> a(n);
        read(a);
        class Sparse_table st(a);

        int l = 0,r = n-1;
        int in = -1;
        for(int i = 0; i < n; i++)
        {
            bool found = 0,valid = 1;
            if(a[l] == i+1)
            {
                found = 1;
                l++;
            }
            if(a[r] == i+1)
            {
                found = 1;
                r--;
            }
            if(st.access(l,r) != i+2)
                valid = 0;
            if(!found || !valid)
            {
                in = i;
            }
        }

        string res = "";
        
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
    cout<<setprecision(20);
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