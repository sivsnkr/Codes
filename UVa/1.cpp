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
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int x = float(a+b)/2;
        int y = a-x;
        if(x > 0 && y > 0)
            printf("%d %d\n",x,y);
        else
            puts("impossible");
    }
    return 0;
}