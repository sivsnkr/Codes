#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int t;
    scanf("%d",&t);
    int j = 0;
    while(t > 0)
    {
        int n;
        scanf("%d",&n);
        vector<int> p(n),q(n);
        for(int i = 0; i < n; i++)
            scanf("%d",&p[i]);
        for(int i = 0; i < n; i++)
            scanf("%d",&q[i]);
        ll sum = 0,msum = 0;
        int index = 0;
        for(int i = 0; i < n; i++)
        {
            sum+=(p[i]-q[i]);
            msum = min(msum,sum);
        }
        printf("Case %d:",j+1);
        if(sum >= 0)
        {
            while(msum < 0 && index < n)
                msum-=p[index]-q[index++];
            printf(" Possible from station %d\n",index+1);
        }
        else
        {
            puts(" Not possible");
        }
        j++;
        
        t--;
    }

    return 0;
}