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
const int MX = 2e5+1;
struct ele
{
    int first,second;
};

ele ret[2];
ele a[MX][2];
ele stree[4*MX][2];
int r,n,m;
void merge(ele a[],ele b[],ele res[])
{
    ele ret[2];
    ret[0].first = (a[0].first*b[0].first + a[0].second*b[1].first)%r;
    ret[0].second = (a[0].first*b[0].second + a[0].second*b[1].second)%r;
    ret[1].first = (a[1].first*b[0].first+ a[1].second*b[1].first)%r;
    ret[1].second = (a[1].first*b[0].second + a[1].second*b[1].second)%r;
    res[1] = ret[1];
    res[0] = ret[0];
}

void build(int p, int l, int r)
{
    if(l == r)
    {
        stree[p][0] = a[l][0];
        stree[p][1] = a[l][1];
        return;
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    build(left,l,(l+r)/2);
    build(right,(l+r)/2+1,r);
    merge(stree[left],stree[right],stree[p]);
}

void access(int p, int l, int r, int L, int R)
{
    if(l > R || r < L)
        return;
    if(l >= L && r <= R)
    {
        merge(ret,stree[p],ret);
        return;
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    access(left,l,(l+r)/2,L,R);
    access(right,(l+r)/2+1,r,L,R);
}

void solve()
{
    cin>>r>>n>>m;
    f(i,0,n)
    {
        cin>>a[i][0].first>>a[i][0].second;
        cin>>a[i][1].first>>a[i][1].second;
    }
    build(0,0,n-1);
    f(i,0,m)
    {
        int l,r;
        cin>>l>>r;
        ret[0] = {1,0},ret[1] = {0,1};
        access(0,0,n-1,l-1,r-1);
        cout<<ret[0].first<<" "<<ret[0].second<<NL;
        cout<<ret[1].first<<" "<<ret[1].second<<NL;
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