#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

inline void solve()
{
    int n,m;cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];

    auto check = [a,n,m](int mval)->bool{
        int prev = 0;
        for(int i = 0; i < n; i++){
            int l = a[i],r = a[i]+mval;
            if((prev >= l && prev <= r) || (prev+m >= l && prev+m <= r))
                continue;
            if(prev > r)
                return false;
            prev = l;
        }
        return true;
    };

    int l = 0,r = m,ans = m-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
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
    #ifdef LOCAL
        auto execution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        cout<<"Execution time : "<<execution_time()*1000<<" ms"<<NL;
    #endif
    fflush(stdin);
    fflush(stdout);
    return 0;
}
