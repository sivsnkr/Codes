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

const int mx = 1e6+77;
LL a[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int a1,b,c,d;
    cin>>a1>>b>>c>>d;
    for(int i = a1; i <= b; i++)
    {
        a[i+b]++;
        a[i+c+1]--;
    }
    for(int i = 1; i < mx; i++)
        a[i] += a[i-1];
    for(int i = 1; i < mx; i++)
        a[i] += a[i-1];

    LL ans = 0;
    f(i,c,d+1)
        ans+=(a[mx-1]-a[i]);
    cout<<ans<<endl;
    return 0;
}