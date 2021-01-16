#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
template<typename T>
void read(vector<T> &a);

struct ele
{
    int a,b,c;
};
inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    vector<ele> a(n);
    f(i,0,n)
    {
        int x,y;cin>>x>>y;
        a[i] = {x,y,i};
    }
    sort(all(a),[](ele a, ele b)->bool{
        return a.a < b.a;
    });
    int k;cin>>k;
    vector<int> kval(k);
    read(kval);
    sort(all(kval));
    
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    vector<int> pos(k,-1);
    f(i,0,n+1)
    {
        f(j,0,k+1)
        {
            if(i < n && j < k && a[i].a <= kval[j])
            {
                if(dp[i+1][j+1] < dp[i][j]+a[i].b)
                    pos[j] = a[i].c+1;
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+a[i].b);
            }
            if(j < k)
                dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
            if(i < n)
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
        }
    }

    f(i,0,k)
        cout<<pos[i]<<" \n"[i==k-1];
    map<int,int> st;
    f(i,0,k)
        if(pos[i] >= 0)
            st[pos[i]] = i;
    cout<<st.size()<<" "<<dp[n][k]<<NL;
    for(auto [x,y] : st)
        cout<<x<<" "<<y+1<<NL;
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
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}