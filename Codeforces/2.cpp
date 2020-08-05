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

int make_a(string s,char b)
{
    if(s.length() == 1)
    {
        if(s[0] != b)
            return 1;
        return 0;
    }
    int n = s.length();
    int co1 = 0,co2 = 0;
    f(i,0,s.length()/2)
    {
        if(s[i] != b)
            co1++;
    }
    f(i,s.length()/2,s.length())
    {
        if(s[i] != b)
            co2++;
    }
    int res1 = co1+make_a(s.substr(n/2,n/2),b+1);
    int res2 = co2+make_a(s.substr(0,n/2),b+1);
    return min(res1,res2);
}

void solve()
{
    // fh;// comment this line before submitting to online judge
    // all the code goes here
    test
    {
        int n;cin>>n;
        string s;cin>>s;
        int co = make_a(s,'a');
        cout<<co<<NL;
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