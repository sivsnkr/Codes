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
    test
    {
        int n;cin>>n;
        string s;cin>>s;
        if(n%2)
        {
            // ra
            bool is = 0;
            for(int i = 0; i < n; i+=2)
            {
                int te = s[i]-48;
                if(te%2)
                    is = 1;
            }
            if(is)
                cout<<1;
            else
                cout<<2;
        }
        else
        {
            bool is = 0;
            for(int i = 1; i < n; i+=2)
            {
                int te = s[i]-48;
                if(te%2 == 0)
                    is = 1;
            }
            if(is)
                cout<<2;
            else
                cout<<1;
        }
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