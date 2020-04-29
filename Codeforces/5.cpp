#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

vector<unordered_set<int>> g;
void dfs(int src,vector<int> &d)
{
    d[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int s = q.front();
        for(int i : g[s])
        {
            if(d[i] == INT_MAX)
            {
                d[i] = d[s]+1;
                q.push(i);
            }
        }
        q.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,m,a,b,c;
        scanf("%d%d%d%d%d", &n,&m,&a,&b,&c);

        int prices[m];
        for(int i = 0; i < m; i++)scanf("%d", &prices[i]);
        g = vector<unordered_set<int>>(n);
        for(int i = 0; i < m; i++)
        {
            int src,dest;
            scanf("%d%d", &src,&dest);
            src--,dest--;
            g[src].insert(dest);
            g[dest].insert(src);
        }

        vector<int>da(n,INT_MAX),db(n,INT_MAX),dc(n,INT_MAX);
        dfs(a-1,da);
        dfs(b-1,db);
        dfs(c-1,dc);

        sort(prices,prices+m);
        vector<long long> pref(m + 1);
		for (int i = 0; i < m; ++i) {
			pref[i + 1] = pref[i] + prices[i];
		}

        ll mp = numeric_limits<ll>::max();
        for(int i = 0; i < n; i++)
        {
            if(da[i]+db[i]+dc[i]<=m)
                mp = min(mp,ll(pref[db[i]]+pref[da[i]+db[i]+dc[i]]));
        }
        printf("%lld\n",mp);
    }

    return 0;
}