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

inline void solve()
{
    // all the code goes here
    string s;cin>>s;
    int n = s.length();
    int sum = 0;
    int w = 0,o = 0;
    vector<int> dp(n);
    f(i,0,n-1)
    {
        if(s[i] == 'o')
        {
            dp[i] = w;
        }
        if(s[i] == s[i+1] && s[i] == 'v')
        {
            w++;
        }
    }
    w = 0;
    fr(i,n-1,1)
    {
        if(s[i] == s[i-1] && s[i] == 'v')
            w++;
        if(s[i] == 'o' && w > 0)
            sum+=dp[i];
    }
    cout<<sum<<NL;
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