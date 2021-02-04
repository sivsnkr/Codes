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

const int mod = 1e9+7;
vector<vector<int>> mul(vector<vector<int>> a,vector<vector<int>> b)
{
    vector<vector<int>> res(2,vector<int>(2,0));
    for(int i = 0; i < 2; i++)
    {
        for(int k = 0; k < 2; k++)
        {
            for(int j = 0; j < 2; j++)
            {
                res[i][j]+=a[i][k]*b[k][j];
                res [i][j] %= mod;
            }
        }
    }

    return res;
}

vector<vector<int>> bin_expo(vector<vector<int>> a, int n)
{
    vector<vector<int>> res({vector<int>({1,0}),vector<int>({0,1})});

    while(n > 0)
    {
        if(n&1)
        {
            res = mul(res,a);
        }
        a = mul(a,a);
        n = n>>1;
    }
    return res;
}

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    // int p;cin>>p;
    vector<vector<int>> prob({vector<int>({0,1}),vector<int>({1,1})});

    prob = bin_expo(prob,n);
    cout<<prob[0][1]<<NL;
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
    cout<<setprecision(10);
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