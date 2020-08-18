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
    int a,b,c,d;
    cout<<"? 1 2"<<NL;
    fflush(stdout);
    cin>>a;
    cout<<"? 2 3"<<NL;
    fflush(stdout);
    cin>>b;
    cout<<"? 3 4"<<NL;
    fflush(stdout);
    cin>>c;
    cout<<"? 4 5"<<NL;
    fflush(stdout);
    cin>>d;
    vector<int> res(6);
    if(a%23 == 0 && b%23 == 0)
        res[1] = 23;
    else if(b%23 == 0 && c%23 == 0)
        res[2] = 23;
    else if(c%23 == 0 && d%23 == 0)
        res[3] = 23;
    else if(a%23 == 0)
        res[0] = 23;
    else if(d%23 == 0)
        res[4]= 23;
    else
        res[5] = 23;
    
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