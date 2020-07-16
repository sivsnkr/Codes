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

struct ele
{
    int seg,pref,suf,sum;
};
vector<ele> stree(400001);
vector<int> a(100001);

ele single(int v)
{
    if(v > 0)
        return{v,v,v,v};
    return {0,0,0,v};
}

ele Nutral()
{
    return {LLONG_MAX,LLONG_MAX,LLONG_MAX,LLONG_MAX};
}

ele merge(ele a, ele b)
{
    return {max({a.seg,b.seg,a.suf+b.pref}),max(a.pref,a.sum+b.pref),max(b.suf,b.sum+a.suf),a.sum+b.sum};
}

void update(int p, int l, int r,int i, int value)
{
    if(r < i || l > i)
        return;
    if(l == r)
    {
        stree[p] = single(value);
        return;
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    update(left,l,(l+r)/2,i,value);
    update(right,(l+r)/2+1,r,i,value);
    stree[p] = merge(stree[left],stree[right]);
}

ele access(int p, int l, int r, int L, int R)
{
   
    if(r < L || l > R)
        return Nutral();
    if(l >= L && r <= R)
        return stree[p];
    int left = (p<<1)+1,right = (p<<1)+2;
    ele lv = access(left,l,(l+r)/2,L,R);
    ele rv = access(right,(l+r)/2+1,r,L,R);
    if(lv.seg == Nutral().seg)
        return rv;
    if(rv.seg == Nutral().seg)
        return lv;
    return merge(lv,rv);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    f(i,0,n)cin>>a[i];
    f(i,0,n)
        update(0,0,n-1,i,a[i]);
    cout<<access(0,0,n-1,0,n-1).seg<<NL;
    while(m--)
    {
        int i,v;
        cin>>i>>v;
        a[i] = v;
        update(0,0,n-1,i,v);
        cout<<access(0,0,n-1,0,n-1).seg<<NL;
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