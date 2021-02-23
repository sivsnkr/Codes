#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]
#define int long long
const int mod = 998244353;

void modv(int &a, int p)
{
    a%=p;
    while(a >= p)a-=p;
    while(a < 0)a+=p;
}

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
    // let's code
    int n;cin>>n;
    vector<int> a(2*n);
    read(a);
    sort(all(a));
    int res = 0;
    for(int i = n; i < 2*n; i++)
    {
        res += a[i];
        modv(res,mod);
    }

    for(int i = 0; i < n; i++)
    {
        res -= a[i];
        modv(res,mod);
    }

    class NCR st(2*n,n,mod);
    res = res * st.ncr(2*n,n,mod);
    res %= mod;
    cout<<res<<NL;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
