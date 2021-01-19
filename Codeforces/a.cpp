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
        for(int j = 1; j < k; j++)
            for(int i = 0; i+(1<<j) <= n; i++)
                table[i][j] = func(table[i][j-1],table[i+(1<<(j-1))][j-1]);
    }
    int func(int a, int b)
    {
        return max(a,b);
    }

    int access(int l,int r)
    {
        int res = LLONG_MIN;
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
        int m;cin>>m;
        vector<int> b(m);
        vector<int> end(n+1,0);
        f(i,0,m)
        {
            int po,en;cin>>po>>en;
            b[i] = po;
            end[en] = max(end[en],po);
        }
        if(*max_element(all(a)) > *max_element(all(b)))
        {
            cout<<-1<<NL;
            continue;
        }

        fr(i,n-1,1)
        {
            end[i] = max(end[i],end[i+1]);
        }

        int i = 0;
        int days = 0;
        while(i < n)
        {
            int j = i;
            while(j < n && st.access(i,j) <= end[j-i+1])
                j++;
            i = j;
            days++;
        }
        cout<<days<<NL;
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