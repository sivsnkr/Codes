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

int n;
vector<int> a(2e6);
bool check(int mid)
{
    bool valid = 1;
    f(i,0,n)
    {
        if(i > mid)
        {
            if(a[i] < n-1-i)
                valid = 0;
            continue;
        }
        if(a[i] < i)
            valid = 0;
    }
    return valid;
}

inline void solve()
{
    // all the code goes here
    test
    {
        cin>>n;
        f(i,0,n)cin>>a[i];
        bool valid = check((n-1)/2);
        valid = valid || check(n/2);
        if(!valid)
            cout<<"No";
        else 
            cout<<"Yes";
        cout<<NL;
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