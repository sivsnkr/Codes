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
int n,p,k;
vector<int> prices;

void solve()
{
    sort(all(prices));
    int sum1 = 0, sum2 = 0;
    int m = p;
    int i;
    vector<bool> inc(n,0);
    for(i = 0; i < n; i+=k)
    {
        if(prices[i] > m)
            break;
        if(i == 0)
            sum1+=1;
        else
            sum1+=k;
        m-=prices[i];
        inc[i] = 1;
    }
    if(i >= n && i - k < n-1)
    {
        int j = n-1;
        while(j > 0 && prices[j] > m && j > i-k)
            j--;
        if(prices[j] <= m && !inc[j])
            sum1+=(j-i+k);
    }
    m = p;
    inc.assign(n,0);
    for(i = k-1; i < n; i+=k)
    {
        if(prices[i] > m)
            break;
        sum2+=k;
        m-=prices[i];
        inc[i] = 1;
    }
    if(i >= n && i - k < n-1)
    {
        int j = n-1;
        while(j > 0 && prices[j] > m && j > i-k)
            j--;
        if(prices[j] <= m && !inc[j])
            sum2+=(j-i+k);
    }
    // cout<<sum1<<" "<<sum2<<endl;
    
    cout<<max(sum1,sum2)<<NL;
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // clock_t st = clock();
    // all the code goes here
    test{
        cin>>n>>p>>k;
        prices.assign(n,0);
        for(int &it : prices)cin>>it;
        solve();
    }
    // cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}