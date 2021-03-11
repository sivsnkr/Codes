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
vector<vector<int>> G;

bool check(int val){
    for(int i = 1; i <= n; i++)G.clear();
    for(int i = 0; i < size(g); i++)
        if()
}
inline void solve()
{
    int n,m;cin>>n>>m;
    g.resize(m);
    vector<int> ws;
    for(int i = 0; i < m; i++){
        cin>>g[i].u>>g[i].v>>g[i].w;
        ws.push_back(g[i].w);
    }

    int st = 0,en = size(ws)-1;
    sort(all(g));
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
