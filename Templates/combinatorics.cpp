#include <bits/stdc++.h>
using namespace std;

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

class Combinatorics
{
    public:
    vector<int> derangements(int n)
    {
        vector<int> der(n+1,0);
        der[1] = 0;
        der[2] = 1;
        for (int i = 3; i <= n; ++i)
            der[i] = (i - 1) * (der[i - 1] + der[i - 2]);
        return der; // der[n] will be the answer
    }
};


inline void solve()
{
    // all the code goes here
    class Combinatorics st;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
