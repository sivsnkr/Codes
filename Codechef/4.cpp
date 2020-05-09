#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

void dfs(vector<unordered_set<int>> &g,int src,vector<bool> &v)
{
    v[src] = 1;
    for(auto it = g[src].begin(); it != g[src].end(); it++)
    {
        if(v[*it] == 0)
            dfs(g,*it,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int t;
    scanf("%d",&t);
    while(t > 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int> ma(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&ma[i]);
            ma[i]--;
        }

        set<pair<int,int>> mp;
        for(int i = 0; i < m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--,b--;
            mp.insert({a,b});
        }
        vector<unordered_set<int>> g(n);
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            g[it->first].insert(it->second);
            g[it->second].insert(it->first);
        }
        vector<bool> v(n);
        int count = 0;

        for(int i = 0; i < n; i++)
        {

            for(int i = 0; i < n; i++)
            {
                if(i != ma[i])
                {
                    v.assign(n,0);
                    dfs(g,ma[i],v);
                    if(v[i] != 0)
                    {
                        v.assign(n,0);
                        dfs(g,ma[ma[i]],v);
                        if(v[ma[ma[ma[i]]]] == 0)
                        {
                            count++;
                        }
                        swap(ma[ma[ma[ma[i]]]],ma[ma[i]]);
                        swap(ma[i],ma[ma[i]]);
                    }
                }
            }
            if(i != ma[i] )
            {
                v.assign(n,0);
                dfs(g,i,v);
                if(v[ma[i]] == 0)
                {
                    count++;
                }
                swap(ma[i],ma[ma[i]]);
            }
        }
        printf("%d\n",count);
        t--;
    }

    return 0;
}