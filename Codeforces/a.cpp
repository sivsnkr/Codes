#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int i = 0; i < size(a); i++)cin>>a[i]

inline void solve()
{
    // let's code
    int n;cin>>n;
    // LL k;cin>>k;
    vector<LL> a(n);
    read(a);


    int l = 0;
    int mx = 1e7;
    int g = 0;
    for(int i = 0; i < n; i++)
    {
        g = gcd(g,a[i]);
        cout<<"val "<<g<<NL;
        while(gcd(a[l+1],a[i]) == 1 && g == 1)
        {
            l++;
        }
        if(g == 1)
            mx = min(mx,i-l+1);
    }

    if(mx == 1e7)
            mx = -1;
    cout<<mx<<NL;
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
