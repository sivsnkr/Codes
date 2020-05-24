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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test{
        int l,s;
        cin>>l>>s;
        vector<set<int>> dpsum(53,set<int>());
        vector<int> dp(s+1,0);
        f(i,0,53)
        {
            dpsum[i].insert(i);
        }
        f(i,1,l+1)
        {
            vector<set<int>> temp(53);
            f(j,1,53)
            {
                set<int>::iterator start = dpsum[j].begin();
                set<int>::iterator end = dpsum[j].end();
                for(auto m = start; m != end; m++)
                {
                    int it = *(m);
                    f(k,j+1,53)
                    {
                        cout<<i<<" "<<l<<endl;
                        // if(i == l-1)
                        //     dp[it+k]++;
                        // if(i == l)
                        //     dp[it]++;
                        temp[k].insert(it+k);
                    }
                }
            }
            dpsum = temp;
            cout<<i<<endl;
        }
        cout<<dp[s]<<endl;
    }
    return 0;
}