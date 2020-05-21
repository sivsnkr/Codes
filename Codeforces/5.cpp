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

bool isok(int i, int j, int c, int d)
{
    int sum = i+j;
    if(sum >= c && sum <= d)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    LL sum = 0;
    f(i,a,b+1)
    {
        f(j,b,c+1)
        {
            if(i+j > 5*100000)
                break;
            sum+=isok(i,j,c,d);
        }
    }
    printf("%lld\n",sum);
    return 0;
}