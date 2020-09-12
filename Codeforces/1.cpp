#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf int t;scanf("%d", &t);while (t--)
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
int mod = 1000000007;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

vector<vector<int>> g(100005);
vector<bool> vis(100005);
vector<int> colour(100005);

bool check(int root,int color)
{
    if(vis[root])
        return true;
    if(colour[root] != color && color != -1)   
        return false;
    bool res = true;
    vis[root] = 1;
    for(int i : g[root])
    {
        bool rest = 1;
        if(color == -1)
            rest = check(i,colour[i]);
        else
            rest = check(i,color);
        res = res&&rest;
    }
    return res;
}

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    f(i,0,n-1)
    {
        int x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    f(i,1,n+1)
        cin>>colour[i];
    int r1 = 1,r2 = 1;
    bool found = 0;
    f(i,0,n)
    {
        for(int j : g[i])
        {
            if(colour[i] != colour[j])
            {
                r1 = i;r2 = j;
                found = 1;
                break;
            }
        }
        if(found)
            break;
    }
    
    if(check(r1,-1))
    {
        cout<<"YES"<<NL;
        cout<<r1<<NL;
        return;
    }
    vis.assign(n+1,0);
    if(check(r2,-1))
    {
        cout<<"YES"<<NL;
        cout<<r2<<NL;
        return;
    }
    cout<<"NO"<<NL;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        fh;
    #endif
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}