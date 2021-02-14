#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
template<typename T>
void read(vector<T> &a);

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    vector<int> a(n);
    read(a);
    cout<<"1 1"<<NL;
    cout<<-a[0]<<NL;
    if(n > 1)
    {
        cout<<"1 "<<n<<NL;
        cout<<0<<" ";
        f(i,1,n)
            cout<<-n*a[i]<<" \n"[i==n-1];
        cout<<"2 "<<n<<NL;
        f(i,1,n)
            cout<<(n-1)*a[i]<<" \n"[i==n-1];
    }
    else
    {
        cout<<"1 1"<<NL;
        cout<<0<<NL;
        cout<<"1 1"<<NL;
        cout<<0<<NL;
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
    cout<<setprecision(10);
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
