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
const int MX = 1e5+1;
vector<int> a(MX);
vector<int> stree(4*MX);

int merge(int a, int b)
{
    return a+b;
}

int Nutral()
{
    return LLONG_MIN;
}

int single(int v)
{
    return v;
}

void update(int p, int l, int r, int i)
{
    if(r < i || l > i)
        return;
    if(l == r)
    {
        stree[p] = a[i];
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    update(left,l,(l+r)/2,i);
    update(right,(l+r)/2+1,r,i);
    stree[p] = merge(stree[left],stree[right]);
}

int access(int p, int l, int r, int L, int R)
{
    if(l > R || r < L)
        return Nutral();
    if(l >= L && r <= R)
    {
        return single(stree[p]);
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    int lv = access(left,l,(l+r)/2,L,R);
    int rv = access(right,(l+r)/2+1,r,L,R);
    if(lv == Nutral())
        return rv;
    if(rv == Nutral())
        return lv;
    return merge(lv,rv);
}

void solve()
{
    int n;cin>>n;
    f(i,0,n)cin>>a[i];
    f(i,0,n)update(0,0,n-1,i);
    int m;cin>>m;
    while(m--)
    {
        int q,l,r;
        cin>>q>>l>>r;
        if(q == 0)
        {
            a[l-1] = r;
            update(0,0,n-1,l-1);
        }
        else
        {
            int res = access(0,0,n-1,l-1,r-1);
            if((l-1)%2 == 0)
                cout<<res;
            else
            {
                cout<<-res;
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