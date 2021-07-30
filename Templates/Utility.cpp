#include <bits/stdc++.h>
using namespace std;

class Utility
{
    public:
    int pow(int a, int b,int mod)
    {
        int res = 1;
        while (b > 0)
        {
            if (b & 1){
                res *= a;
                res %= mod;
            }
            a = a * a;
            a %= mod;
            b >>= 1;
        }
        return res;
    }

    void mod(int &a, int p)
    {
        a%=p;
        while(a < 0)a+=p;
    }

    int mod_inverse(int a,int m)
    {
        int res = pow(a,m-2,m);
        mod(res,m);
        return res;
    }
};
inline void solve()
{
    // all the code goes here
    class Utility st;
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
