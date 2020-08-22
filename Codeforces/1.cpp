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
    vector<int> dp(n,0);
    int q;cin>>q;
    while(q--)
    {
        int x;cin>>x;
        x--;
        dp[x]++;
        dp[n-x-1]--;
    }
    f(i,1,n)
        dp[i]+=dp[i-1];
    // f(i,0,n)
    //     cout<<dp[i]<<" \n"[i==n-1];
    f(i,0,n)
        if(dp[i]%2 && i < n-i-1)
        {
            swap(s[i],s[n-i-1]);
        }
    cout<<s<<NL;
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