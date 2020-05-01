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
    while(t--)
    {
        int n,a,b,c,d;
        scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
        int maxw = (a+b)*n;
        int minw = (a-b)*n;
        if((maxw <= (c+d)&&maxw>=(c-d))|| (minw <= (c+d) && minw >=(c-d))||(c+d >= minw && c+d <= maxw)||((c-d)>=minw&&c-d<=maxw))
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }

    return 0;
}