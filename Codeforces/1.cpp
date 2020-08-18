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
    int n;cin>>n;
    vector<int> a(n);readarray(a);
    map<int,int> st;
    fr(i,n-1,0)
    {
        st[a[i]]++;
        int mi = LLONG_MAX;
        for(int k : {4,8,15,16,23,42})
        {
            if(k > a[i])
                break;
            st[k] = min(st[a[i]],st[k]);
        }
    }
    int mi = LLONG_MAX;
    for(int k : {4,8,15,16,23,42})
    {
        cout<<k<<" "<<st[k]<<NL;
        mi = min(mi,st[k]);
    }
    int sum = n-mi*6;
    cout<<sum;
    
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