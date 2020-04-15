#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;cin>>n>>m;
    vector<pair<int,int>> q(m);
    for(int i = 0; i < m; i++)
    {
        cin>>q[i].first>>q[i].second;
    }
    
    vector<int> s{q[0].first,q[0].second};
    for(int x : s)
    {
        int all = 0;
        vector<int> val(n+1);
        for(pair<int,int> a : q)
        {
            if(a.first != x&&a.second != x)
                val[a.first]++,val[a.second]++,all++;
        }

        if(*max_element(val.begin(),val.end()) == all)
        {
            cout<<"YES"<<"\n";
            return 0;
        }
    }
    cout<<"NO"<<"\n";
    return 0;
}