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
    int her[3],his[2];
    while(scanf("%d%d%d%d%d",&her[0],&her[1],&her[2],&his[0],&his[1]),her[0])
    {
        bool available[53];
        memset(available,1,sizeof(available));
        for(int i = 0; i < 3; i++)
        {
            available[her[i]] = false;
            if(i < 2)
                available[his[i]] = false;
            // printf("%d\n",her[i]);
        }

        sort(her,her+3);
        sort(his,his+2);
        int card = 53;
        if(his[0] > her[2])
            for(int i = 1; i < 53 && i < card; i++)
                if(available[i])
                    card = i;
        
        if(his[1] > her[2])
            for(int i = her[2]+1; i < 53&&i < card; i++)
                if(available[i])
                    card = i;
        if(his[0] > her[1])
            for(int i = her[1]+1; i < 53&&i < card; i++)
                if(available[i])
                    card = i;
        if(card == 53)
            puts("-1");
        else
        {
            printf("%d\n",card);
        }
        
    }

    return 0;
}