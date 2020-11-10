#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    const int MX = 1e5+5;
    int ma = MX,mb = MX,mc = MX;
    int total = 3*MX;
    vector<pair<int,string>> vec;
    for(int i = 0; i < n; i++)
    {
        int c;cin>>c;
        string s;cin>>s;
        vec.emplace_back(c,s);
        bool A = 0,B = 0,C = 0;
        for(int i = 0; i < s.length(); i++)
            if(s[i] == 'A')
                A = 1;
            else if(s[i] == 'B')
                B = 1;
            else
                C = 1;
        if(A)
            ma = min(ma,c);
        if(B)
            mb = min(mb,c);
        if(C)
            mc = min(mc,c);
    }
    for(int i = 0; i < n; i++)
    {
        bool A = 0,B = 0,C = 0;
        string s = vec[i].second;
        int tc = vec[i].first;
        for(int i = 0; i < s.length(); i++)
            if(s[i] == 'A')
                A = 1;
            else if(s[i] == 'B')
                B = 1;
            else
                C = 1;
        if(!A)
            tc+=ma;
        if(!B)
            tc+=mb;
        if(!C)
            tc+=mc;
        total = min(total,tc);
    }
    if(mc >= MX || mb >= MX || ma >= MX)
    {
        cout<<-1<<NL;
        return;
    }
    cout<<total<<NL;
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