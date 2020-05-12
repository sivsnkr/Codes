#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int mod(int a,int b)
{
    a%=b;
    if(a < 0)
        a+=b;
    return a;
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
        int n;
        scanf("%d",&n);
        vector<int> num(n);
        for(int &i : num)scanf("%d",&it);
        vector<int> newpos(n);
        for(int i = 0; i < n; i++)
        {
            newpos[i] = i+mod(num[i],)
        }
    }

    return 0;
}