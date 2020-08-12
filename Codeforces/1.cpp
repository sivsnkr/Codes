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

void solve()
{
    #ifndef ONLINE_JUDGE
        fh;
    #endif
    // all the code goes here
    int n;
    long double m;
    cin>>n>>m;
    vector<long double> a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];
    long double sum = m/(1+b[0]);
    fr(i,n-1,1)
    {
        sum+=((m+sum)/(1+a[i]));
        sum+=((m+sum)/(1+b[i]));
    }
    sum+=(m+sum)/(1+a[0]);
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