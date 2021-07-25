#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

// aaram se code kro, nhi to bhoot glti hoga
// hm to khenge ki, step by step bdho or dhyan se kro

// agr ek logic kam nhi kr rha ya implement krna muskil hai to duskra try kro
inline void solve()
{
    // this programme count the number of subsequence of a string in a bigger string.
    const int mod = 1e9 + 7;
    string s,t = "chokudai";cin>>s;
    int n = sz(s);

    vector<vector<LL>> dp(n + 1,vector<LL>(9,0));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 8; j++){
            if(j == 0){
                dp[i][j] = 1;
                continue;
            }

            if(i == 0){
                dp[i][j] = 0;
                continue;
            }

            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                dp[i][j] %= mod;
            }else{
                dp[i][j] = dp[i - 1][j];
                dp[i][j] %= mod;
            }
        }
    }

    cout<<dp[n][8]<<NL;
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
