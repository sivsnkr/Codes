#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; scanf("%d",&t); while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

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
        n = (int)a.size();
        A = a;
        st.assign(4*n,0);
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
    if(L == R)
    {
        st[p] = L;
        return;
    }
    build(left(p),L,(L+R)/2);
    build(right(p),(L+R)/2+1,R);
    int p1 = st[right(p)],p2 = st[left(p)];
    st[p] = (A[p1] >= A[p2])?p2:p1;
}

int Segment_tree::Access(int p,int i, int j, int L, int R)
{
    if(i > R || j < L)
        return -1;
    if(L>=i && R <= j)
        return st[p];
    int p1 = Access(left(p),i,j,L,(L+R)/2);
    int p2 = Access(right(p),i,j,(L+R)/2+1,R);
    if(p1 == -1)return p2;
    if(p2 == -1)return p1;
    return (A[p1]>=A[p2])?p2:p1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int arr[9] = {10, 2, 47, 3, 7, 9, 1, 98, 21};
    vector<int> A(arr, arr + 9);
    Segment_tree st(A);
    int i = st.access(1,1);
    int j = st.access(3,8);
    printf("i %d\n",A[i]);
    printf("j %d\n",A[j]);
    st.update(6,100);
    A[6] = 100;
    i = st.access(1,1);
    j = st.access(6,6);
    printf("i %d\n",A[i]);
    printf("j %d\n",A[j]);
    return 0;
}