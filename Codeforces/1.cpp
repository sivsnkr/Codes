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

vector<bool> vis(5e5+1),avis(5e5+1);
int co;
int n;
map<int,int> st;
map<int,int> cou;
int dfs(int root, vector<set<int>> &g)
{
    if(st.find(root) != st.end())
        return 0;
    st[root] = co;
    int ans = (root <= n)?1:0;
    for(int i : g[root])
        ans+=dfs(i,g);
    return ans;
}

inline void solve()
{
    // all the code goes here
    int q;cin>>n>>q;
    vector<set<int>> g(n+5);
    while(q--)
    {
        int si;cin>>si;
        vector<int> res(si);
        f(i,0,si)
            cin>>res[i];
        f(i,0,si-1)
        {
            g[res[i]].insert(res[i+1]);
            g[res[i+1]].insert(res[i]);
        }
    }

    f(i,1,n+1)
    {
        if(st.find(i) == st.end())
        {
            co++;
            int ans = dfs(i,g);
            cou[co] = ans;
        }
        cout<<max(1LL,cou[st[i]])<<" ";
    }
    cout<<NL;
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