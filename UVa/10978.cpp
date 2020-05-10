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
    while(t > 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        set<int> maybefalse;
        for(int i = 1; i <= n; i++)
            maybefalse.insert(i);
        for(int i = 0; i < m; i++)
        {
            int s;
            scanf("%d",&s);
            vector<int> coins(2*s);
            for(int i = 0; i < 2*s; i++)
            {
                scanf("%d",&coins[i]);
            }
            char j;
            scanf("%c",&j);
            char a;
            scanf("%c",&a);
            // printf("sign %c\n",a);
            switch(a)
            {
                case '=':
                    for(int i : coins)
                        maybefalse.erase(i);
                    break;
                // default:
                //     for(int i : coins)
                //         maybefalse.insert(i);
            }
        }
        if(maybefalse.size() > 1)
            puts("0");
        else
        {
            printf("%d\n",*maybefalse.begin());
        }
        cout<<endl;
        
        t--;
    }
    return 0;
}