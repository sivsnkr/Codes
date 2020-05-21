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
    test
    {
        int n;
        scanf("%d",&n);
        // int freq[200000+1] = {0};
        vector<int> ele(n);
        f(i,0,n)
        {
            int t;
            scanf("%d",&t);
            // freq[t]++;
            ele[i] = t;
        }
        LL sum = 0;
        int c = 0;
        // f(i,1,2*1e5+1)
        // {
        //     sum+=freq[i]/i;
        // }
        sort(all(ele));
        f(i,0,n)
        {
            c++;
            if(c >= ele[i])
            {
                sum++;
                c = 0;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}