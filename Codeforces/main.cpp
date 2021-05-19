#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

inline void solve()
{
    LL n;cin>>n;
    vector<int> a(3),b(3);
    for(int i = 0; i < 3; i++)cin>>a[i];
    for(int i = 0; i < 3; i++)cin>>b[i];

    LL mx = min(a[2],b[0])+min(a[0],b[1])+min(a[1],b[2]);

    vector<int> ac = a,bc = b;

    ac[0] -= min(a[0],b[2]),bc[2] -= min(a[0],b[2]);
    ac[1] -= min(a[1],b[0]),bc[0] -= min(a[1],b[0]);
    ac[2] -= min(a[2],b[1]),bc[1] -= min(a[2],b[1]);

    
}

int32_t main()
{
    clock_t startTime;
    startTime = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    #ifdef LOCAL
        auto execution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        cout<<"Execution time : "<<execution_time()*1000<<" ms"<<NL;
    #endif
    return 0;
}
