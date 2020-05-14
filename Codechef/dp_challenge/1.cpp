#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        int n;
        scanf("%d",&n);
        vector<int> nums(n);
        for(int &it : nums)scanf("%d",&it);
        int c = 0;
        LL totalsub = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] >= nums[i-1])
            {
                c++;
                totalsub += c;
            }
            else
            {
                c = 0;
            }
        }
        totalsub+=nums.size();
        printf("%lld\n",totalsub);
        t--;
    }
    return 0;
}