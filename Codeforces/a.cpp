#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
template<typename T>
void read(vector<T> &a);

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
    int n,m;cin>>n>>m;
    class DSU st(n+1);
    vector<pair<int,int>> edges;
    vector<int> cnt(n+1,0);


    for(int i = 0; i < m; i++)
    {
        int x,y;cin>>x>>y;
        edges.emplace_back(x,y);
        cnt[x]++,cnt[y]++;
    }
    vector<vector<int>> g(n+1);
    multiset<pair<int,int>> min_vals;
    for(int i = 1; i <= n; i++)
        min_vals.insert({cnt[i],i});
    int res = 0;
    for(auto [x,y] : edges)
    {
        if(st.get(x) != st.get(y))
        {
            res++;
            st.join(x,y);
            g[x].push_back(y),g[y].push_back(x);
        }
    }
    cout<<"val "<<res<<NL;
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] < n-1)
        {
            auto it = min_vals.find({cnt[i],i});
            auto [count,in] = *it;
            min_vals.erase(it);
            if(min_vals.size() > 0 && (*min_vals.begin()).first < n-1)
            {
                res--;
                cout<<"i "<<i<<NL;
                auto [cou,j] = *min_vals.begin();
                cnt[j]++;
                cout<<"j "<<j<<NL;
                min_vals.erase(min_vals.begin());
                min_vals.insert({cou+1,j});
                min_vals.insert({count+1,i});
                cnt[i]++;
            }
            else 
                min_vals.insert({count,i});
        }
    }

    cout<<res<<NL;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}
