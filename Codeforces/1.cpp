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
    fh;
    test
    {
        int a,b,c;cin>>a>>b>>c;
        int n = a+b+c;
        int m = LLONG_MAX;
        f(A,1,a+b+1)
        {
            f(C,1,c+b+1)
            {
                int B = n-(A+C);
                if(C > 0 && A+B+C == n && !(B > b && A < a && C < c))
                {
                    m = min(m,max({A,B,C}));
                }
            }
        }
        cout<<m<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}