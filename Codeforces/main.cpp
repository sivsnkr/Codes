#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define int long long

inline void solve()
{
    int n;cin>>n;
    vector<int> a(n+1),b(n+1);

    for(int i = 1; i <= n; i++)cin>>a[i];
    for(int i = 1; i <= n; i++)cin>>b[i];

    vector<vector<int>> dp(n+1,vector<int>(n+2,0));

    for(int i = 1; i <= n; i++){
        int val = 0;
        for(int j = n; j >= i; j--){
            val += a[i+j]*b[j];
            dp[i][j] = val;
        }
    }

    int res = 0;
    vector<int> dpf(n+2,0),dpb(n+2,0);
    for(int i = 1; i <= n; i++)
        dpf[i] += dpf[i-1] + a[i]*b[i];

    for(int i = 1; i <= n; i++)
        dpb[i] += dpb[i-1] + a[i]*b[i];


    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int val = dpf[i-1]+dpb[j+1];
            val += dp[i][i]-dp[i][j+1];

            res = max(res,val);
        }
    }

    cout<<res<<NL;
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
    while(t--){
        solve();
    }
    #ifdef LOCAL
        auto execution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        cout<<"Execution time : "<<execution_time()*1000<<" ms"<<NL;
    #endif
    return 0;
}
