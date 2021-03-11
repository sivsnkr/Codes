#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

struct ele{
    int w,u,v;
};

vector<ele> g;
int n,m;
bool check(int val){
}

inline void solve()
{
    cin>>n>>m;
    g.resize(m);
    vector<int> ws;
    for(int i = 0; i < m; i++){
        cin>>g[i].u>>g[i].v>>g[i].w;
        ws.push_back(g[i].w);
    }

    sort(all(g),[](ele a, ele b)->bool{
        return a.w < b.w;
    });
    int st = 0,en = 1e9+5;
    int ans = -1;
    while(st <= en){
        int mid = (st+en)/2;
        if(check(mid)){
            ans = mid;
            en = mid-1;
        }else{
            st = mid+1;
        }
    }

    cout<<ans<<NL;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
