#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

class Max_bipartetG_match{
    int n;
    int m;
    list<int> *adj;
    const int INF = 1e9;
    const int NIL = 0;
    vector<int> pairu,pairv,dist;
    bool bfs();
    bool dfs(int root);
public:
    Max_bipartetG_match(int n,int m){
        this->n = n;
        this->m = m;
        this->adj = new list<int>[n+1];
        pairu.assign(n+1,NIL);
        pairv.assign(m+1,NIL);
        dist.resize(n+1);
    }

    void add_edge(int u,int v);
    int hopcroftKarp();
};

int Max_bipartetG_match::hopcroftKarp() {
    int res = 0;
    while(bfs()){
        for(int i = 1; i <= n; i++){
            if(pairu[i] == NIL && dfs(i)){
                res++;
            }
        }
    }
    return res;
}
void Max_bipartetG_match::add_edge(int u, int v) {
    adj[u].push_back(v);
}

bool Max_bipartetG_match::bfs() {
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(pairu[i] == NIL){
            dist[i] = 0;
            q.push(i);
        }else dist[i] = INF;
    }

    dist[NIL] = INF;
    while(!q.empty()){
        int root = q.front();
        q.pop();
        if(dist[root] < dist[NIL]){
            for(int v : adj[root]){
                if(dist[pairv[v]] == INF){
                    dist[pairv[v]] = dist[root]+1;
                    q.push(pairv[v]);
                }
            }
        }
    }

    return (dist[NIL] != INF);
}

bool Max_bipartetG_match::dfs(int root) {
    if(root != NIL){
        for(int v : adj[root]){
            if(dist[pairv[v]] == dist[root]+1){
                if(dfs(pairv[v])){
                    pairv[v] = root;
                    pairu[root] = v;
                    return true;
                }
            }
        }
        dist[root] = INF;
        return false;
    }

    return true;
}

inline void solve()
{
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
