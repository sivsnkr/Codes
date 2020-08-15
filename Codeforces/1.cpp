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
    int r,g,b;cin>>r>>g>>b;
    vector<multiset<int,greater<int>>> ar(3);
    f(i,0,r)
    {
        int x;cin>>x;
        ar[0].insert(x);
    }
    f(i,0,g)
    {
        int x;cin>>x;
        ar[1].insert(x);
    }
    f(i,0,b)
    {
        int x;cin>>x;
        ar[2].insert(x);
    }
    int sum = 0;
    while (true)
    {
        int mx = -3;
        int sum1 = -1;
        if(size(ar[0]) > 0 && size(ar[1]) > 0)
            sum1 = *ar[0].begin()*(*ar[1].begin());
        int sum2 = -1;
        if(size(ar[0]) > 0 && size(ar[2]) > 0)
            sum2 = *ar[0].begin()*(*ar[2].begin());
        int sum3 = -1;
        if(size(ar[2]) > 0 && size(ar[1]) > 0)
            sum3 = *ar[2].begin()*(*ar[1].begin());
        mx = max({sum1,sum2,sum3});
        // cout<<mx<<NL;
        if(mx == -1)
            break;
        sum+=mx;
        if(mx == sum1)
        {
            ar[0].erase(ar[0].begin());
            ar[1].erase(ar[1].begin());
        }
        else if(mx == sum2)
        {
            ar[0].erase(ar[0].begin());
            ar[2].erase(ar[2].begin());
        }
        else
        {
            ar[2].erase(ar[2].begin());
            ar[1].erase(ar[1].begin());
        }
    }
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