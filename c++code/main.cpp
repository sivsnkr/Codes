#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

const int N = 1e6 + 2;
inline void solve()
{
    int n,q;
    scanf("%d%d", &n, &q);
    
    vector<int> values(N, 0);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        values[x]++;
    }

    while(q--){
        int x;
        scanf("%d", &x);
        if(x > 0){
            values[x]++;
        }else{
            // values[x]--;
        }
    }
}

int32_t main()
{
    clock_t startTime;
    startTime = clock();
    int t = 1;
    while(t--){
        solve();
    }
    #ifdef LOCAL
        auto execution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        printf("Execution time : %.3f ms", execution_time() * 1000);
    #endif
    return 0;
}
