#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]

inline void solve()
{
    test{
        int n;cin>>n;
        vector<int> a(n);
        read(a);

        if(n <= 2 || *min_element(all(a)) == 0){
            cout<<0<<NL;
            continue;
        }

        int mx = *max_element(all(a));
        int c = -1;
        for(int i = 1; i < n; i++){
            if(a[i] < mx && a[i-1] < mx && a[i] >= a[i-1]){
                c = a[i]-a[i-1];
                break;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
