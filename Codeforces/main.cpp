#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

void print(vector<int> &a){
    for(int i : a)
        cout<<i<<" ";
    cout<<NL;
}

inline void solve()
{
    const int mod = 1e9+7;
    string n;cin>>n;
    int m;cin>>m;
    vector<int> freq(10,0);
    for(char c : n){
        freq[c-'0']++;
    }
    
    for(int i = 0; i < m; i++){
        vector<int> new_freq = freq;
        for(int j = 0; j < 9; j++){
            new_freq[j+1] = freq[j];
        }
        new_freq[1] = (new_freq[1]+freq[9])%mod;
        new_freq[0] = freq[9];
        freq = new_freq;
        // print(freq);
    }

    LL res = 0;
    for(int i = 0; i < 10; i++){
        res += freq[i];
        res %= mod;
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
    cin>>t;
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
