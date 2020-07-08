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
int n,q;
const int MX = 2e5+1;
vector<int> h(MX),te(MX);
class Segment_tree
{
    private:
    vector<int> A,st;
    int n;
    int left(int p){return p<<1;}
    int right(int p){return (p<<1)+1;}
    void build(int p, int L, int R);
    int Access(int p,int i, int j, int L , int R);
    void Update(int p,int i,int L, int R);
    public:
    Segment_tree(vector<int> a)
    {
        n = size(a);
        A = a;
        st.assign(8*n,0);
        build(1,0,n-1);
    }
    int access(int i, int j){return Access(1,i,j,0,n-1);}
    void update(int i, int value){A[i] = value;Update(1,i,0,n-1);}
};

void Segment_tree::Update(int p,int i, int L, int R)
{
    if(L==R || (i<L || i > R))
        return;
    Update(left(p),i,L,(L+R)/2);
    Update(right(p),i,(L+R)/2+1,R);
    int p1 = st[left(p)];
    int p2 = st[right(p)];
    st[p] = (A[p1]>=A[p2])?p2:p1;
}

void Segment_tree::build(int p, int L, int R)
{
    // cout<<L<<" "<<R<<NL;
    if(R == L)
    {
        st[p] = A[L];
        return;
    }
    if(R - L == 1)
    {
        build(left(p),L,(L+R)/2);
        build(right(p),(L+R)/2+1,R);
    }
    else
    {
        build(left(p),L,(L+R)/2);
        build(right(p),(L+R)/2,R);
    }
    // int p1 = right(p),p2 = left(p);
    cout<<L<<" "<<R<<NL;
    st[p] = A[L]-A[R];
    cout<<"val "<<st[p]<<NL;
}

int Segment_tree::Access(int p,int i, int j, int L, int R)
{
    if(i > R || j < L)
        return -1;
    if(L>=i && R <= j)
    {
        cout<<"L R"<<NL;
        cout<<L<<" "<<R<<NL;
        cout<<"st val "<<st[p]<<NL;
        if(st[p] <= 0)
            return 0;
        else
            return st[p];
    }
    int p1 = 0,p2 = 0;
    if(R - L == 1)
    {
        p1 = Access(left(p),i,j,L,(L+R)/2);
        p2 = Access(right(p),i,j,(L+R)/2+1,R);
    }
    else
    {
        p1 = Access(left(p),i,j,L,(L+R)/2);
        p2 = Access(right(p),i,j,(L+R)/2,R);
    }
    cout<<"p1 p2 "<<p1<<" "<<p2<<NL;
    return p1+p2;
}
void solve()
{
    cin>>n>>q;
    f(i,0,n)cin>>h[i];
    f(i,0,n)cin>>te[i];
    vector<int> mb(n),mbr(n),mbs(n),mbrs(n);
    mb[n-1] = LLONG_MAX;
    mbs[n-1] = LLONG_MAX;
    mbr[0] = LLONG_MIN;
    mbrs[0] = LLONG_MIN;
    stack<int> st;
    f(i,0,n)
    {
        while(!st.empty() && h[st.top()] <= h[i])
        {
            mb[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        mb[st.top()] = LLONG_MAX;
        st.pop();
    }

    f(i,0,n)
    {
        while(!st.empty() && h[st.top()] < h[i])
        {
            mbs[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        mbs[st.top()] = LLONG_MAX;
        st.pop();
    }

    fr(i,n-1,0)
    {
        while(!st.empty() && h[st.top()] <= h[i])
        {
            mbr[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        mbr[st.top()] = LLONG_MIN;
        st.pop();
    }

    fr(i,n-1,0)
    {
        while(!st.empty() && h[st.top()] < h[i])
        {
            mbrs[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        mbrs[st.top()] = LLONG_MIN;
        st.pop();
    }

    vector<int> cf(n,0),cb(n,0);
    f(i,0,n)
    {
        cf[i] = te[i];
        cb[i] = te[i];
    }
    fr(i,n-1,0)
    {
        if(mbs[i] < n)
        {
            cf[i]+=cf[mbs[i]];
        }
    }

    f(i,0,n)
    {
        if(mbrs[i] > -1)
        {
            cb[i]+=cb[mbrs[i]];
        }
    }
    Segment_tree cft(cf);
    while(q--)
    {
        int qt,a,b;
        cin>>qt>>a>>b;
        a--,b--;
        if(qt == 1)
        {
            
        }
        else
        {
            if(a > b)
            {
                if(mbr[a] < b)
                {
                    // int res = cf[b]-cf[a]+te[a];
                    // cout<<"heee"<<NL;
                    int res = cft.access(b,a)+te[a];
                    cout<<res<<NL;
                }
                else
                {
                    cout<<-1<<NL;
                }
            }else
            {
                if(mb[a] > b)
                {
                    int res = cb[b]-cb[a]+te[a];
                    cout<<res<<NL;
                }
                else
                {
                    cout<<-1<<NL;
                }
            }
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