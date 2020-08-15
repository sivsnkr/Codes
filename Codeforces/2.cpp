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
void readarray(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}
multiset<int,greater<int>> fi,se;
int calc()
{
    int sum = 0;
    while(size(se) > 0 && size(fi) > 0)
    {
        sum+=(*se.begin()*(*fi.begin()));
        se.erase(se.begin());
        fi.erase(fi.begin());
    }
    return sum;
}

void solve()
{
    #ifndef ONLINE_JUDGE
        fh;
    #endif
    // all the code goes here
    int r,g,b;cin>>r>>g>>b;
    multiset<int,greater<int>>rv,gv,bv;
    f(i,0,r)
    {
        int x;cin>>x;
        rv.insert(x);
    }
    f(i,0,g)
    {
        int x;cin>>x;
        gv.insert(x);
    }
    f(i,0,b)
    {
        int x;cin>>x;
        bv.insert(x);
    }
    int sum = 0;
    fi.clear(),se.clear();
    fi = rv;
    merge(all(gv),all(bv),inserter(se,se.begin()));
    sum = max(sum,calc());
    // cout<<sum<<NL;
    fi.clear(),se.clear();
    fi = gv;
    merge(all(rv),all(bv),inserter(se,se.begin()));
    sum = max(sum,calc());
    // cout<<sum<<NL;
    fi.clear(),se.clear();
    fi = bv;
    merge(all(rv),all(gv),inserter(se,se.begin()));
    sum = max(sum,calc());
    cout<<sum<<NL;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}