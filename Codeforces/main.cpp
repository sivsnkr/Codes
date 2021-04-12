#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

inline void solve()
{
    int n,l,r,s;cin>>n>>l>>r>>s;
    vector<int> per;
    for(int i = 1; i <= n; i++)
        per.push_back(i);
    
    int le = r-l+1;
    int sc = s;
    vector<int> ano;
    for(int i = n; i > 0; i--){
        int lec = le-sz(ano)-1;
        if(sc - i >= lec*(lec+1)/2 && lec >= 0){
            ano.push_back(i);
            sc -= i;
        }
    }
 
    if(sc > 0){
        cout<<-1<<NL;
        return;
    }
    vector<int> res(n+1);
    vector<bool> vis(n+1,0);
    for(int i = l; i <= r; i++){
        res[i] = ano[i-l];
        vis[ano[i-l]] = 1;
    }
    
    for(int i = 1; i < l; i++){
        for(int j = 1; j <= n; j++){
            if(!vis[j]){
                res[i] = j;
                vis[j] = 1;
                break;
            }
        }
    }
 
    for(int i = r+1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!vis[j]){
                res[i] = j;
                vis[j] = 1;
                break;
            }
        }
    }
 
    for(int i = 1; i <= n; i++)
        cout<<res[i]<<" \n"[i==n];
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
        auto excution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        cout<<"Excution time : "<<excution_time()*1000<<" ms"<<NL;
    #endif
    return 0;
}
