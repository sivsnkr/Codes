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

void solve()
{
    fh;// comment this line before submitting to online judge
    // all the code goes here
    test
    {
        int n;cin>>n;
        vector<int> a(n);
        f(i,0,n)cin>>a[i];
        vector<int> b;
        b.push_back(a[0]);
        f(i,0,n-1)
        {
            if(a[i] > a[i+1])
                b.push_back(a[i]);
        }
        b.push_back(a[size(a)-1]);
        bool valid = true;
        f(i,0,size(b)-1)
            if(b[i] > b[i+1])
            {
                valid = false;
                break;
            }
        if(!valid)
            cout<<"NO";
        else
        {
            cout<<"YES";
        }
        cout<<NL;
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