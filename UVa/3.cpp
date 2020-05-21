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

vector<int> nums;
class Segment_tree
{
    private:
    vector<int> st;
    int n;
    int left(int p){return p<<1;}
    int right(int p){return (p<<1)+1;}
    void form(int p,int l, int r);
    int Access(int p, int l, int r, int i, int j);
    void Update(int p, int l, int r, int j);
    public:
    Segment_tree(int size)
    {
        n = size;
        st.assign(4*n,0);
        form(1,0,n-1);
    }
    int access(int l, int r){return Access(1,0,n-1,l,r);}
    void update(int i){return Update(1,0,n-1,i);}
};

void Segment_tree::form(int p, int l, int r)
{
    if(l == r)
    {
        st[p] = nums[l];
        return;
    }
    form(left(p),l,(l+r)/2);
    form(right(p),(l+r)/2+1,r);
    st[p] = st[left(p)]+st[right(p)];
    return;
}

int Segment_tree::Access(int p, int l, int r, int i, int j)
{
    if(r < i || l > j)
        return -1;
    if(l>=i&&r<=j)
        return st[p];
    int s1 = Access(left(p),l,(l+r)/2,i,j);
    int s2 = Access(right(p),(l+r)/2+1,r,i,j);
    int sum = 0;
    if(s1 != -1)
        sum+=s1;
    if(s2 != -1)
        sum+=s2;
    return sum;
}

void Segment_tree::Update(int p, int l, int r, int j)
{
    if(r < j || l > j)
        return;
    if(l == r && l == j)
    {
        st[p] = nums[j];
        return;
    }
    Update(left(p),l,(l+r)/2,j);
    Update(right(p),(l+r)/2+1,r,j);
    st[p] = st[left(p)]+st[right(p)];
    return;
}

vector<string> split(string s,char a)
{
    int j = 0;
    int n = s.length();
    vector<string> res;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == a)
        {
            res.push_back(s.substr(j,i-j));
            j = i+1;
        }
    }
    res.push_back(s.substr(j,n-j));
    return res;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int t = 0;
    while(true)
    {
        int n;
        scanf("%d",&n);
        if(n == 0)
            return 0;
        nums.reserve(n);
        f(i,0,n)
            scanf("%d",&nums[i]);
        Segment_tree sums(n);
        string s;
        printf("\nCase %d:\n",t+1);
        while(true)
        {
            char ts[30];
            fgets(ts,30,stdin);
            s = "";
            f(i,0,strlen(ts)-1)
                s+=ts[i];
            if(s == "END")
                break;
            vector<string> st = split(s,' ');
            if(st[0] == "M")
            {
                int l = stoi(st[1]),r = stoi(st[2]);
                printf("%d\n",sums.access(l-1,r-1));
            }
            else if(st[0] == "S")
            {
                int in = stoi(st[1]),value = stoi(st[2]);
                nums[in-1] = value;
                sums.update(in-1);
            }
        }
        t++;
    }
    return 0;
}