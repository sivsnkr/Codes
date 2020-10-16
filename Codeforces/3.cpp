#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define PI 3.14159265
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
int mod = 1000000007;
void read(vector<int> &a);

bool check(int a, int b, int c)
{
    if(a == b)
        return false;
    if(b == c)
        return false;
    if(a == c)
        return false;
    return true;
}

inline void solve()
{
    // all the code goes here
    int n,m;cin>>n>>m;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<pair<int,int>> num,spe,al;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if('0' <= a[i][j] && a[i][j] <= '9')
                num.push_back({min(j,m-j),i});
            if('a' <= a[i][j] && a[i][j] <= 'z')
                al.push_back({min(j,m-j),i});
            if(a[i][j] == '#' || a[i][j] == '*' || a[i][j] == '&')
                spe.push_back({min(j,m-j),i});
        }
    }

    int mi = LLONG_MAX;

    for(int i = 0; i < num.size(); i++)
    {
        for(int j = 0; j < al.size(); j++)
        {
            for(int k = 0; k < spe.size(); k++)
            {
                if(check(num[i].second,al[j].second,spe[k].second))
                {
                    mi = min(mi,num[i].first+al[j].first+spe[k].first);
                }
            }
        }
    }
    cout<<mi<<NL;
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