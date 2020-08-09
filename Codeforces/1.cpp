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
    string s;cin>>s;
    char mc = s[0];
    int in = 0;
    int n = s.length();
    f(i,0,n)
        if(s[i] <= mc)
        {
            mc = s[i];
            in = i;
        }
    f(i,0,n)
    {
        if(s[i] == mc)
        {
            cout<<1<<" ";
            swap(s[i],s[0]);
            continue;
        }

        if(s[i] > s[0] && i < in)
        {
            cout<<1<<" ";
            swap(s[i],s[0]);
        }
        else 
            cout<<0<<" ";
    }
    cout<<NL;
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