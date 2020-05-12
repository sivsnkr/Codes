#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

ll isposs(int tc)
{
    ll v = 24*ll(tc);
    v = sqrt(1+v)-1;
    v/=6;
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int tc;
        scanf("%d",&tc);
        int c = 0;
        while(tc > 0)
        {   
            ll v = isposs(tc);
            if(v > 0)
            {
                tc -= ((v*(6+(v-1)*3))/2-v);
                if(tc >= 0)
                    c++;
            }
            else
            {
                tc = 0;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}