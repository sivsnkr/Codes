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
    int n,k,p;
    scanf("%d%d%d",&n,&k,&p);
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i].first);
        arr[i].second = i;
    }
    // vector<int> us(n);
    // for(int )
    sort(all(arr));

    vector<int>dp(n);
    dp[n-1] = n-1;

    vector<int> si(n);

    for(int i = 0; i < n; i++)
    {
        si[arr[i].second] = i;
    }

    for(int i = n-2; i >= 0; i--)
    {
        if(abs(arr[i].first-arr[i+1].first) <= k)
        {
            dp[i] = dp[i+1];
        }
        else
        {
            dp[i] = i;
        }
    }

    for(int i = 0; i < p; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        int mi = (arr[si[a]].first >= arr[si[b]].first)?b:a;
        if(dp[si[mi]] >= si[a+b-mi])
            puts("Yes");
        else
            puts("No");
        
    }
    return 0;
}