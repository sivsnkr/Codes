#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define PI 3.14159265
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
int mod = 1000000007;
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    vector<int> x(n);
    read(x);
    sort(all(x));
    int j = 0;
    vector<int> m(n,0);
    for(int i=1;i<n;i++)
        x[i]==x[i-1]?m[j]++:j++;
	int a=m[0]+1,b=m[1]+1;
	cout<<(a>=3?a*(a-1)*(a-2)/6:a==2?b:b>=2?b*(b-1)/2:m[2]+1);
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