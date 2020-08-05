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
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void readarray(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

vector<set<int>> g(100002);
vector<bool> vis(100002,0);
long double dfs(int root, int p)
{
    vis[root] = 1;
    long double sum = 0;
    for(int i : g[root])
        if(!vis[i])
            sum += dfs(i,root)+1;
    if(sum == 0)
        return 0;
    return sum/(size(g[root]) - (p >= 1));
}

void solve()
{
    // fh;// comment this line before submitting to online judge
    // all the code goes here
    int n;
    scanf("%lld",&n);
    f(i,0,n-1)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        g[x].insert(y);
        g[y].insert(x);
    }
    long double rs = dfs(1,0);
    printf("%.18LF\n",rs);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    startTime = clock();
    solve();
    // fflush(stdin);
    // fflush(stdout);
    return 0;
}