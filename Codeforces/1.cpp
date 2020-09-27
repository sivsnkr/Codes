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
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
// #define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
int mod = 1000000007;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

#define pb insert
inline void solve()
{
    // all the code goes here
    test
    {
        int n;cin>>n;
        set<int> xl,xu,yl,yu;
        bool ok = 1;
        f(i,0,n)
        {
            int x,y;cin>>x>>y;
            int f1,f2,f3,f4;
            cin>>f1>>f2>>f3>>f4;
            if(f1 == 0)
            {
                if(size(xl) > 0 && x < *xl.rbegin())
                    ok = 0;
                xl.pb(x);
            }
            if(f2 == 0)
            {
                if(size(yu) > 0 && y > *yu.rbegin())
                    ok = 0;
                yu.pb(y);
            }
            if(f3 == 0)
            {
                if(size(xu) > 0 && x > *xu.rbegin())
                    ok = 0;
                xu.pb(x);
            }
            if(f4 == 0)
            {
                if(size(yl) > 0 && y < *yl.rbegin())
                    ok = 0;
                yl.pb(y);
            }
        }
        cout<<"ok "<<ok<<NL;
        cout<< *yu.begin()<<" "<<*yl.rbegin()<<NL;
        cout<< *xu.begin()<<" "<<*xl.rbegin()<<NL;
        if(!ok || (size(yu) > 0 && size(yl) > 0 && *yu.begin() < *yl.rbegin()) || (size(xu) > 0 && size(xl) > 0 && *xu.begin() < *xl.rbegin()))
            cout<<0;
        else
        {
            int x = size(xu) != 0 ? *xu.begin():size(xl) != 0 ?*xl.begin():0;
            int y = size(yu) != 0 ? *yu.begin():size(yl) != 0 ?*yl.begin():0;
            cout<<1<<" "<<x<<" "<<y;
        }
        cout<<NL;
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