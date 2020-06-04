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

int h,c,ti;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test{
        cin>>h>>c>>ti;
        if(ti <= (h+c)/2)
        {
            cout<<2<<NL;
        }
        else
        {
            int k = (h-ti)/(2*ti-h-c);
            float v = abs(((float)(h*k+c*k+h)/(2*k+1))-ti);
            k++;
            float av = abs(((float)(h*k+c*k+h)/(2*k+1))-ti);
            (av >= v)?cout<<2*k-1<<NL:cout<<2*k+1<<NL;
        }
    }
    fflush(stdin);
    fflush(stdout);
    return 0;
}