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

int find(int p,int l, int r, int x)
{
    if(l == r)
        return l;
    int left = (p<<1)+1,right = (p<<1)+2;
    int xl = stree[left];
    if(xl >= x)
    {
        return find(left,l,(l+r)/2,x);
    }
    return find(right,(l+r)/2+1,r,x-xl);
}

void solve()
{
    int n;cin>>n;
    vector<int> b(n);
    f(i,0,n)cin>>b[i];
    reverse(all(b));
    a.assign(n,1);
    f(i,0,n)
        update(0,0,n-1,1,i);
    vector<int> res(n);
    f(i,0,n)
    {
        int l = find(0,0,n-1,b[i]+1);
        res[i] = n-l;
        update(0,0,n-1,0,l);
    }
    reverse(all(res));
    for(int i : res)
        cout<<i<<" ";
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