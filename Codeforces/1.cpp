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
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

int s,w;
int p,f;
tuple<int,int,int> so(int cnts,int cntw, int lim)
{
    int c1s = 0,c1w = 0;
    int msc = 0;
    f(i,0,cnts+1)
    {
        int w1 = i*s;
        int w2 = (min((lim-w1)/w,cntw))*w;
        if(w1+w2 <= lim)
        {
            if(msc < i+min((lim-w1)/w,cntw))
            {
                c1s = i;
                c1w = min((lim-w1)/w,cntw);
                msc = c1s+c1w;
            }
        }
    }
    return {msc,c1s,c1w};
}

inline void solve()
{
    // all the code goes here
    test
    {
        cin>>p>>f;
        int cnts,cntw;cin>>cnts>>cntw;
        cin>>s>>w;
        if(min(s,w) != s)
        {
            swap(s,w);
            swap(cnts,cntw);
        }
        auto [msc,c1s,c1w] = so(cnts,cntw,p);
        auto [msc1,c2s,c2w] = so(cnts-c1s,cntw-c1w,f);
        auto [msc11,c11s,c11w] = so(cnts,cntw,f);
        auto [msc12,c21s,c21w] = so(cnts-c11s,cntw-c11w,p);
        cout<<max(msc+msc1,msc11+msc12)<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        fh;
    #endif
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}