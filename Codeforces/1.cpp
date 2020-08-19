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
    test
    {
        int n,k;cin>>n>>k;
        vector<int> a(n);readarray(a);
        multiset<int> st;
        f(i,0,n)
            if(a[i]%k)
                st.insert((a[i]/k+1)*k-a[i]);
        int sum = 0;
        int x = 1;
        while(!st.empty())
        {
            int te = *st.begin();
            if(te == x)
            {
                st.erase(st.begin());
                x++;
            }
            else if(te < x)
            {
                st.erase(st.begin());
                st.insert(((te+x)/k+1)*k-(te+x));
                x++;
            }
            else
            {
                x = te;
                st.erase(st.begin());
            }

        for(int i : st)
            cout<<i<<" ";
        cout<<NL;
        }
        cout<<x+1<<NL;
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