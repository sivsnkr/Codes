#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define testf int t; scanf("%d",&t); while(t--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define size(container) (int)container.size()
#define int long long int
const int MX = 55;
int n,m;
char mat[MX][MX];
bool visited[MX][MX];
bool good[MX][MX];

void dfs(int i, int j)
{
    if(i >= n || i < 0 || j >= m || j < 0 || mat[i][j] == '#' || visited[i][j])
        return;
    visited[i][j] = 1;
    if(mat[i][j] == '.')
    {
        mat[i][j] = '#';
        return;
    }
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}

bool gdfs(int i, int j)
{
    if(i >= n || i < 0 || j >= m || j < 0 || mat[i][j] == '#' || mat[i][j] == 'B')
        return false;
    if(good[i][j] || (i == n-1 && j == m-1))
        return true;
    good[i][j] = 1;
    return good[i][j] = gdfs(i-1,j) || gdfs(i+1,j) || gdfs(i,j-1) || gdfs(i,j+1);
}

void solve()
{
    memset(visited,0,sizeof(visited));
    f(i,0,n)
    {
        f(j,0,m)
        {
            if(mat[i][j] == 'B')
            {
                dfs(i,j);
            }
        }
    }
    memset(good,0,sizeof(good));
    f(i,0,n)
    {
        f(j,0,m)
        {
            if(mat[i][j] == 'G')
            {
                if(!gdfs(i,j))
                {
                    cout<<"No"<<NL;
                    return;
                }
                good[i][j] = 1;
            }
        }
    }
    cout<<"Yes"<<NL;
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test{
        cin>>n>>m;
        f(i,0,n)
        {
            f(j,0,m)
            {
                cin>>mat[i][j];
            }
        }
        solve();
    }
    fflush(stdin);
    fflush(stdout);
    return 0;
}