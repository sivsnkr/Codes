#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

inline void solve()
{
    // let's code
    test{
        int n,u,r,d,l;cin>>n>>u>>r>>d>>l;

        bool valid = 1;

        if(u > n-1)
        {
            if(l == 0 || r == 0)
                valid = 0;
            if(r > 0)
               r--;
            if(l > 0)
                l--;
            u-=2;
        }

        if(r > n-1)
        {
            if(u == 0 || d == 0)
                valid = 0;
            if(u > 0)
                u--;
            if(d > 0)
                d--;
            r-=2;
        }

        if(d > n-1)
        {
            if(l == 0 || r == 0)
                valid = 0;
            if(r > 0)
                r--;
            if(l > 0)
                l--;
            d-=2;
        }

        if(l > n-1)
        {
            if(u == 0 || d == 0)
                valid = 0;
            if(u > 0)
                u--;
            if(d > 0)
                d--;
            l-=2;
        }

        if(u > n-2)
        {
            if(r > 0)
                r--;
            else if(l > 0)
                l--;
            else
                valid = 0;
            u--;
        }
        if(l > n-2)
        {
            if(u > 0)
                u--;
            else if(d > 0)
                d--;
            else
                valid = 0;
            l--;
        }

        if(r > n-2)
        {
            if(u > 0)
                u--;
            else if(d > 0)
                d--;
            else
                valid = 0;
            r--;
        }
        if(d > n-2)
        {
            if(l > 0)
                l--;
            else if(r > 0)
                r--;
            else
                valid = 0;
            d--;
        }

        if(!valid)
            cout<<"NO";
        else
            cout<<"YES";
        cout<<NL;
    }
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
