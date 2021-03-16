#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

const int MX = 1e5+5;
vector<vector<int>> g(MX),gc;
vector<vector<int>> g1(MX),gc1;

class DSU
{
    vector<int> p,ranks;
public:
    DSU(int MX)
    {
        p.resize(MX);
        ranks.resize(MX);
        iota(p.begin(),p.end(),0);
    }
    int get(int c)
    {
        return p[c] = p[c] == c ? c : get(p[c]);
    }
    void join(int a, int b)
    {
        int pa = get(a),pb = get(b);
        if(pa != pb)
        {
            if(ranks[pa] == ranks[pb])
                ranks[pa]++;
            if(ranks[pa] > ranks[pb])
                p[pb] = pa;
            else
                p[pa] = pb;
        }
    }

    map<int,int> get_freq()
    {
        map<int,int> res;
        int MX = size(p);
        for(int i = 0; i < MX; i++)
            res[get(i)]++;
        return res;
    }

};

vector<bool> vis(MX);
int dfs(vector<vector<int>> &g, int root){
    int len = 0;
    for(int i : g[root]){
        len = max(len,dfs(g,i));
    }
    return len+1;
}

inline void solve()
{
    int n;cin>>n;
    vector<int> a(n);
    read(a);
    class DSU con(n+1),con1(n+1);

    for(int i = 0; i < n-1; i++){
        if(i == 0){
            if(a[1] > a[0])g1[0].push_back(1),g[1].push_back(0),con.join(1,0);
            else g1[1].push_back(0),g[0].push_back(1);
        }else{
            if(a[i] > a[i+1])g1[i+1].push_back(i),g[i].push_back(i+1),con.join(i,i+1);
            else g1[i].push_back(i+1),g[i+1].push_back(i);
        }
    }

    vector<pair<int,int>> mxe;
    for(int i = 0; i < n; i++){
        if(!vis[i])
            mxe.push_back({dfs(g1,i),i});
    }
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
