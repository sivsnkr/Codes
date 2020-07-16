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
vector<int> stree(400001);
vector<int> a(100001);

void build(int p,int l, int r)
{
    if(l == r)
    {
        stree[p] = a[l];
        return;
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    build(left,l,(l+r)/2);
    build(right,(l+r)/2+1,r);
    stree[p] = stree[left] >= stree[right] ? stree[right]:stree[left];
}

void update(int i, int value, int p, int l, int r)
{
    if(l > i || r < i)
        return;
    if(l == r)
    {
        stree[p] = a[l];
        return;
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    update(i,value,left,l,(l+r)/2);
    update(i,value,right,(l+r)/2+1,r);
    stree[p] = stree[left] >= stree[right] ? stree[right]:stree[left];
}

int access(int p, int l, int r, int L, int R)
{
    if(l > R || r < L)
        return -1;
    if(l >= L && r <= R)
    {
        return stree[p];
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    int li = access(left,l,(l+r)/2,L,R);
    int ri = access(right,(l+r)/2+1,r,L,R);
    if(li == -1)
        return ri;
    if(ri == -1)
        return li;
    return li >= ri ? ri:li;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    f(i,0,n)cin>>a[i];
    build(0,0,n-1);
    while(m--)
    {
        int q,s,b;
        cin>>q>>s>>b;
        if(q == 1)
        {
            a[s] = b;
            update(s,b,0,0,n-1);
        }
        else
        {
            int res = access(0,0,n-1,s,b-1);
            cout<<res<<NL;
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