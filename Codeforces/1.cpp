#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    string a,b;cin>>a>>b;
    int ones = 0,zeros = 0;
    int n = a.length(),m = b.length();
    vector<int> z(n),o(n);
    for(int i = 0; i < n; i++)
    {
        if(a[i] == '1')
            ones++;
        else
            zeros++;
        z[i] = zeros;
        o[i] = ones;
    }

    int count = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(b[i] == '1')
        {
            count+=z[i];
        }
        else
        {
            count+=o[i];
        }
    }
    cout<<"first count "<<count<<NL;
    for(int i = m-1; i+n > m; i--)
    {
        if(b[i] == '0')
            count+=(ones-o[m-1-i]);
        else
            count+=(zeros-z[m-1-i]);
    }
    cout<<"second count "<<count<<NL;
    for(int i = n-1; i+n <= m; i++)
    {
        if(b[i] == '1')
            count+=zeros;
        else
            count+=ones;
    }
    cout<<count<<NL;
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