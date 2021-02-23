#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int i = 0; i < size(a); i++)cin>>a[i]

class Min_queue
{
    deque<int> a;
    public:
    void push(int val)
    {
        while(!a.empty() && a.back() > val)
            a.pop_back();
        a.push_back(val);
    }

    void del(int val)
    {
        if(!a.empty() && a.front() == val)
            a.pop_front();
    }

    int find_min()
    {
        return a.front();
    }
};

inline void solve()
{
    // let's code
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
