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
vector<int> st;
vector<int> ar;
map<int,int> fr;

int left(int p){return p<<1;}
int right(int p){return (p<<1)+1;}

void form_sg(int p, int i, int j)
{
    if(i == j)
    {
        st[p] = i;
        return;
    }
    form_sg(left(p),i,(i+j)/2);
    form_sg(right(p),(i+j)/2+1,j);
    int l = st[left(p)],r = st[right(p)];
    st[p] = fr[ar[l]] >= fr[ar[r]]?l:r;
}

int access(int p, int i, int j,int l, int r)
{
    if(i > r || j < l)
    {
        return -1;
    }
    if(i>=l&&j<=r)
    {
        return st[p];
    }
    int le = access(left(p),i,(i+j)/2,l,r);
    int re = access(right(p),(i+j)/2+1,j,l,r);
    if(le == -1)
        return re;
    if(re == -1)
        return le;
    return fr[ar[le]]>=fr[ar[re]]?le:re;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int n,m;
    cin>>n>>m;
    ar.assign(n,0);
    for(int &it : ar)
    {
        cin>>it;
        fr[it]++;
    }
    st.assign(4*n,0);
    form_sg(1,0,n-1);
    f(i,0,m)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<fr[ar[access(1,0,n-1,l,r)]]<<endl;
    }
    return 0;
}