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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // clock_t st = clock();
    // all the code goes here
    // solve();
    vector<vector<int>> st;
    vector<int> a{1,2,3};
    st.push_back(a);
    a[0] = 2;
    for(int i = 0; i < size(st); i++)
    {
        for(int j = 0; j < size(st[i]); j++)
            cout<<st[i][j]<<" ";
        cout<<NL;
    }
    // cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}