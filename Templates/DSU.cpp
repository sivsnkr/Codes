#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
void read(vector<int> &a);

class DSU
{
    vector<int> p,ranks;
    public:
    DSU(int MX)
    {
        p.resize(MX);
        ranks.resize(MX);
        iota(all(p),0);
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
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}