#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    test
    {
        int n,m;cin>>n>>m;
        vector<int> a(n);
        read(a);
        map<int,long double> st;
        f(i,0,m)
        {
            int x;cin>>x;
            long double p;cin>>p;
            st[x] = p;
        }
        if(is_sorted(all(a)))
        {
            cout<<"1"<<NL;
            continue;
        }
        int sum = 0;
        long double p = 1;
        f(i,0,n)
        {
            int l = i+1;
            sum+=a[i];
            if(sum == (l*(l+1))/2)
            {
                if(st.find(l) != st.end())
                {
                    p*=(1-st[l]);
                }
            }
        }
        cout<<setprecision(20);
        long double res = 1-p;
        if(st.find(n) != st.end())
            res = max(res,st[n]);
        cout<<res<<NL;
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