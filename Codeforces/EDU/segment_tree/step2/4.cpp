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
// #define int long long int

// struct ele
// {
//     int seg,pref,suf,sum;
// };
typedef int ele;
vector<ele> stree(400001);
vector<int> a(100001);

ele single(int v)
{
    return v;
}

ele Nutral()
{
    return -1;
}

ele merge(ele i, ele j)
{
    return a[i]>=a[j]?i:j;
}

void update(int p, int l, int r,int i)
{
    if(r < i || l > i)
        return;
    if(l == r)
    {
        stree[p] = single(l);
        return;
    }
    int left = (p<<1)+1,right = (p<<1)+2;
    update(left,l,(l+r)/2,i);
    update(right,(l+r)/2+1,r,i);
    stree[p] = merge(stree[left],stree[right]);
}

// ele access(int p, int l, int r, int L, int R)
// {
   
//     if(r < L || l > R)
//         return Nutral();
//     if(l >= L && r <= R)
//         return stree[p];
//     int left = (p<<1)+1,right = (p<<1)+2;
//     ele lv = access(left,l,(l+r)/2,L,R);
//     ele rv = access(right,(l+r)/2+1,r,L,R);
//     if(lv.seg == Nutral().seg)
//         return rv;
//     if(rv.seg == Nutral().seg)
//         return lv;
//     return merge(lv,rv);
// }

int find(int p,int l, int r, int x,int L)
{
    if(a[stree[p]] < x || (l < L && r < L))
        return Nutral();
    // cout<<l<<" "<<r<<NL;
    if(l == r)
        return l;
    int left = (p<<1)+1,right = (p<<1)+2;
    ele lv = find(left,l,(l+r)/2,x,L);
    if(lv == -1)
        return find(right,(l+r)/2+1,r,x,L);
    return lv;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    f(i,0,n)cin>>a[i];
    f(i,0,n)
        update(0,0,n-1,i);
    while(m--)
    {
        int q;cin>>q;
        if(q == 1)
        {
            int i,v;cin>>i>>v;
            a[i] = v;
            update(0,0,n-1,i);
        }
        else
        {
            int i,l;cin>>i>>l;
            int res = find(0,0,n-1,i,l);
            cout<<res<<NL;
            // if(a[res] >= i)
                
            // else
            // {
            //     cout<<-1;
            // }
            // cout<<NL;
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