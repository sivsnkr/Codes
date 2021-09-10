#include <bits/stdc++.h>
using namespace std;

class Segment_tree
{
    // 0 based indexing
    private:
    vector<int> A,st;
    int n;
    void build(int p, int L, int R);
    int Access(int p,int i, int j, int L , int R);
    void Update(int p,int i,int L, int R);
    inline int func(int a, int b){
        // implement your func for combining the seg tree here
        return gcd(a,b);
    }
    public:
    Segment_tree(const vector<int> &a)
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
    if(i < L || i > R)
        return;
    if(L == R){
        st[p] = A[L];
        return;
    }
    int left = (p << 1), right = (p << 1) + 1;
    Update(left,i,L,(L+R)/2);
    Update(right,i,(L+R)/2+1,R);
    int p1 = st[left];
    int p2 = st[right];
    st[p] = func(p1,p2);
}

void Segment_tree::build(int p, int L, int R)
{
    if(L == R)
    {
        st[p] = A[L];
        return;
    }
    int left = (p << 1), right = (p << 1) + 1;
    build(left, L, (L+R)/2);
    build(right, (L+R)/2+1, R);
    int p1 = st[right],p2 = st[left];
    st[p] = func(p1,p2);
}

int Segment_tree::Access(int p,int i, int j, int L, int R)
{
    if(i > R || j < L)
        return -1;
    if(L>=i && R <= j)
        return st[p];
    
    int mid = (L + R) / 2, p1 = -1, p2 = -1;
    int left = (p << 1), right = (p << 1) + 1;

    if(i >= L && j <= mid){
        p1 = Access(left,i,j,L,mid);
    }
    if(i >= mid + 1 && j <= R){
        p2 = Access(right,i,j,mid+1,R);
    }
    if(p1 == -1)return p2;
    if(p2 == -1)return p1;
    return func(p1,p2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
}