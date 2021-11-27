#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

void solve()
{
    int n,k;cin>>n>>k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];

    int res = 0;
    
    for(int i = 1; i <= n; i++){
        bool en = 0;
        for(int j = sz(a) - 1; j >= 0; j--){
            if(a[j] != j + 1){
                a.erase(a.begin() + j);
                res++;
                en = 1;
                break;
            }
        }

        if(!en){
            res = -1;
            break;
        }

        int cnt = 0;
        for(int i = 0; i < sz(a); i++){
            if(a[i] == i + 1)
                cnt++;
        }

        if(cnt == k){
            cout<<"in "<<i<<"\n";
            break;
        }
    }

    cout<<res<<"\n";
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
        cout<<"Execution time : "<<execution_time()*1000<<" ms";
    #endif
    cout.flush();
    return 0;
}
