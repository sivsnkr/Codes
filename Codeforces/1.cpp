#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define PI 3.14159265
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
int mod = 1000000007;
void read(vector<int> &a);

const int MX = 3e5+5;
vector<int> p(MX);
vector<int> ranks(MX);
vector<int> depth(MX);
int sum;
int get(int c)
{
    sum+=depth[c];
    return p[c] = p[c] == c ? c : get(p[c]);
}

void join(int a, int b)
{
    int pa = get(a);
    depth[a] = sum+1;
    sum = 0;
    int pb = get(b);
    depth[b] = sum+1;
    if(pa != pb)
    {
        // sum = 0;
        if(ranks[pa] >= ranks[pb])
            ranks[pb] = ranks[pa]+1;
        p[pa] = pb;
        depth[pa] = depth[pb]+1;
    }
}

inline void solve()
{
    // all the code goes here
    iota(all(p),0);
    int n,m;cin>>n>>m;
    while(m--)
    {
        int q;cin>>q;
        if(q == 1)
        {
            int a,b;cin>>a>>b;
            join(a,b);
        }
        else
        {
            int a;cin>>a;
            sum = 0;
            // int pa = a;
            get(a);
            // while(true)
            // {
            //     int par = get(pa);
            //     if(pa == par)
            //         break;
            // }
            cout<<sum<<NL;
        }
    }
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