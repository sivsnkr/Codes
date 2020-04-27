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
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int dif = (n-2)/2;
        if(dif%2 == 0)
        {
            cout<<"NO"<<nl;
            continue;
        }
        int start = 2;
        ll sum = 0;
        cout<<"YES"<<nl;
        for(int i = 0; i < n/2; i++)
        {
            cout<<start<<" ";
            sum+=start;
            start+=2;
        }
        start = 1;
        ll ano = 0;
        for(int i = 0; i < n/2-1; i++)
        {
            cout<<start<<" ";
            ano+=start;
            start+=2;
        }
        cout<<sum-ano<<nl;
    }

    return 0;
}