#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

inline void solve()
{
    LL x0,y0,ax,ay,bx,by;cin>>x0>>y0>>ax>>ay>>bx>>by;
    LL xs,ys,t;cin>>xs>>ys>>t;

    vector<pair<LL,LL>> dp;
    while(true){
        LL reqt = abs(x0-xs)+abs(y0-ys);
        if(reqt <= t){
            dp.emplace_back(x0,y0);
        }
        if(x0 >= 1e17 ||  y0 >= 1e17)
            break;
        x0 = x0*ax+bx;
        y0 = y0*ay+by;
    }
    int ans = 0;
    for(int l = 0; l < sz(dp); l++){
        for(int r = l; r < sz(dp); r++){
            LL tt = 0;
            for(int i = l; i < r; i++){
                tt += abs(dp[i].first-dp[i+1].first)+abs(dp[i].second-dp[i+1].second);
            }
            if(tt+abs(xs-dp[l].first)+abs(ys-dp[l].second) <= t || tt+abs(xs-dp[r].first)+abs(ys-dp[r].second) <= t)
                ans = max(ans,r-l+1);
        }
    }

    cout<<ans<<NL;
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
    fflush(stdin);
    fflush(stdout);
    #ifdef LOCAL
        auto execution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        cout<<"Execution time : "<<execution_time()*1000<<" ms"<<NL;
    #endif
    return 0;
}
