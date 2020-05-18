#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

class Segment_tree
{
    private:
    vector<int> A,st;
    int n;
    int Access(int p, int l, int r, int i, int j);
    void Form(int p, int l, int r);
    int left(int p){return p<<1;}
    int right(int p){return (p<<1)+1;}
    public:
    Segment_tree(vector<int> &a)
    {
        n = a.size();
        A = a;
        st.assign(4*n,0);
        Form(1,0,n-1);
    }
    int access(int i, int j){return Access(1,0,n-1,i,j);}
};

void Segment_tree::Form(int p, int l, int r)
{
    if(l == r)
    {
        st[p] = A[l];
        return;
    }
    Form(left(p),l,(l+r)/2);
    Form(right(p),(l+r)/2+1,r);
    int lp = left(p),rp = right(p);
    st[p] = st[lp]+st[rp];
    return;
}

int Segment_tree::Access(int p, int l, int r, int i, int j)
{
    if(r < i || l > j)
        return -1;
    if(l >= i && r <= j)
        return st[p];
    
    int v1 = Access(left(p),l,(l+r)/2,i,j);
    int v2 = Access(right(p),(l+r)/2+1,r,i,j);
    int sum = 0;
    if(v1 != -1)
        sum+=v1;
    if(v2 != -1)
        sum+=v2;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    vector<int> A = {1,2,3,4,5,6,7};
    Segment_tree sum(A);
    printf("1 3 -  %d\n",sum.access(2,4));
    return 0;
}