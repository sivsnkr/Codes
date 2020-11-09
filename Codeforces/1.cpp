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
    test
    {
        int n;cin>>n;
        string s,t;cin>>s>>t;
        int pt = 0;
        bool flip = 0;
        vector<int> res;
        for(int i = n-1; i >= 0; i--)
        {
            if(flip ^ (s[pt] == t[i]))
                res.push_back(1);
            res.push_back(i+1);
            if(flip)
                pt-=i;
            else
                pt+=i;
            flip = !flip;
        }
        cout<<res.size()<<" ";
        for(int x : res)
            cout<<x<<" ";
        cout<<NL;
    }    
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