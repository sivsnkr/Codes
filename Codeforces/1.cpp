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
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin>>a[i];

    map<int,int> st;
    int sum = 0;
    st[0] = 0;
    int count = 0;
    int j = 1;
    for(int i = 1; i <= n; i++)
    {
        sum+=a[i];
        if(st.find(sum) != st.end())
        {
            int l = i-1-j;
            if(j != 0)
                l++;
            count+=(l*(l+1))/2;
            j = st[sum]+2;
            l = i-j;
            count-=(l*(l+1))/2;

        }
        st[sum] = i;
    }
    int l = n-j;
    if(j != 0)
        l++;
    count+=(l*(l+1))/2;
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