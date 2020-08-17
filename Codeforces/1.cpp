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
        int n;cin>>n;
        vector<int> a(n);readarray(a);
        map<int,int> st;
        f(i,0,n)
            st[a[i]]++;
        multiset<int,greater<int>> ste;
        for(pair<int,int> a : st)
            ste.insert(a.second);
        set<int> st1;
        int sum = 0;
        for(int i : ste)
        {
            if(st1.empty())
            {
                sum+=i;
                st1.insert(i);
            }
            else if(i >= *st1.begin())
            {
                int v = *st1.begin();
                if(v-1 > 0)
                {
                    sum += v-1;
                    st1.insert(v-1);
                }
            }
            else
            {
                sum+=i;
                st1.insert(i);
            }
        }
        cout<<sum<<NL;
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