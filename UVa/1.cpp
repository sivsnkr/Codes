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
vector<int> p(1000),g(1000);
int parent(int n)
{
    if(p[n] == n)
        return n;
    return parent(p[n]);
}

void Union(int x, int y)
{
    int p1 = parent(x);
    int p2 = parent(y);

    if(p1 != p2)
    {
        p[p1] = p2;
        g[p1]+=g[p2];
    }
    cout<<g[p1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test{
        int n,a=0;
        cin>>n;
        map<string,int> st;
        f(i,0,n)
        {
            string s1,s2;
            cin>>s1>>s2;
            if(st.find(s) == st.end())
            {
                st[a] = a;
            }
        }
    }
    return 0;
}