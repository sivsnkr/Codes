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
        int n,p,k;cin>>n>>p>>k;
        vector<int> a(n);
        read(a);
        sort(all(a));
        int pref = 0,sum = 0;
        int ans = 0;
        for(int i = 0; i < k; i++)
        {
            sum = pref;
            if(sum > p)
                break;
            int count = i;
            for(int j = i+k-1; j < n; j+=k)
            {
                if(sum+a[j] > p)
                    break;
                count+=k;
                sum+=a[j];
            }
            pref += a[i];
            ans = max(ans,count);
        }
        cout<<ans<<NL;
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