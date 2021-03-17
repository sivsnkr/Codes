#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

class Segment_tree
{
private:
    vector<int> A,st,lazy;
    int n;
    int left(int p){return p<<1;}
    int right(int p){return (p<<1)+1;}
    void build(int p, int L, int R);
    int Access(int p,int i, int j, int L , int R);
    void Update(int p,int l,int r,int L, int R,int value);
public:
    Segment_tree(vector<int> a)
    {
        n = (int)a.size();
        A = a;
        st.assign(4*n,0);
        lazy.assign(4*n,-1);
        build(1,0,n-1);
    }
    int access(int i, int j){return Access(1,i,j,0,n-1);}
    void update(int l, int r, int value){Update(1,l,r,0,n-1,value);}
};

void Segment_tree::Update(int p,int l, int r, int L, int R, int value)
{
    if(lazy[p] != -1){
        st[p] = (R-L+1)*lazy[p];
        if(L != R){
            lazy[left(p)] = lazy[p];
            lazy[right(p)] = lazy[p];
        }
        lazy[p] = -1;
    }

    if(L > r || R < l)
        return;
    if(L >= l && R <= r){
        st[p] = (R-L+1)*value;
        if(L != R) {
            lazy[left(p)] = value;
            lazy[right(p)] = value;
        }
        return;
    }

    Update(left(p),l,r,L,(L+R)/2,value);
    Update(right(p),l,r,(L+R)/2+1,R,value);

    st[p] = st[right(p)]+st[left(p)];
}

void Segment_tree::build(int p, int L, int R)
{
    if(L == R)
    {
        st[p] = A[L];
        return;
    }
    build(left(p),L,(L+R)/2);
    build(right(p),(L+R)/2+1,R);
    int p1 = st[right(p)],p2 = st[left(p)];
    st[p] = p1+p2;
}

int Segment_tree::Access(int p,int i, int j, int L, int R)
{
    if(lazy[p] != -1){
        st[p] = (R-L+1)*lazy[p];
        if(L != R){
            lazy[left(p)] = lazy[p];
            lazy[right(p)] = lazy[p];
        }
        lazy[p] = -1;
    }

    if(L > j || R < i)
        return -1;

    if(L >= i && R <= j){
        return st[p];
    }

    int p1 = Access(left(p),i,j,L,(L+R)/2);
    int p2 = Access(right(p),i,j,(L+R)/2+1,R);
    if(p1 == -1)return p2;
    if(p2 == -1)return p1;
    return p1+p2;
}

inline void solve()
{
    test{
        int n,q;cin>>n>>q;
        string s,t;cin>>s>>t;
        vector<pair<int,int>> qu(q);
        for(int i = 0; i < q; i++)cin>>qu[i].first>>qu[i].second,qu[i].first--,qu[i].second--;
        reverse(all(qu));

        bool valid = 1;
        vector<int> a(n);
        for(int i = 0; i < n; i++)a[i] = t[i]-'0';
        class Segment_tree st(a);
        for(auto [x,y] : qu){
            int sum = st.access(x,y);
            int z = (y-x+1)-sum,o = sum;
            if(o == z){
                valid = 0;
                break;
            }
//            cout<<"sum "<<sum<<NL;
            if(o > z)st.update(x,y,1);
            else st.update(x,y,0);
        }

        for(int i = 0; i < n; i++){
            int val = s[i] - '0';
//            cout<<"val "<<st.access(i,i)<<NL;
            if(st.access(i,i) != val)
                valid = 0;
        }
//        cout<<"val "<<res<<NL;
        if(!valid)cout<<"NO";
        else cout<<"YES";
        cout<<NL;
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
