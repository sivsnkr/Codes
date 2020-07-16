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
vector<pair<int,int>> stree(400001);
vector<int> a(100001);
int n;

void update(int i, int value, int p, int l, int r)
{
    if(l > i || r < i)
        return;
    if(l == r)
    {
        stree[p] = {a[l],1};
        return;
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    update(i,value,left,l,(l+r)/2);
    update(i,value,right,(l+r)/2+1,r);
    if(stree[left].first > stree[right].first)
        stree[p] = stree[right];
    else if(stree[left].first < stree[right].first)
        stree[p] = stree[left];
    else
    {
        stree[p] = {stree[left].first,stree[left].second+stree[right].second};
    }
}

void build()
{
    f(i,0,n)
    {
        update(i,a[i],0,0,n-1);
    }
}

pair<int,int> access(int p, int l, int r, int L, int R)
{
    if(l > R || r < L)
        return {-1,-1};
    if(l >= L && r <= R)
    {
        return stree[p];
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    pair<int,int> li = access(left,l,(l+r)/2,L,R);
    pair<int,int> ri = access(right,(l+r)/2+1,r,L,R);
    if(li.first == -1)
        return ri;
    if(ri.first == -1)
        return li;
    if(li.first > ri.first)
        return ri;
    else if(li.first < ri.first)
        return li;
    return {li.first,li.second+ri.second};
}

void solve()
{
    int m;
    cin>>n>>m;
    f(i,0,n)cin>>a[i];
    build();
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
            pair<int,int> res = access(0,0,n-1,s,b-1);
            cout<<res.first<<" "<<res.second<<NL;
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