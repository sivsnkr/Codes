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
    vector<int> a(n);
    read(a);
    string s;cin>>s;
    int l = -1e10,r = 1e10;
    for(int i = 4; i < n; i++)
    {
        if(s[i] == '1')
        {
            int mi = 1e10,mx = -1e10;
            for(int j = min((int)0,i-3); j < min(n,i+4); j++)
            {
                if(j <= i)
                    mi = min(mi,a[j]);
                if(j >= i)
                    mx = max(mx,a[j]);
            }

            r = min(r,mi-1);
            l = max(l,mx+1);
        }
    }
    cout<<l<<" "<<max(r,l+1)<<NL;
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