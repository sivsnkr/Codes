#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define testf int t; scanf("%d",&t); while(t--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define size(container) (int)container.size()
#define int long long int
int n;
int a[100001];
bool in = 1,d = 1;
int start = 0;
vector<int> res;
set<int> r;

void ins(int i)
{
    if(a[i] >= a[i-1])
    {
        if(!in)
        {
            if(r.find(a[start]) == r.end())
                res.push_back(a[start]);
            r.insert(a[start]);
            if(r.find(a[i-1]) == r.end())
                res.push_back(a[i-1]);
            r.insert(a[i-1]);
            start = i-1;
        }
        in = 1;
        d = 0;
    }
    else
    {
        if(!d)
        {
            if(r.find(a[start]) == r.end())
                res.push_back(a[start]);
            r.insert(a[start]);
            if(r.find(a[i-1]) == r.end())
                res.push_back(a[i-1]);
            r.insert(a[i-1]);
            start = i-1;
        }
        d = 1;
        in = 0;
    }
}
void solve()
{
    test{
        cin>>n;
        start = 0;
        in = 1,d = 1;
        res.clear(),r.clear();
        f(i,0,n)
            cin>>a[i];
        
        f(i,1,n)
        {
            ins(i);
        }
        if(r.find(a[start]) == r.end())
            res.push_back(a[start]);
        r.insert(a[start]);
        if(r.find(a[n-1]) == r.end())
            res.push_back(a[n-1]);
        cout<<size(res)<<NL;
        for(int it : res)
            cout<<it<<" ";
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