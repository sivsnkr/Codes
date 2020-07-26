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

const int MX = 1e5+1;
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

void update(int p, int l, int r, int v, int i)
{
    if(r < i || l > i)
        return;
    if(l == r)
    {
        stree[p] = single(v);
        return;
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    update(left,l,(l+r)/2,v,i);
    update(right,(l+r)/2+1,r,v,i);
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
    vector<set<int>> st(41);
    int n,q;cin>>n>>q;
    vector<int> a(n);
    f(i,0,n)
    {
        cin>>a[i];
        st[a[i]].insert(n-i-1);
    }
    for(set<int> a : st)
    {
        for(int i : a)
            cout<<i<<" ";
        cout<<NL;
    }
    f(i,0,n)
    {   
        int v = 0;
        f(j,1,a[i]-1)
        {
            auto it =lower_bound(all(st[j]),n-i-1);
            v+=distance(st[j].begin(),it);
        }
        cout<<"V a[i]"<<v<<" "<<a[i]<<NL;
        update(0,0,n-1,v,i);
    }

    f(i,0,q)
    {
        int qi;cin>>qi;
        if(qi == 1)
        {
            int a,b;cin>>a>>b;
            int res = 0;
            res = access(0,0,n-1,a-1,b-1);
            cout<<res<<NL;
        }
        else
        {
            int x,y;cin>>x>>y;
            int v = 0;
            f(j,1,y-1)
            {
                v+=*st[j].lower_bound(x-1)-1;
            }
            update(0,0,n-1,v,x-1);
            a[x-1] = y;
            st[y].insert(n-x-1-1);
        }
    }
}

int32_t main()
{
    fh;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}