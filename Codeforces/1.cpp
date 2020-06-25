#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf        \
    int t;           \
    scanf("%d", &t); \
    while (t--)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int

void solve()
{
    test
    {
        string s;
        cin>>s;
        set<pair<int,int>> st;
        int p = 0,h = 0;
        int ti = 0;
        for(char a : s)
        {
            int hc = h,vc = p;
            if(a == 'N')p++;
            else if(a == 'S')p--;
            else if(a == 'W')h--;
            else h++;
            if(st.find({hc+h,vc+p}) == st.end())
                ti+=5,st.insert({hc+h,vc+p});
            else ti++;
        }
        cout<<ti<<NL;
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