#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
template<typename T>
void read(vector<T> &a);

class NCR
{
    // O(n) for big n and r modulo prime p
    vector<int> fact,inv,finv;
    public:
    NCR(int n,int c, int p)
    {
        fact.resize(n+1),inv.resize(n+1),finv.resize(n+1);
        fact[1] = inv[1] = finv[0] = fact[0] = finv[1] = inv[0] = 1;
        for(int i = 2; i <= n; i++)
            fact[i] = i*fact[i-1]%p;
        for(int i = 2; i <= n; i++)
            inv[i] = p-p/i*inv[p%i]%p;
        for(int i = 2; i <= n; i++)
            finv[i] = inv[i]*finv[i-1]%p;
    }
    int ncr(int n,int r,int p)
    {
        if(n < r)
            return 0;
        return fact[n]*finv[r]%p*finv[n-r]%p;
    }
};

inline void solve()
{
    // all the code goes here
    const int mod = 998244353;
    int n,k;cin>>n>>k;
    class NCR st(3e5+5,3e5+5,mod);
    vector<pair<int,int>> pa;
    f(i,0,n)
    {
        int l,r;cin>>l>>r;
        pa.emplace_back(l,1);
        pa.emplace_back(r,-1);
    }
    sort(all(pa),[](pair<int,int> a,pair<int,int> b)->bool{
        if(a.first == b.first)
            return a.second>b.second;
        return a.first < b.first;
    });
    int cnt = 0,res = 0;
    f(i,0,2*n)
    {
        if(pa[i].second > 0)
        {
            res = (res+st.ncr(cnt,k-1,mod))%mod;
        }
        cnt+=pa[i].second;
    }
    cout<<res<<NL;
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