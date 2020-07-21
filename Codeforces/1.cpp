#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf int t;scanf("%d", &t);while (t--)
#define test int t;cin >> t;while (t--)
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int

void solve()
{
    test
    {
        map<int,int> st;
        int n;cin>>n;
        string s;cin>>s;
        vector<int> a(n);
        f(i,0,n)
        {
            switch (s[i])
            {
            case 'L':
            a[i] = -1;break;
            case 'R':
            a[i] = 1;break;
            case 'U':
            a[i] = 4e5;break;
            case 'D':
            a[i] = -4e5;
            }
        }
        int sum = 0;
        int m = LLONG_MAX;
        pair<int,int> res = {-4e5,4e5};
        st.insert({0,0});
        f(i,0,n)
        {
            sum+=a[i];
            if(st.find(sum) == st.end())
            {
                st[sum] = i+1;
            }
            else
            {
                m = min(m,i-st[sum]);
                if(abs(i-st[sum]) < abs(res.second - res.first))
                    res = {st[sum]+1,i+1};
            }
        }
        if(m == LLONG_MAX)
            cout<<-1;
        else
            cout<<res.first<<" "<<res.second;
        cout<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // clock_t st = clock();
    // all the code goes here
    solve();
    // cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}