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

inline void solve()
{
    // let's code
    int n;cin>>n;
    vector<int> a(2*n);
    read(a);
    sort(all(a));
    int diff = 0,res = 0;
    for(int i = n; i < 2*n; i++)
    {
        if(i == n)
        {
            diff = a[i]-a[i-1];
            res+= n*n*diff;
        }
        else
        {
            int lres = (i-n)*diff + a[i]-a[2*n-i-1] + (i-n)*(a[i]-a[i-1]);
            res += n*n*lres;
            diff = lres;
        }
    }

    for(int i = n-1; i >= 0; i--)
    {
        if(i == n-1)
        {
            diff = a[i+1]-a[i];
            // res += n*n*diff;
        }
        else
        {
            int lres = (n-1-i)*diff + a[n+n-i-1]-a[i] + (n-1-i)*(a[i+1]-a[i]);
            res += n*n*lres;
            // diff+=a[n+n-i-1]-a[i];
            diff = lres;
        }
    }

    if(n == 1)
        res/=2;
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
