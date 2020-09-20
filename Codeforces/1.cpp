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
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
    int n;cin>>n;
    vector<int> a(n);
    read(a);
    // sort(all(a),greater<int>());
    multiset<int> st;
    f(i,0,n)
        st.insert(a[i]);
    int i = 0,j = n-2;
    vector<int> res(n,-1);
    for(int i = 0; i < n; i+=2)
    {
        int it = *st.begin();
        st.erase(st.begin());
        res[i] = it;
    }

    f(i,0,n)
    {
        if(res[i] == -1)
        {
            int it = *st.begin();
            st.erase(st.begin());
            res[i] = it;
        }
    }
    int co = 0;
    f(i,1,n-1)
        if(res[i] < res[i-1] && res[i] < res[i+1])
            co++;
    cout<<co<<NL;
    f(i,0,n)
        cout<<res[i]<<" \n"[i==n-1];
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