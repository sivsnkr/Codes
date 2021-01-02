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
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}