#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

const int mod = 1e9+7;
int getmain(int n)
{
    int p = 1;
    while(n--)
    {
        p*=2;
        p%=mod;
    }
    return p;
}

int getb(int n)
{
    int p = n;
    int s = n;
    for(int i = 1; i < n; i++)
    {
        p = p*(n-i)/(i+1);
        p%=mod;
        s+=p;
        s%=mod;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n;cin>>n;
    for(int i = 0; i < n-1; i++)
    {
        int l,m;cin>>l>>m;
    }
    int m = getmain(n);
    // cout<<getb(n-1)<<"\n";
    int res = m-getb(n-1);
    cout<<res<<"\n";

    return 0;
}