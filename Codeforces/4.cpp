#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
template<typename T>
void read(vector<T> &a);

inline void solve()
{
    // all the code goes here
    test
    {
        int n;cin>>n;
        vector<int> nums;
        vector<pair<int,int>> a(n);
        f(i,0,n)
        {
            int x,y;cin>>x>>y;
            a[i] = {x,y};
            nums.push_back(x),nums.push_back(y);
        }
        sort(all(nums));
        map<int,int> st;
        int cnt = 1;
        f(i,0,nums.size())
        {
            if(st.find(nums[i]) == st.end())
            {
                st[nums[i]] = cnt;
                cnt++;
            }
        }
        vector<int> dp(cnt+1,0);
        f(i,0,n)
        {
            dp[st[a[i].first]]++,dp[st[a[i].second]+1]--;
        }

        f(i,1,cnt+1)
            dp[i]+=dp[i-1];

        int mxv = 1;
        f(i,0,n)
            mxv = min(n,max(mxv,dp[st[a[i].first]]+dp[st[a[i].second]]));
        cout<<n-mxv<<NL;
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
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}