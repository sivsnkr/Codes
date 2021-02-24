#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

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
};

inline void solve()
{
    // all the code goes here
    int n,k;cin>>n>>k;
    vector<tuple<int,int,int>> edges(k);
    class DSU st(n+1);
    for(int i = 0; i < k; i++)
    {
        int x,y,d;cin>>x>>y>>d;
        edges[i] = {d,x,y};
    }
    sort(all(edges));
    int res = 0;
    for(int i = 0; i < k; i++)
    {
        auto [d,x,y] = edges[i];
        int pa = st.get(x),pb = st.get(y);
        if(pa != pb)
        {
            st.join(pa,pb);
            res = max(res,d);
        }
    }
    cout<<res<<NL;
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