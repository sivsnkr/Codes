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
int n;
string a[200005];
bool visited[200005];
bool vc[27];
vector<set<int>> graph(26);

void dfs(char c)
{
    for(int i : graph[c-'a'])
    {
        if(!visited[i])
        {
            visited[i] = 1;
            for(char c1 : a[i])
            {
                if(!vc[c1-'a'])
                {
                    vc[c1-'a'] = 1;
                    dfs(c1);
                }
            }
        }
    }
}
void solve()
{
    cin>>n;
    f(i,0,n)
    {
        cin>>a[i];
        for(char c : a[i])
        {
            graph[c-'a'].insert(i);
        }
    }
    int count = 0;
    f(i,0,n)
    {
        if(!visited[i])
        {
            count++;
            visited[i] = 1;
            for(char c : a[i])
            {
                if(!vc[c-'a'])
                {
                    vc[c-'a'] = 1;
                    dfs(c);
                }
            }
        }
    }
    cout<<count<<NL;
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