#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n,m;cin>>n>>m;
    multiset<int> g;
    vector<int> p(m);
    for(int i = 0; i < n; i++)
    {
        int pe;cin>>pe;g.insert(pe);
    }

    for(int &a : p)
    {
        cin>>a;
    }
    sort(p.begin(),p.end(),[](int a, int b)->bool{
        return a>b;
    });

    long long  int sum = 0;
    int i = 0;
    bool ps[m];
    memset(ps,0,sizeof(ps));
    int j =0;
    while(!g.empty()&&true)
    {
        int top = *g.rbegin();
        g.erase(--g.end());
        if(top == 0)
            break;
        // if(ps[i] == 1)
        //     sum+=1;
        if(top-p[i] >= 0)
        {
            g.insert(top-p[i]);
        }
        ps[i] = !ps[i];
        i = (i+1)%p.size();
        if(i == 0)
        {
            sum+=1+j;
            j = 1;
        }
    }
    if(i+1 != 0)
        sum+=2;
    cout<<sum<<"\n";
    return 0;
}