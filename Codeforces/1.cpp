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
int n;
vector<int> b;
int MX = 4e5;

void solve()
{
    vector<int> dp(n);
    f(i,0,n)
        dp[i] = b[i];
    set<pair<int,int>> psab;
    f(i,0,n)
    {
        for(int l = bn(b[i]-i); l < psab.size(); l++)
        {
            pair<int,int> be = psab[l];
            int index = i-b[i]+be.first;
            if(index < i && index >= 0 && index == be.second)
                dp[i]= max(dp[i],dp[index]+b[i]);
            else if(index >= i)
            {
                break;
            }
        }
        psab.insert({b[i],i});
    }
    cout<<*max_element(all(dp))<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    clock_t st = clock();
    // all the code goes here
    cin>>n;
    b.assign(n,0);
    for(int &it : b)cin>>it;
    solve();
    cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}