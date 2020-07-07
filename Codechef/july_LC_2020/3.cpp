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
int c = 0,k;
vector<vector<bool>> v;
void dfs(int i,int j)
{
    if(i < 0 || i > 7 || j < 0 || j > 7 || v[i][j] || c >= k)
        return;
    c++;
    v[i][j] = 1;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i+1,j+1);
    dfs(i+1,j-1);
    dfs(i-1,j+1);
    dfs(i-1,j-1);
}
void solve()
{
    test
    {
        cin>>k;
        c = 0;
        v.assign(8,vector<bool>(8,0));
        dfs(0,0);
        f(i,0,8)
        {
            f(j,0,8)
            {
                if(i == 0 && j == 0)
                    cout<<'O';
                else if(v[i][j])
                    cout<<'.';
                else
                {
                    cout<<'X';
                }
            }
            cout<<NL;
        }
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