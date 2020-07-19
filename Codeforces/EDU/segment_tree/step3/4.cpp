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

vector<int> stree(800001);
vector<int> a(200001);

int merge(int a, int b)
{
    return a+b;
}

int single(int v)
{
    return v;
}

int Nutral()
{
    return -1;
}

void update(int p, int l,int r, int v,int i)
{
    if(l > i || r < i)
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
        return stree[p];
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
    vector<int> b(2*n);
    f(i,0,2*n)cin>>b[i];
    a.assign(2*n,1);
    f(i,0,2*n)
        update(0,0,2*n-1,a[i],i);
    vector<int> res(n,0);
    map<int,int> st;
    f(i,0,2*n)
    {
        if(st.find(b[i]) != st.end())
        {
            update(0,0,2*n-1,0,st[b[i]]);
            update(0,0,2*n-1,0,i);
            int r = access(0,0,2*n-1,st[b[i]],i);
            res[b[i]-1] += r;
        }
        else
        {
            st.insert({b[i],i});
        } 
    }
    f(i,0,2*n)
        update(0,0,2*n-1,1,i);
    st.clear();
    fr(i,2*n-1,0)
    {
        if(st.find(b[i]) != st.end())
        {
            update(0,0,2*n-1,0,st[b[i]]);
            update(0,0,2*n-1,0,i);
            int r = access(0,0,2*n-1,i,st[b[i]]);
            res[b[i]-1] += r;
        }
        else
        {
            st.insert({b[i],i});
        } 
    }
    for(int i : res)
    {
        cout<<i<<" ";
    }
    cout<<NL;
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