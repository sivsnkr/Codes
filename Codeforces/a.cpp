#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

inline void solve()
{
    // let's code
    test
    {
        int n,k;cin>>n>>k;
        string s;cin>>s;

        if(k%n == 0)
        {
            cout<<n<<NL;
            continue;
        }
        map<int,int> freq;
        for(char c : s)
            freq[c-'a']++;
        int res = 0;
        for(int lens = 1; lens <= n; lens++)
        {
            int kval = k%lens;
            int reqf = lens/kval;
            map<int,int> cf = freq;
            for(int i = 0; i < kval; i++)
            {
                for(auto &[x,y] : freq)
                {

                }
            }
        }
    }
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
