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
#define pb push_back
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

inline void solve()
{
    // all the code goes here
    string s;cin>>s;
    s+='$';
    int n = size(s);
    vector<int> p(n),c(n);
    {
        // for k = 0
        vector<pair<char,int>> a(n);
        f(i,0,n)a[i] = {s[i],i};
        sort(all(a));
        f(i,0,n)p[i] = a[i].second;
        c[p[0]] = 0;
        f(i,1,n)
        {
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else 
                c[p[i]] = c[p[i-1]]+1;
        }
    }
    
    int k = 0;
    while(((int)1<<k) < n)
    {
        vector<pair<pair<int,int>,int>> a(n);
        f(i,0,n)
        {
            a[i] = {{c[i],c[(i+((int)1<<k))%n]},i};
        }
        sort(all(a));
        f(i,0,n)p[i] = a[i].second;
        c[p[0]] = 0;
        f(i,1,n)
        {
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else 
                c[p[i]] = c[p[i-1]]+1;
        }
        k++;
    }
    f(i,0,n)
        cout<<p[i]<<" ";
    cout<<NL;
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