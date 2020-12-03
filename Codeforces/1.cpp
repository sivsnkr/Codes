#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
void read(vector<int> &a);
const int MX = 1e5+5;
vector<vector<int>> g(MX);
vector<int> elein(MX);
vector<pair<int,int>> range(MX);
int timer;
const int inf = 1e17;
void dfs(int root, int par)
{
    range[root].first = timer;
    elein[root] = timer++;
    for(int i : g[root])
    {
        if(i != par)
        {
            dfs(i,root);
        }
    }
    range[root].second = timer-1;
}

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
    Segment_tree(int size)
    {
        n = size;
        A.assign(n,0);
        st.assign(4*n,0);
        // build(1,0,n-1);
    }
    int access(int i, int j){return Access(1,i,j,0,n-1);}
    void update(int i, int value){A[i] = value;Update(1,i,0,n-1);}
};

void Segment_tree::Update(int p,int i, int L, int R)
{
    if(i < L || i > R)
        return;
    if(L == R)
    {
        st[p] += A[L];
        return;
    }
    Update(left(p),i,L,(L+R)/2);
    Update(right(p),i,(L+R)/2+1,R);
    int p1 = st[left(p)];
    int p2 = st[right(p)];
    st[p] = p1+p2;
}

int Segment_tree::Access(int p,int i, int j, int L, int R)
{
    if(i > R || j < L)
        return -inf;
    if(L>=i && R <= j)
        return st[p];
    int p1 = Access(left(p),i,j,L,(L+R)/2);
    int p2 = Access(right(p),i,j,(L+R)/2+1,R);
    // cout<<p1<<" "<<p2<<NL;
    if(p1 == -inf)return p2;
    if(p2 == -inf)return p1;
    return p1+p2;
}

bool is_par(pair<int,int> a, pair<int,int> b)
{
	if(a.first <= b.first && a.second >= b.second)
		return true;
	return false;
}

inline void solve()
{
    // all the code goes here
	test
	{
		timer = 0;
		int n,q;cin>>n>>q;
		f(i,0,n+1)
			g[i].clear();
		f(i,0,n-1)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y),g[y].push_back(x);
		}
		dfs(1,1);
		class Segment_tree st(n+1);
		while(q-- > 0)
		{
			int a,b,x;
			cin>>a>>b>>x;
			if(x == 0)
			{
				if(is_par(range[a],range[b]))
				{
					cout<<abs(st.access(range[b].first,range[b].second))<<NL;
				}
				else
				{
					cout<<abs(st.access(range[a].first,range[a].second))<<NL;
				}
				
			}
			else
			{
				st.update(elein[a],x);
				st.update(elein[b],-x);
			}
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}