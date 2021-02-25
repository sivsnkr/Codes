#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

const int mod = 998244353;
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
//        build(1,0,n-1);
    }
    int access(int i, int j){return Access(1,i,j,0,n-1);}
    void update(int i, int value){A[i] = value;Update(1,i,0,n-1);}
};

void Segment_tree::Update(int p,int i, int L, int R)
{
    if(i<L || i > R)
        return;
    if(L==R) {
        st[p] = A[L];
        return;
    }
    Update(left(p),i,L,(L+R)/2);
    Update(right(p),i,(L+R)/2+1,R);
    int p1 = st[left(p)];
    int p2 = st[right(p)];
    st[p] = p1+p2;
}

//void Segment_tree::build(int p, int L, int R)
//{
//    if(L == R)
//    {
//        st[p] = L;
//        return;
//    }
//    build(left(p),L,(L+R)/2);
//    build(right(p),(L+R)/2+1,R);
//    int p1 = st[right(p)],p2 = st[left(p)];
//    st[p] = (A[p1] >= A[p2])?p2:p1;
//}

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
    return p1+p2;
}

inline void solve()
{
    // let's code
    test
    {
        int n, k;
        cin >> n >> k;
        class Segment_tree rq(vector<int>(n+1,0));
        vector<int> a(n), b(k);
        map<int, int> ind;
        read(a);
        read(b);
        set<int> st;
        for (int i = 0; i < n; i++)
            ind[a[i]] = i;
        for (int i = 0; i < k; i++)
            st.insert(b[i]);

        int cnt = -1;
        int i = 0;
        while (!st.empty()) {
            int be = b[i];
            st.erase(be);
            int in = ind[be];
            int deleted_element = rq.access(1,be);
//            in
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
