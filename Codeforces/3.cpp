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
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void readarray(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

int n,m;
bool checkV(vector<vector<int>> a)
{
    bool valid = 1;
    f(i,0,n)
    {
        f(j,0,m-1)
            if(a[i][j] >= a[i][j+1])
                valid = 0;
    }
    f(i,0,m)
        f(j,0,n-1)
            if(a[j][i] >= a[j+1][i])
                valid = 0;
    return valid;
}

inline void solve()
{
    // all the code goes here
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m)),b(n,vector<int>(m));
    f(i,0,n)
        f(j,0,m)
            cin>>a[i][j];
    f(i,0,n)
        f(j,0,m)
            cin>>b[i][j];
    f(i,0,n)
        f(j,0,m)
        {
            int mi = min(a[i][j],b[i][j]);
            int mx = max(a[i][j],b[i][j]);
            a[i][j] = mi;
            b[i][j] = mx;
        }
    bool valid = checkV(a);
    valid = valid&&checkV(b);
    if(valid)
        cout<<"Possible";
    else 
        cout<<"Impossible";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        fh;
    #endif
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}