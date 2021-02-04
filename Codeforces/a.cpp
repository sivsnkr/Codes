#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
template<typename T>
void read(vector<T> &a);

inline void solve()
{
    // all the code goes here
    int n,d,m;cin>>n>>d>>m;
    vector<int> a(n);
    read(a);
    sort(all(a),greater<int>());
    int mx = a[0];
    a.erase(a.begin());
    int i = 0,j = n-2;
    int sum = 0,cnt = 0;
    // cout<<accumulate(all(a),0LL)<<NL;
    vector<int> a1;
    while(i <= j)
    {
        sum+=a[i];
        if(a[i] > m)
        {
            cnt = d;
            int sum1 = 0;
            while(cnt-- > 0)
            {
                if(a[j] <= m)
                    sum1+=a[j];
                j--;
            }
            if(sum1 > a[i])
            {
                a1.push_back(a[i]);
                sum-=a[i];
                sum+=sum1;
            }
        }
        i++;
    }
    a1.push_back(mx);
    sort(all(a1),greater<int>());
    i = 0,j = a1.size()-1;
    while(i <= j)
    {
        sum+=a1[i];
        cnt = d;
        while(cnt-- > 0)
        {
            j--;
        }
        i++;
    }
    cout<<sum<<NL;
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
    cout<<setprecision(20);
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