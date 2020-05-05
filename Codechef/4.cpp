// #include <bits/stdc++.h>
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
    if(v[src])
        return;
    v[src] = 1;
    for(auto it = g[src].begin(); it != g[src].end(); it++)
    {
        printf("src %d\n",*it);
        if(v[*it] == 0)
            dfs(g,*it,v);
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

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
        }

        set<pair<int,int>> mp;
        for(int i = 0; i < m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--,b--;
            mp.insert({a,b});
            // mp.insert({b,a});
        }
        vector<unordered_set<int>> g(n);
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            // if(ma[it->first] > ma[it->second] && it->first < it->second)
            //     swap(ma[it->first],ma[it->second]);
            g[it->first].insert(it->second);
            g[it->second].insert(it->first);
        }

        // for(int i = 0; i < n; i++)
        // {
        //     printf("src %d : ",i);
        //     for(auto it = g[i].begin(); it != g[i].end(); it++)
        //     {
        //         printf("%d\t",*it);
        //     }
        // }
        vector<bool> v(n);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            // int max = 0;
            // int mxin = 0;
            // for(int j = 0; j < n-i; j++)
            // {
            //     if(ma[j] > max)
            //     {
            //         max = ma[j];
            //         mxin = j;
            //     }
            // }
        
            // if(mxin != n-i-1)
            // {
            //     v.assign(n,0);
            //     dfs(g,mxin,v);
            //     swap(ma[mxin],ma[n-i-1]);
            //     if(v[n-i-1] == 0)
            //     {
            //         count++;
            //     }
            //     // if(mp.find({mxin,n-i-1}) == mp.end() && mp.find({n-i-1,mxin}) == mp.end())
            //     // {
            //     //     count++;
            //     // }
            // }
            if(i != ma[i]-1)
            {
                v.assign(n,0);
                dfs(g,i,v);
                swap(ma[i],ma[ma[i]-1]);
                if(v[ma[i]-1] == 0)
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