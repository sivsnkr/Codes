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
    test
    {
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int co = 0;
        vector<bool> vis(n,0);
        f(i,0,n/2)
        {
            if(!vis[i])
            {
                char c = s[i],c1 = s[n-1-i];
                int co1 = 0,co2 = 0;
                for(int j = i; j < n; j+=k)
                {
                    if(s[j] != c)
                        co1++;
                    if(s[j] != c1)
                        co2++;
                    vis[j] = 1;
                }
                c = co1>co2?c1:c;
                for(int j = i; j < n; j+=k)
                {
                    s[j] = c;
                }
                co+=min(co1,co2);
            }
        }
        cout<<co<<NL;
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