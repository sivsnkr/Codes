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

void solve()
{
    fh;// comment this line before submitting to online judge
    // all the code goes here
    test
    {
        int n,k;cin>>n>>k;
        vector<int> a(n);
        f(i,0,n)cin>>a[i];
        // int sum = 0;
        // f(i,0,n)sum+=a[i];
        // int x = 0;
        // f(i,0,n-1)
        // {
        //     sum+=x;
        //     x++;
        // }
        // while(sum % k != 0)
        // {
        //     x++;
        //     sum+=x;
        //     cout<<"sum "<<sum<<NL;
        // }
        // cout<<x+1<<NL;
        vector<int> re
    }
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