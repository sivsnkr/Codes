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
    int k;cin>>k;
    vector<int> a(n);
    read(a);


    int l = 0;
    LL res = 0;
    map<int,int> st;
    for(int i = 0; i < n; i++)
    {
        st[a[i]]++;
        while(size(st) > k)
        {
            st[a[l]]--;
            if(st[a[l]] == 0)
                st.erase(a[l]);
            l++;
        }
        res += (i-l+1);
    }
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
