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
    // fh;// comment this line before submitting to online judge
    // all the code goes here
    test
    {
        int n;cin>>n;
        string s;cin>>s;
        char c = 'z';
        int mi = -1;
        f(i,0,n)
            if(s[i] < c)
            {
                c = s[i];
                mi = i;
            }
        set<string> st;
        string te1 = "";
        f(i,0,n)
        {
            if(s[i] == c)
            {
                string te = s.substr(0,i+1);
                reverse(all(te));
                int j = 0;
                for(j = 0; j < min(te.length(),te1.length()); j++)
                {

                }
            }
        }
        te1 = *st.begin();
        int k = 0;
        f(i,0,n-k+1)
        {
            string st = s.substr(i,k);
            reverse(all(st));
            s = s.substr(0,i)+st+s.substr(i+k,n-i-k);
        }
        cout<<s<<NL;
        cout<<k<<NL;
    }
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