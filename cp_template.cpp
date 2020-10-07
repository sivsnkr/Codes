#include <bits/stdc++.h>
const char NL = '\n';
#define PI 3.14159265
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
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
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}