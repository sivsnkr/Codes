// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

void dfs(vector<set<int>> &g,int src,vector<bool> &v)
{
    v[src] = 1;
    for(auto it = g[src].begin(); it != g[src].end(); it++)
        if(v[*it] == 0)
            dfs(g,*it,v);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t > 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int> ma(n);
        set<pair<int,int>> mp;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&ma[i]);
        }
        vector<set<int>> g(n);
        for(int i = 0; i < m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--,b--;
            g[a].insert(b);
            g[b].insert(a);
            mp.insert({a,b});
        }
        vector<bool> v(n);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(auto it = mp.begin(); it != mp.end(); it++)
            {
                int a = min(it->first,it->second);
                int b = max(it->first,it->second);
                if(ma[a] > ma[b])
                    swap(ma[it->first],ma[it->second]);
            }
            int maxv = 0;
            int mxin = 0;
            for(int j = 0; j < n-i; j++)
            {
                if(ma[j] > maxv)
                {
                    maxv = ma[j];
                    mxin = j;
                }
            }
            if(mxin != n-i-1)
            {
                v.assign(n,0);
                dfs(g,mxin,v);
                swap(ma[mxin],ma[n-i-1]);
                if(v[n-i-1] == 0)
                {
                    count++;
                }
            }
        }
        printf("%d\n",count);
        t--;
    }
    return 0;
}