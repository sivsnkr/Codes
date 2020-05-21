#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; scanf("%d",&t); while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int n,s;
    cin>>n>>s;
    if(n>s/2)
    {
        puts("NO");
        return 0;
    }
    cout<<"YES"<<endl;
    f(i,0,n-1)
        cout<<1<<" ";
    cout<<s-(1*n-1)<<endl;
    cout<<s/2<<endl;
    
    return 0;
}