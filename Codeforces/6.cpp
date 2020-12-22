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

class Isit
{
    public:
    bool ispoweroftwo(int n)
    {
        if((n&(n-1)) == 0)
            return true;
        return false;
    }
    bool is_prime(int n)
    {
        if(n == 1)
            return false;
        for(int i = 2; i*i <= n; i++)
            if(n%i == 0)
                return false;

        return true;
    }
    bool is_plaindrome(string s)
    {
        int st = 0,e = s.length()-1;
        while(st < e)
        {
            if(s[st] != s[e])
                return false;
            st++,e--;
        }
        return true;
    }
};

const int mod = 1e9+7;
inline void solve()
{
    // all the code goes here

    class Isit st;
    cout<<st.is_prime(7367)<<endl;
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