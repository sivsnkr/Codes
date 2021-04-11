#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]
double time_taken();
#define size(a) (int)(a).size()
inline void solve()
{
    cout<<50<<NL;
    for(int i = 0; i < 50; i++){
        int n = rand()%100+1;
        cout<<n<<NL;
        for(int i = 0; i < n; i++){
            string s = "";
            int le = rand()%9+1;
            for(int j = 0; j < le; j++){
                int num = rand()%10;
                if(j == 0){
                    num = rand()%9+1;
                }
                s += to_string(num);
            }
            cout<<s<<" ";
        }
        cout<<NL;
    }
}

clock_t startTime;
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
