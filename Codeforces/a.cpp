#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]
#define size(a) (int)(a).size()
clock_t startTime;
double time_taken();

inline void solve()
{
}

int32_t main()
{
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
    return 0;
}

double time_taken() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
