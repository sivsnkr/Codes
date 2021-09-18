#include<bits/stdc++.h>
using namespace std;

class Segment_tree
{
    // 0 based indexing
    private:
    vector<int> A,st, heights;
    int n;
    void build(int p, int L, int R);
    int Access(int p,int i, int j, int L , int R);
    inline int func(int a, int b){
        // implement your func for combining the seg tree here
        return (heights[a] > heights[b] ? b : a);
    }
    public:
    void init(const vector<int> &a, const vector<int> _heights)
    {
        n = (int)a.size();
        A = a;
        heights = _heights;
        st.assign(4*n,0);
        build(1,0,n-1);
    }
    int access(int i, int j){return Access(1,i,j,0,n-1);}
};

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

    if(!(i > mid || j < L)){
        p1 = Access(left,i,j,L,mid);
    }
    if(!(i > R || j < mid + 1)){
        p2 = Access(right,i,j,mid+1,R);
    }
    if(p1 == -1)return p2;
    if(p2 == -1)return p1;
    return func(p1,p2);
}

class LCA
{
    vector<int> euler,heights,first;
    vector<bool> visited;
    class Segment_tree st;
    int n;

    void dfs(const vector<vector<int>> &g, int root, int height){
        heights[root] = height;
        first[root] = (int)euler.size();
        visited[root] = 1;
        euler.push_back(root);

        for(int child : g[root]){
            if(!visited[child]){
                dfs(g, child, height + 1);
                euler.push_back(root);
            }
        }
    }

    public:
    LCA(const vector<vector<int>> &g, int root){
        n = (int)g.size();
        euler.reserve(2 * n + 5);
        heights.resize(n + 1);
        first.resize(n + 1);
        visited.assign(n + 1, 0);
        dfs(g, root, 0);
        st.init(euler, heights);
    }

    int access(int a, int b){
        int l = first[a], r = first[b];
        if(l > r)
            swap(l, r);
        return st.access(l, r);
    }
};

int main(){
    int n;cin>>n;
    vector<vector<int>> g(n + 1);

    for(int i = 0; i < n - 1; i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    class LCA st(g, 1);

    cout<<st.access(7, 4)<<"\n";
}
