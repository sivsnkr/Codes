#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define testf int t; scanf("%d",&t); while(t--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define size(container) (int)container.size()
#define int long long int

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test
    {
        int n;
        cin>>n;
        int sum = 0;
        int i = 1;
        sum+=(n/2)*3+1;
        while(((int)1<<i) <= n)
        {
            sum+=(i+1);
            sum-=2;
            i++;
        }
        if(n%2 == 0)
        {
            sum-=1;
        }
        cout<<sum<<NL;
    }
    fflush(stdin);
    fflush(stdout);
    return 0;
}