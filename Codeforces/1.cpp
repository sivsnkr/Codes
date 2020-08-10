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

int fac(int n)
{
    int p = 1;
    f(i,1,n+1)
    {
        p*=i;
        p%=mod;
    }
    return p;
}

void solve()
{
    // fh;// comment this line before submitting to online judge
    // all the code goes here
    int n;cin>>n;
    int res = n*(n-1);
    res%=mod;
    res*=(n-2);;
    res/=6;
    res%=mod;
    res*=2;
    res*=fac(n-2);
    res%=mod;
    res*=fac(n-3);
    res%=mod;
    cout<<res<<NL;
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