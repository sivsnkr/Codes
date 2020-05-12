#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int t;
    scanf("%d",&t);
    while(t > 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n == 1 || m == 1)
        {
            puts("YES");
        }
        else
        {
            if((m == 2 && n == 2))
            {
                puts("YES");
            }else
            {
                puts("NO");
            }
        }
        t--;
        
    }

    return 0;
}