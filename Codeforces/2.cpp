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
    int n,k;cin>>n>>k;
    set<int> st;
    for(int i = 0; i < n; i++)
    {
        int val = 0;
        for(int j = k-1; j >= 0; j--)
        {
            int x;cin>>x;
            val+=(x << j);
        }
        st.insert(val);
    }

    bool valid = 0;
    for(int i : st)
    {
        for(int j : st)
            if((i&j) == 0)
            {
                valid = 1;
                break;
            }
        if(valid)
            break;
    }

    if(valid)
        cout<<"YES";
    else 
        cout<<"NO";
    cout<<NL;
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