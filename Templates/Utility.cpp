#include <bits/stdc++.h>
using namespace std;

class Utility
{
    public:
    int pow(int a, int b)
    {
        int res = 1;
        while (b > 0)
        {
            if (b & 1)
                res *= a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

    int mod(int a, int p)
    {
        a%=p;
        while(a >= p)a-=p;
        while(a < 0)a+=p;
        return a;
    }

    int mod_inverse(int a,int m)
    {
        int res = pow(a,m-2);
        res = mod(res,m);
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
