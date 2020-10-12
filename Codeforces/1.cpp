#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define PI 3.14159265
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
int mod = 1000000007;
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    int n,m;cin>>n>>m;
    vector<int> a(n),b(n);
    read(a),read(b);

    sort(all(b));
    vector<int> choices;
    for(int i = 0; i < n; i++)
    {
        int val = b[0]-a[i];
        while(val < 0)
            val+=m;
        choices.push_back(val);
    }
    int ans;
    sort(all(choices));
    for(int choice : choices)
    {
        bool valid = 1;
        vector<int> tem = a;
        for(int i = 0; i < n; i++)
            tem[i] = (tem[i]+choice)%m;
        sort(all(tem));
        for(int i = 0; i < n; i++)
        {
            if(tem[i] != b[i])
                valid = 0;
        }
        if(valid)
        {
            ans = choice;
            break;
        }
    }
    cout<<ans<<NL;
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