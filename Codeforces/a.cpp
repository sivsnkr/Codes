#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]
#define size(a) (int)(a).size()
clock_t startTime;
double time_taken();

struct ele{
    int d,u,v;
};

inline void solve()
{
    int n,m,k;cin>>n>>m>>k;
    vector<int> g(n);
    read(g);
    g.insert(g.begin(),0);
    vector<ele> data(m);
    for(int i = 0; i < m; i++){
        auto &[d,u,v] = data[i];
        cin>>u>>v>>d;
    }

    vector<int> mins(n+1,1);
    for(int i = 1; i <= n; i++)
        if(g[i] < 0)
            mins[i] = 0;
    // for(int i = 1; i <= n; i++)
    //     cout<<mins[i]<<" \n"[i==n];

    sort(all(data),[](ele a, ele b)->bool{
        return abs(a.d) > abs(b.d);
    });
    
    vector<bool> vis(n+1,0);
    for(auto [d,u,v] : data){
        int sum = 0;
        for(int i = u; i <= v; i++)
            sum += g[i];
        int sum1 = 0;
        for(int i = u; i <= v; i++)
            if(mins[i])
                sum1 += g[i];
        bool changable = 1;
        for(int i = u; i <= v; i++)
            changable = changable && !vis[i];
        if(!changable)
            continue;
        if(d + sum > sum1){
            for(int i = u; i <= v; i++){
                mins[i] = 1;
                vis[i] = 1;
            }
        }

        // int psum = sum;
        // sum = 0;
        // for(int i = u; i <= v; i++){
        //     if(mins[i])
        //         sum += g[i];
        //     else 
        //         break;
        // }

        if(sum == sum1){
            int mi = g[u];
            int in = u;
            for(int i = u; i <= v; i++){
                if(g[u] < mi){
                    mi = g[u];
                    in = i;
                }
            }
            if(sum + d < sum-mi){
                mins[in] = 0;
                vis[in] = 1;
            }
        }

        // for(int i = 1; i <= n; i++)
        //     cout<<mins[i]<<" \n"[i==n];
    }

    int res = 0;
    for(int i = 1; i <= n; i++)
        if(mins[i])
            res += g[i];

    for(auto [d,u,v] : data){
        bool re = 1;
        for(int i = u; i <= v; i++){
            re  = re && mins[i];
        }
        if(re)
            res += d;
    }

    // for(int i = 1; i <= n; i++)
    //     cout<<mins[i]<<" \n"[i==n];
    cout<<res<<NL;
}

int32_t main()
{
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
    return 0;
}

double time_taken() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
