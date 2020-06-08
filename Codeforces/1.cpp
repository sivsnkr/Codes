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
vector<pair<int,int>> ar(510);
void solve()
{
    f(i,0,n)
    {
        f(j,0,n)
        {
            if(i > j)
            {
                if(ar[i].first < ar[j].second && ar[i].second != ar[j].second)
                swap(ar[i],ar[j]);
            }
            else if(i < j)
            {
                if(ar[i].first > ar[j].first && ar[i].second != ar[j].second)
                swap(ar[i],ar[j]);
            }
        }
    }
    f(i,0,n-1)
    {
        if(ar[i].first > ar[i+1].first)
        {
            cout<<"No"<<endl;
            return;
        }
        // cout<<ar[i].first<<" ";
    }
    // cout<<endl;
    cout<<"Yes"<<endl;
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test
    {
        cin>>n;
        f(i,0,n)
        {
            cin>>ar[i].first;
        }
        f(i,0,n)
            cin>>ar[i].second;
        solve();
    }
    fflush(stdin);
    fflush(stdout);
    return 0;
}