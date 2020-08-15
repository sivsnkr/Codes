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

int n,m,arr[300000];
int k,x,z;

inline void solve()
{
    // all the code goes here
    cin>>n>>m>>k;
    f(i,0,m)cin>>arr[i];
    int ans=0;
    z=k;
    int rem=0;
    int cur=-1;
    while(cur<m-1){
        int ind=upper_bound(arr,arr+m,z+rem)-arr;
        ind--;
        if (ind!=cur)
        {
            rem+=ind-cur;
            cur=ind;
            ans++;
        }
        else {
            x=arr[cur+1]-z-rem;
            x=ceil(1.0*x/k);
            z+=k*x;
        }
    }
    cout<<ans;
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