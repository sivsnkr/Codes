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
    while(x0 < xs || y0 < ys){
        dp.emplace_back(x0,y0);
        x0 = ax*x0+bx;
        y0 = ay*y0+by;
    }

    LL ti = t - abs(xs-dp[sz(dp)-1].first)-abs(ys-dp[sz(dp)-1].second);
    int val = 0;
    if(ti >= 0)
        val++;
    int i;
    LL tim = 0;
    for(i = sz(dp)-2; i >= 0; i--){
        LL reqt = abs(dp[i+1].first-dp[i].first)+abs(dp[i+1].second-dp[i].second);
        tim += reqt;
        if(ti >= reqt){
            ti -= reqt;
            val++;
        }else
            break;
    }
//    dp.emplace_back(x0,y0);

    if(i > 0){
        cout<<val<<NL;
        return;
    }

    LL time = abs(xs-dp[sz(dp)-1].first)+abs(ys-dp[sz(dp)-1].second);
    while(true){
        LL val = time+abs(x0-dp[sz(dp)-1].first)+
    }
    cout<<val<<NL;
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
